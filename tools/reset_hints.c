#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#define HINTINJECT 0xFE0B
#define HINTRESET 0xFE0C

struct hint_entry {
	unsigned long long offset;
	unsigned long long size;
	int placement;
};
int main() {
	char *name = "/dev/tiercontrol";
	int fd, ret;
	struct hint_entry entry = {
		.offset = 9000,
		.size = 512,
		.placement = 1
	};

	printf("Open file\n");
	fd = open(name, O_RDONLY);
	printf("ioctl\n");
	ret = ioctl(fd, HINTRESET, &entry);
	printf("ret: %d\n", ret);
	return 0;
}
