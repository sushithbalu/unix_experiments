#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

#define MAX 100

char *path();
int listdir(char *arg[], char *path);

int main(int argc, char *argv[])
{
	int c, i, j;
	char *path;
	char *ap[MAX];
	
	if(argc < 2){
		c = listdir(ap, ".");
		for(i = 0; i < c; i++){
			printf("%s ", ap[i]);
		}
		printf("\n");	
	}else{
		for(j = 1; j < argc; j++){
			c = listdir(ap, argv[j]);
			for(i = 0; i < c; i++){
				printf("%s ", ap[i]);
			}
			printf("\n");
		}	
	}
	return 0;
}

int listdir(char *arg[], char *path)
{
	int i = 0;
	DIR *dir;
	struct dirent *dirp;
	struct stat buf;
	
	if((dir = opendir(path)) != NULL) {
		while((dirp = readdir(dir)) != NULL){
			arg[i++] =  dirp->d_name;
		}
		arg[i] = NULL;
	}
	closedir(dir);
	return i;
}

