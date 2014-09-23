/*usage: ./a.out  <existing file>  <new or existing file>*/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
int main(int argc, char **argv)
{
	int fdr,  fdw;
	size_t nbr, nbw;
	char *buf;

	fdr = open(argv[1], O_RDONLY);
	assert(fdr > 0);
	fdw = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644);
	assert(fdw > 0);
	while((nbr = read(fdr, buf, sizeof(buf))) > 0){
		write(1, buf, nbr);
		nbw = write(fdw, buf, nbr);
		if(nbw != nbr){
			exit(1);
		}
	}
	if(nbr == -1){
		fprintf(stderr, "write error");
		exit(1);
	}
	return 0;
}
