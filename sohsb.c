#include "osama.h"
int main(int argc, char *argv[]){
	if(argc != 3){
		printf("usage : sohsb username password");
	}else{
		FILE *file = fopen("users.txt","r");
		FILE *filew = fopen("users.txt","a");
		FILE *passfile = fopen("passwords.txt","a");
		int last_uid = -1;
		char line[256];
		while (fgets(line, sizeof(line), file) != NULL) {
		
		    char *part = strtok(line, ":");
		    int i = 0;
		
		    while (part != NULL) {
		
		        if (i == 1) {
		            last_uid = atoi(part);
		        }
		
		        part = strtok(NULL, ":");
		        i++;
		    }
		}
		if (file == NULL) {
	        printf("Error opening the file!\n");
		    return 1;
	    }else{
	    	int li = ++last_uid;
	    	fprintf(filew,"%s:%d\n",argv[1],li);
	    	fprintf(passfile,"%d:%s",li,argv[2]);
	    }
	}
}
