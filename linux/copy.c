#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 1024
int main (int argc, char *argv[]){
  if (argc != 3) {
    printf("Not enough args");
    exit(-1);
  }

  int inputFd, outputFd, openFlag;
  
  mode_t filePerms;

  ssize_t numRead;

  char buf[BUF_SIZE];
  
  inputFd = open(argv[1], O_RDONLY );

  if (inputFd == -1){
    printf("Error opening file %s\n", argv[1]);
  }

  openFlag = O_CREAT | O_WRONLY | O_TRUNC;
  filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

  outputFd = open (argv[2], openFlag, filePerms);

  if (outputFd == -1){
    printf("Error opening file %s\n", argv[2]);
    exit(-1);
  }
  
  while((numRead = read(inputFd, buf, BUF_SIZE) )>0){
    if (write(outputFd, buf, numRead) != numRead){
      printf("Error while copying\n");
      exit(-1);
    }
  }

  close(inputFd);
  close(outputFd);

  return 0;
}
