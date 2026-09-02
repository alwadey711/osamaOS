#include <unistd.h>
#include <stdio.h>
int main(int argc,char *argv[]){
	if(argc == 2){
		if (unlink(argv[1]) == -1){
			perror("shl");
		}
	}else{
		perror("shl");
	}
}
