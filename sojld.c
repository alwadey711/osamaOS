#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	if (argc < 2 || argc > 3){
		perror("sojld");
	}else{
	if (argc == 3){
		mkdir(argv[1],strtol(argv[2],NULL,8));
	}else{
		mkdir(argv[1],0755);
		}
		
	}
}

