#include<sys/types.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	int pid, state;

	pid = atoi(argv[1]);
	if(argc < 2){
		printf("usage: ./a.out  pid\n");
		exit(1);
	}
	state = kill(pid, SIGKILL);
	if(state == -1){
		perror("error in kill");
		exit(1);
	}
	
	return 0;
}
