#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include <dirent.h>

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

char *history[100];
int history_count = 0;

while(1){
char the_user_path[PATH_MAX];
char the_user_command[PATH_MAX];
char *the_user_command_array[64];
int the_user_command_counter = 0;
getcwd(the_user_path,sizeof(the_user_path));
printf("%s __",the_user_path);
sinput(the_user_command);

if(strlen(the_user_command) > 0 && history_count < 100){
	history[history_count] = strdup(the_user_command);
	history_count++;
}

char *the_user_command_tok = strtok(the_user_command," \t");
while(the_user_command_tok != NULL && the_user_command_counter < 63){
the_user_command_array[the_user_command_counter] = the_user_command_tok;
the_user_command_counter++;
the_user_command_tok = strtok(NULL," \t");
}
the_user_command_array[the_user_command_counter] = NULL;
if(the_user_command_counter == 0){
continue;
}

printf("\n");
if(strcmp(the_user_command_array[0],"exit") == 0){
exit(0);
}else if(strcmp(the_user_command_array[0],"wshfeeh?") == 0){
pid_t pid = fork();
if(pid == 0){
execvp("./wshfeeh",the_user_command_array);
perror("execvp");
exit(1);
}else{
wait(NULL);
}
}else if(strcmp(the_user_command_array[0],"anaween?") == 0){
pid_t pid = fork();
if (pid == 0){
	execlp("./anaween","anaween",NULL);
	perror("execlp");
	exit(1);
}else{
wait(NULL);
}
}else if(strcmp(the_user_command_array[0],"wdni") == 0){
	if(the_user_command_array[1] == NULL){
		printf("wdni: missing path\n");
	}else{
		wdni(the_user_command_array[1]);
	}
}else if(strcmp(the_user_command_array[0],"sheel") == 0){
	pid_t pid = fork();
	if(pid == 0){
		execlp("./sheel","sheel",NULL);
		perror("execlp");
		exit(1);
	}else{
		wait(NULL);
	}
}else if(strcmp(the_user_command_array[0],"somlf") == 0){
	pid_t pid = fork();
	if (pid == 0){
		execvp("./somlf",the_user_command_array);
		perror("execvp");
		exit(1);
	}else{
		wait(NULL);
	}
}else if(strcmp(the_user_command_array[0],"sojld") == 0){
pid_t pid = fork();
if (pid == 0){
execvp("./sojld",the_user_command_array);
perror("execvp");
exit(1);
}else{
wait(NULL);
}
}else if (strcmp(the_user_command_array[0],"shl") == 0){
	pid_t pid = fork();
	if (pid == 0){
	execvp("./shl",the_user_command_array);
	perror("execvp");
	exit(1);
	}else{
	wait(NULL);
	}
}else if(strcmp(the_user_command_array[0],"brnmj") == 0){
	pid_t pid = fork();
	if (pid == 0){
	execvp("./brnmj",the_user_command_array);
	perror("execvp");
	exit(1);
	}else{
	wait(NULL);
	}
}else if(strcmp(the_user_command_array[0],"history") == 0){
	for(int i = 0; i < history_count; i++){
		printf("%d %s\n", i, history[i]);
}
}else if(strcmp(the_user_command_array[0],"hml") == 0){
	pid_t pid = fork();
	if (pid == 0){
	execvp("./hml",the_user_command_array);
	perror("hml");
	exit(1);
}else{
	wait(NULL);
}
}else if(strcmp(the_user_command_array[0],"sohsb") == 0){
	pid_t pid = fork();
	if (pid == 0){
	execvp("./sohsb",the_user_command_array);
	perror("sohsb");
	exit(1);
}else{
	wait(NULL);
}
}else{
printf("no command called %s\n",the_user_command_array[0]);
}
}
}
