#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
/*Assignment 1: John Van Gilder                                                                                                                                                      
  This program takes in a file full of binary representations of integers and prints it, in ascii form to the console in reverse order.                                                                                                  
                                                                                                                                                                                     
*/


/* Main takes in a file and returns nothing meaningful.                                                                                                                              
 It prints the file's contents to the console, in ascii and in reverse order, provided the file                                                                                                                     
 contains ascii integers.*/
int main (int argc, char *argv[]){

  char *outfile;
  
  int fileaddr;
  int fileaddrO;
  int filesize;
  int check;
  int *p;
  int numInts;
  struct stat buffer;

  /*Checks to see if the user provided the correct
    number of arguments to the strcat program.*/
    if(argc != 3){
    fprintf(stderr, "Usage: intrev <fileIn fileOut>\n");
    exit(1);
  }
  fileaddr = open(argv[1], O_RDONLY);
  
  /*Checks to make sure the file was opened 
   without any errors.*/

  if(fileaddr == -1){
    fprintf(stderr, "File open failure");
    exit(1);
      }
  
  outfile = argv[2];
  fileaddrO = open(outfile, O_CREAT | O_WRONLY);
  
  /*Same check as above, for second file (output)*/
  if(fileaddrO == -1){
    fprintf(stderr, "Outfile open failure");
    exit(1);
  }
  check = fstat(fileaddr, &buffer);
  
  /*Checks to make sure the file was
   sized without any errors.*/
  if(check != 0){
    fprintf(stderr, "File sizing error");
    exit(1);
  }
  filesize =  buffer.st_size;
  
  p = malloc(filesize);

  if(p ==NULL){
    fprintf(stderr, "Memory allocation error");
    exit(1);
  }

  read(fileaddr, p, filesize);
  int i;
  numInts = filesize/sizeof(int);
  for(i = numInts-1; i >= 0; i--){
   check =  write(fileaddrO, (p+i), sizeof(int));
   if(check == -1){
     fprintf(stderr, "File write error");
     exit(1);
   }
  }
   /*Check to make sure the file closed correctly*/
   if(close(fileaddrO) == -1){
     fprintf(stderr, "File close error");
     exit(1);
   }
  
  return 0;

  }
