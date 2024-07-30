#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void printHelp(){
    printf("Please type command for init app\n");
}

int main(int argc, char *argv[]){
    if (argv[1]){
        if(strcmp("--help", argv[1]) == 0){
            printf("%s\n", helpMessage);
        } else {
            if(argv[1]){
                sprintf(command, "sudo nice -n -18 /usr/bin/%s", argv[1]);
                sprintf(desktopEntryName, "./%s.desktop", argv[1]);
                system(pidCommand);
                sprintf(desktopEntry, "echo '[Desktop Entry]\nName=%s(BigShot)\nComment=Entry for gaming mode\nExec=%s\nTerminal=true\nType=Application' > %s.desktop", argv[1], command, argv[1]);
                system(desktopEntry);
                system("sudo desktop-file-install *.desktop");
                system(command);
            } else {
                printf("Please type command for init app\n");
                exit(1);
            }
        }
    } else {
        printHelp();
    }
}
