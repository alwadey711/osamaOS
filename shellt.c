#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include <dirent.h>

void wshfeeh(char *path){
DIR *dirlocat = opendir(path);
struct dirent *theonece;
if(dirlocat == NULL){
printf("you cant reach thats file stupid B****");
return;
}
while((theonece = readdir(dirlocat)) != NULL){
printf("%s\n", theonece->d_name);
}
}

void sinput(char the_input[]){
fgets(the_input,PATH_MAX,stdin);
the_input[strcspn(the_input, "\n")] = 0;
}
void wdni(char *path){
	if(chdir(path) == -1){
		perror("wdni");
	}
}
int main(){
printf("welcome to __ script\n");
while(1){
char the_user_path[PATH_MAX];
char the_user_command[PATH_MAX];
char *the_user_command_array[64];
int the_user_command_counter = 0;
getcwd(the_user_path,sizeof(the_user_path));
printf("%s __",the_user_path);
sinput(the_user_command);

char *the_user_command_tok = strtok(the_user_command," \t");
while(the_user_command_tok != NULL){
the_user_command_array[the_user_command_counter] = the_user_command_tok;
the_user_command_counter++;
the_user_command_tok = strtok(NULL," \t");
}

if(the_user_command_counter == 0){
continue;
}

printf("\n");
if(strcmp(the_user_command_array[0],"exit") == 0){
exit(0);
}else if(strcmp(the_user_command_array[0],"wshfeeh?") == 0){
if(the_user_command_counter == 1){
wshfeeh(".");
}else if(the_user_command_counter == 2){
if(the_user_command_counter == 2){
wdni(the_user_command_array[1]);
}else{
printf("wdni needs one path\n");
}
}else{
printf("more arguments mf\n");
}
}else if(strcmp(the_user_command_array[0],"anaween?") == 0){
printf("%s\n", the_user_path);
}else if(strcmp(the_user_command_array[0],"wdni") == 0){
	wdni(the_user_command_array[1]);
}else{
printf("no command called %s\n",the_user_command_array[0]);
}
}
}
