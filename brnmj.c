#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include <dirent.h>
int main(int argc, char *argv[]){
if(argc == 1){
		printf("brnmj: missing program\n");
	}else{
		pid_t pid = fork();
		if (pid == 0){
		execvp(argv[1],&argv[1]);
		perror("execvp");
		exit(1);
		}else{
		wait(NULL);
		}
	}
}

