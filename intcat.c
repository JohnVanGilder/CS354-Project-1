#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/*Assignment 1: John Van Gilder
  This program takes in a file full of binary representations of integers and prints it to the console.

 */


/* Main takes in a file and returns nothing meaningful.
 It prints the file's contents (converted to ascii) to the console, provided the file
 contains binary representations integers.*/
int main(int argc, char *argv[]){
  int fp;
  int buf;
  int file;
  
    
  /*Checks to see if the user provided the correct
   number of arguments to the intcat program.*/
  
  if(argc != 2){
    fprintf(stderr, "Usage: strcat <file>\n");
    exit(1);
  }
 
  fp = open(argv[1], O_RDONLY);
  
  /*Makes sure the file was opened correctly*/
  if(fp == -1){
    fprintf(stderr, "File open failure\n");
    exit(1);
  }

  /**needs to be initialized before the loop**/  
  file = 1;

  /*Runs until the end of the file*/
  while(file != 0){

    /*Checks to make sure
     the file was read correctly*/
    if(file == -1){
      fprintf(stderr, "File read failure\n");
      exit(1);
      }

    file = read(fp, &buf, sizeof(int));
    
    if(file !=0){
    printf("%d\n", buf);
    } 
  }
 
  if(close(fp) != 0){
    fprintf(stderr, "File close error");
    exit(1);
  }
  return 0; 
    }
