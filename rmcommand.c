#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<assert.h>

int main(int argc, char **argv)
{
	int i;
	char *ptr;

	if(argc < 2){
		fprintf(stderr, 
		"error:\nusage: ./a.out <file>; ./a.out -r <folder>\n");
		exit(1);
	}
	if(strcmp(argv[1], "-r") == 0){
		i = 2;
		while(i < argc){
			if(rmdir(argv[i++]) == 0){
				printf("the folder has been removed\n");
			} else{
				perror("rmdir");
				exit(1);
			}
		}
	} else {
		i = 1;
		while(i < argc){
			if(unlink(argv[i++]) == 0){
				printf("the file has been removed\n");
			} else {
				perror("rmfile");
				exit(1);
			}
		}
	}
	return 0;
}
