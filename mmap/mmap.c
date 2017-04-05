#include <sys/types.h>
#include <sys/mman.h>
#include <err.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int parpid = getpid(), childpid;
	int fd = -1;
	char *zero;
	
	if ((fd = open("tmp", O_RDWR)) == -1) {
		err(1, "open");
	}
	
	zero = (char *)mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd,0);

	if (zero == MAP_FAILED)
		errx(1, "either mmap");

	lseek(fd, 100, SEEK_CUR);	
	strcpy(zero, "Nothing in the world can change your mind.");
	printf("content:%s\n", zero);
        munmap(zero, 4096);
        close(fd);
        return EXIT_SUCCESS;
}

