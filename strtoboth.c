#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
/*Assignment 1: John Van Gilder
 This program takes in a file of ascii integers and outputs a binary representation of the integers, as well as outputs a file of those same ascii integers with a slight modification. Wherever there are negative integers, this program inserts a space in between the negative sign and the integer. It also adds semicolons at the end of each line.*/

/*Maintakes in a file of ascii integers and outputs a binary representation of the integers, as well as outputs a file of those same ascii integers with a slight modificati\
on. Wherever there are negative integers, this program inserts a space in between the negative sign and the integer. It also adds semicolons at the end of each line. It takes in 3 file names: it reads from the first, and outputs to the others. It doesn't return anything meaningful. */
int main(int argc, char *argv[]){

  FILE *fp;
  int fileint;
  int check;
  int check2;
  char *outfile1;
  FILE *outfile2;
  int outfile1i;
  /*Check to see if the user input the correct number of arguments*/
  if(argc != 4){
    fprintf(stderr, "Usage: strtoboth <infile> <outfile1> <outfile2>\n");
    exit(1);
  }
  
  fp = fopen(argv[1], "r");

  /*Checks to make sure the file was opened correctly*/
  if (fp == NULL){
    fprintf(stderr, "Invalid file\n");
    exit(1);
  }
  outfile1 = argv[2];
  
  outfile1i = open(outfile1, O_WRONLY | O_CREAT);

  /*checks to make sure the first output file was opened correctly*/
  if(outfile1i == -1){
    fprintf(stderr, "Outfile 1 open error\n");
      exit(1);
  }
  
  outfile2 = fopen(argv[3], "w");
  
  /*check to make sure outfile2 was created correctly*/
  if(outfile2 == NULL){
    printf("%s", argv[3]);
    fprintf(stderr, "Outfile open error\n");
    exit(1);
  }
  check2 = 1;
  check = 0;
  /*This while loop goes through the input file, 
   outputs each int to the first output file as a binary, then
  modifies each int and outputs it to the second output file 
  as an ascii. Each time it writes, it checks to make sure the 
  write was successful before proceeding.*/
  while(check2 == 1){
    check2 = fscanf(fp, "%d", &fileint);
    if(check2 == 1){
      check = write(outfile1i, &fileint, sizeof(int));

      if(check == -1){
	fprintf(stderr, "Outfile 1 write error");
	exit(1);
      } 
    if(fileint < 0){
      fileint = fileint * -1;
      check = fprintf(outfile2, "- %d;\n", fileint);
      if(check < 0){
	fprintf(stderr, "Outfile 2 write error");
	exit(1);
      }
    }
      else{
	check = fprintf(outfile2, "%d;\n", fileint);
	if(check < 0){
	  fprintf(stderr,"Outfile 2 write error");
	  exit(1);
	}
      }
    }
  }
  /*Closes and confirms closure of each file.*/
    if(close(outfile1i) == -1){
      fprintf(stderr, "Outfile 1 close error");
      exit(1);
    }
    if(fclose(fp) != 0){
      fprintf(stderr, "File close error");
      exit(1);
    }
    if (fclose(outfile2)){
      fprintf(stderr, "File close error");
      exit(1);
    }
return 0;
  
}
