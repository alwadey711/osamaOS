#include "osama.h"

int main(){
	while(1)
	printf("welcome to osamaOS system :)\n");
	printf("enter username:");
	char username[256];
	scanf("%255s", username);
	printf("\nenter password:");
	char password[256];
	scanf("%255s", password);
	printf("\n");
	FILE users = fopen("users.txt","r");
	char uline[256];
	while(fgets(uline, sizeof(uline), users) != NULL){
		char *userl = strtok(uline,":");
		int *userid = strtok(NULL,":");
		userid = atoi(userid);
		if (strcmp(username,userl) == 0){
			int useruid = -1;
			userid = useruid;
		}if(useruid == -1){
			printf("this user dosn't exist\n");
			continue;
		}else{
			char pline[256];
			FILE *passfile = fopen("passwords.txt","r");
			while (fgets(pline, sizeof(pline), passfile) != NULL){
				char *passw[256];
				if()
			}
		}
		
	}
}
