#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int i = 1, status;

	if(argc < 2){
//		perror("error");
		exit(1);
	}
	while(i < argc){
		status = mkdir(argv[i], S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		if(status == -1){
			perror("mkdir");
			exit(EXIT_FAILURE);
		}
	}
	return 0;	
}
