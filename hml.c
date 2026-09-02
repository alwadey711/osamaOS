#include "osama.h"

int check(char *name, char *found_path){
    char paths[PATH_MAX];
    char full_path[PATH_MAX];

    strcpy(paths, getenv("PATH"));

    char *dir = strtok(paths, ":");

    while(dir != NULL){
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, name);

        if(access(full_path, X_OK) == 0){
            strcpy(found_path, dir);
            return 0;
        }

        dir = strtok(NULL, ":");
    }

    return -1;
}

int main(int argc, char *argv[]){
    char path[PATH_MAX];
    char realpath[PATH_MAX];
    char *pakman;

    if(check("dnf", path) == 0){
        snprintf(realpath,sizeof(realpath),"%s/dnf",path);
        pakman = "dnf";
    }else if(check("apt", path) == 0){
        snprintf(realpath,sizeof(realpath),"%s/apt",path);
        pakman = "apt";
    }else if(check("pacman", path) == 0){
        snprintf(realpath,sizeof(realpath),"%s/pacman",path);
        pakman = "pacman";
    }else{
        printf("unkown pakman to now\n");
        return 1;
    }

    if(argc == 1){
        printf("wtf do u want?!\n");
    }else{
        printf("calling your pakman...\n");
        pid_t pid = fork();

        if(pid == 0){

            if(strcmp(pakman, "dnf") == 0){
                char *args[] = {"dnf", "install", argv[1], NULL};
                execvp(realpath, args);

            }else if(strcmp(pakman, "apt") == 0){
                char *args[] = {"apt", "install", argv[1], NULL};
                execvp(realpath, args);

            }else if(strcmp(pakman, "pacman") == 0){
                char *args[] = {"pacman", "-S", argv[1], NULL};
                execvp(realpath, args);
            }

        }else{
            wait(NULL);
        }
    }
}
