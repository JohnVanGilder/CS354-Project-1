#include <stdio.h>
#include <stdlib.h>
/*Assignment 1: John Van Gilder                                                                                                                                                      
  This program takes in a file full of ascii integers and prints it to the console.                                                                                                  
                                                                                                                                                                                     
*/


/* Main takes in a file and returns nothing meaningful.                                                                                                                              
 It prints the file's contents to the console, provided the file                                                                                                                     
 contains ascii integers.*/
int main(int argc, char *argv[]){
  
  #define NUMINTS 8 
  FILE *fp;
  int check;
  int fileint;
  /*Checks to see if the user provided the correct
   number of arguments to the strcat program.*/
  
  if(argc != 2){
    fprintf(stderr, "Usage: strcat <file>\n");
    exit(1);
  }
  
  fp = fopen(argv[1], "r");

  /*Checks to see if the user provided a valid 
   filename to be read*/
  
  if (fp == NULL){
    fprintf(stderr, "Invalid file\n");
    exit(1);
  }
  check = 1;
  while(check == 1){
  check = fscanf(fp, "%d", &fileint);
  if(check == 1){
  printf("%d\n", fileint);
  }
  }
  /*Checks to make sure the program printed the correct
   number of ints*/
  

 
  /*Closes the file*/
  check = fclose(fp);
  
  /*checks to make sure the file was closed correctly */
  if(check != 0){
    fprintf(stderr, "File close failure");
    exit(1);
  }

  return 0; 
    }
