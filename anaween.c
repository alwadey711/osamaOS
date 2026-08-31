#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(){
	char path[PATH_MAX];
	getcwd(path,sizeof(path));
	printf("%s\n",path);
	return 0;
}
