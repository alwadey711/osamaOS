#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
int main(){
while(1){
printf("welcome to osama system/n");
printf("the username:");
char username[21];
scanf("%20s",username);
printf("\n");
printf("enter your password:");
char password[21];
scanf("%20s",password);
printf("\n");
if (strcmp(username,"osamasu") != 0 || strcmp(password,"1029384756") != 0){
printf("incorrect password,username\n");
}else{
printf("welcome to osama's init\n");
sleep(2);
pid_t bsh = fork();
if (bsh == 0){
execl("/bin/sh","sh",NULL);
}else{
wait(NULL);
}
}
}
return 0;
}
