#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
int main(int argc,char **argv)
{
	int i;
	struct stat t;

	if (argc < 2) {
		printf("usage : %s <file>\n",argv[0]);
		exit(1);
	}
	
	for(i = 1; i < argc; i++){
		if ((stat(argv[i],&t)) == -1) {
			perror("error in stat");
			exit(1);
		}
 		printf(" filename:\t\t\t %s\n", argv[i]);
		printf(" device:\t\t\t %lld\n", (long long int) t.st_dev);
		printf(" inode:\t\t\t\t %ld\n", (long int)t.st_ino);
		printf(" protection:\t\t\t %o\n", (unsigned int)t.st_mode);	
		printf(" number of hard links:\t\t %d\n", (int)t.st_nlink);
		printf(" user ID of owner:\t\t %d\n", (int) t.st_uid);
		printf(" group ID of owner:\t\t %d\n", (int) t.st_gid);
		printf(" device type (if inode device):\t %lld\n", 
			(long long int)t.st_rdev);
		printf(" total size, in bytes:\t\t %ld\n", 
			(long int)t.st_size);
		printf(" blocksize for filesystem I/O:\t %ld\n", 
			(long int)t.st_blksize);
		printf(" number of blocks allocated:\t %ld\n", 
			(long int)t.st_blocks);
		printf(" time of last access:\t\t %ld : %s", 
			(long int)t.st_atime, ctime(&t.st_atime));
		printf(" time of last modification:\t %ld : %s", 
			(long int)t.st_mtime, ctime(&t.st_mtime));
		printf(" time of last change:\t\t %ld : %s", 
			(long int)t.st_ctime, ctime(&t.st_ctime));
	}
	return 0;
}
