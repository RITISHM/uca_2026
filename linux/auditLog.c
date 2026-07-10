#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define BUFF_SIZE 1024
int main(int argc, char *argv[]) {

    int fd, openFlags;
    mode_t filePerms;
    ssize_t numRead;
    char buf[BUFF_SIZE];
	if(argc < 2){
   	 printf("Usage:\n");
    	printf("./auditlog --add \"message\"\n");
    	printf("./auditlog --view\n");
    	exit(-1);
	}
	if(strcmp(argv[1], "--add") == 0){
	openFlags = O_CREAT | O_WRONLY | O_APPEND;
	filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	fd = open("audit.log", openFlags, filePerms);
	if(fd == -1){
    		printf("Error opening file\n");
    		exit(-1);
		}
	write(fd, argv[2], strlen(argv[2]));
	write(fd, "\n", 1);
	close(fd);
	}
	else if(strcmp(argv[1], "--view") == 0){

    fd = open("audit.log", O_RDONLY);

    if(fd == -1){
        printf("Error opening file\n");
        exit(-1);
    }

int line = 1;
char ch;

printf("%d: ", line);
fflush(stdout);

while(read(fd, &ch, 1) > 0){

    write(STDOUT_FILENO, &ch, 1);

    if(ch == '\n'){
        if(read(fd, &ch, 1) > 0){
            line++;
            printf("%d: ", line);
            fflush(stdout);
            write(STDOUT_FILENO, &ch, 1);
        }
        else{
            break;
        }
    }
}

close(fd);
}
}

