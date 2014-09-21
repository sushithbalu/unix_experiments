
/*usage: ./a.out  <source file>  <destination file> */

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int fdw, fdr;
	ssize_t nbr, nbw;
	char *buf;
	fdr = open(argv[1], O_RDONLY);
	assert(fdr >= 0);
	fdw = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644);
	assert(fdw >= 0);
	while((nbr = read(fdr, buf, strlen(buf)))> 0){
		nbw = write(fdw, buf, nbr);
		if(nbr != nbw){
			fprintf(stderr, "write error\n");
			exit(1);
		}
	}
	if(nbr == -1){ /*error value*/
		fprintf(stderr, "read error\n");
		exit(1);
	}
	return 0;
}
