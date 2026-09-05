#include "osama.h"
int init(){
	printf("welcome to osamaOS\n");
}
int main(){
	while(1){
	printf("welcome to osamaOS system :)\n");
	printf("enter username:");
	char username[256];
	scanf("%255s", username);
	printf("\nenter password:");
	char password[256];
	scanf("%255s", password);
	printf("\n");
	FILE *users = fopen("users.txt","r");
	char line[256];
	int idu = -1;
	while(fgets(line,sizeof(line),users)){
		//awla na5th aluserat w nt7gg mnha
		char *uname = strtok(line,":");
		char *userid = strtok(NULL,":");
		if (uname == NULL || userid == NULL) {
    	    continue;
	    }
	
		int uid = atoi(userid);
		if(strcmp(username,uname) == 0){
			idu = uid;
		}else{
			
		}
	}
	if(idu == -1){
		printf("user dosn't exist");
		continue;
	}else{
		FILE *passws = fopen("passwords.txt","r");
		char passline[256];
		char thepass[256] = "";
		while(fgets(passline,sizeof(passline),passws)){
			char *passid = strtok(passline,":");
			char *passwrd= strtok(NULL,":");
			if (passid == NULL || passwrd == NULL) {
   			   continue;
            }
			int psid = atoi(passid);
			passwrd[strcspn(passwrd, "\n")] = '\0';
			if (strcmp(password,passwrd) == 0 && idu == psid){
				strcpy(thepass,password);
			}else{
				
			}
		}
		if(strcmp(thepass,"") != 0){
			init();
		}else{
			printf("incorrect password\n");
			continue;
		}
	}
}
}
