#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
int main(int argc , char *argv[]){
char *path;
if (argc == 1){
path = ".";
}else{
path = argv[1];
}
DIR *dirlocat = opendir(path);
struct dirent *theonece;
if(dirlocat == NULL){
perror("wshfeeh?");
return 1;
}
while((theonece = readdir(dirlocat)) != NULL){
printf("%s\n", theonece->d_name);
}
closedir(dirlocat);
return 0;
}
