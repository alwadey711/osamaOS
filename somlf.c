#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[]){
	if (argc < 2 || argc > 3){
		perror("somlf");
	}else if(argc == 3){
		open(argv[1],O_CREAT, strtol(argv[2],NULL,8));
	}
	else{
		open(argv[1], O_CREAT, 0644);
		return 0;
	}
}
