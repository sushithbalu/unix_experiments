#include<stdlib.h>
#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

#define MAX 100

int listdir(char *arg[], char *path);
void rlist(char *arg[]);
int main(int argc, char *argv[])
{
	int c, j;
	char *ap[MAX];
	
	if(argc < 2){
		c = listdir(ap, ".");
		printf("\ntotal:%d\n",c);
	}else{
		if(strcmp(argv[1], "-R") == 0){
			rlist(ap);
		}else{
			for(j = 1; j < argc; j++){
				c = listdir(ap, argv[j]);
				printf("\ntotal:%d\n",c);
			}	
		}
	}
	return 0;
}

int listdir(char *arg[], char *path)
{
	int i = 0, j;
	DIR *dir;
	char *p;
	struct dirent *dirp;
	
	if((dir = opendir(path)) != NULL) {
		while((dirp = readdir(dir)) != NULL){
			arg[i++] =  dirp->d_name;
		}
		arg[i] = NULL;
	}
	for(j = 0; j < i; j++){
		printf("%s ", arg[j]);
	}
//	closedir(dir);
	return i;
}

void rlist(char *arg[])
{
	int c, i = 0,d;
	struct stat t;
	char m[100];
	char *ptr;
	c = listdir(arg, ".");
	printf("\n");
	while(i < (c)){
		if ((stat(arg[i],&t) == 0)&&(strcmp(arg[i], "..") != 0)&&(strcmp(arg[i],"."))) {
			if (t.st_mode & S_IFDIR) {
				getcwd(m, sizeof(m));
				strcat(m, "/");
				ptr = strdup(m);
			//	printf("\n%s\n", ptr);	
				strcat(ptr, arg[i]);
			//	printf("\n%s\n", ptr);	
				chdir(ptr);
				d = listdir(arg, ptr);
				printf("\npath:%s\ntotal:%d\n\n", ptr, d);
				chdir("..");
			}
			
                }
		i++;
	}
}

