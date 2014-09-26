#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>

#define SIZE  1024

int main(int argc, char *argv[])
{
	int fdr, fdw, pid, i, j = 1;
	char buf[SIZE];	
	char *arg[SIZE];
	char *temp[SIZE];

	fdr = read(0, buf, sizeof(buf));
	buf[fdr] = '\0';
	temp[0] = strtok(buf, " 	\n\t");
	for(i = 1; i <= argc; i++){
		temp[i] = strtok(NULL, " 	\n\t");
	}
  
	for(i = 0; i< argc; i++){
		arg[i] = argv[i+1];
	} 
	for(i = 0; i< argc; i++){
		printf("%s", arg[i]);
	} 

	if(argc < 2){
		fdw = write(1, buf, fdr);
		exit(1);
	} else { 
		pid = fork();
		if(pid == -1){
			perror("error in fork");
			exit(1);
		}else if(pid == 0){
			execvp(arg[0], arg, NULL);
			perror("error in execvp");
			exit(1);
			
		} else {
			wait(&fdr);
		}
	}
	return 0;
}
