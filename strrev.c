#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
/*Assignment 1: John Van Gilder                                                                                                                                                     This program takes in a file full of ascii integers and prints it to the console in reverse order. 
*/

/* Main takes in a file and returns nothing meaningful.                                                                   
 It prints the file's contents to the console, in reverse order, provided the file
 contains ascii integers.*/

struct node *push(struct node* oldTOS, int valueToPush);
int pop(struct node** pstackptr);

/*Set up the nodes for a linked list*/
typedef struct node{                                                                                                                                                                
  int value;                                                                                                                                                                       
  struct node *next;                                                                                                                                                               
}Node;

int main(int argc, char *argv[]){
  FILE* fp;
  int check;
  int fileint;
  Node *stackptr;
  
  stackptr = NULL;
  
  /*check to make sure the user provided the correct number
   of arguments*/
  if(argc != 3){
    fprintf(stderr, "Usage: strrev <InputFile> <OutputFile>");
    exit(1);
  }
  fp = fopen(argv[1], "r");

  /*Makes sure the file was opened correctly*/
  if(fp == NULL){
    fprintf(stderr, "File open failure\n");
    exit(1);
  }

  /*check needs to be initialized before the loop*/
  check = 1;
  while(check == 1){
  check = fscanf(fp, "%d", &fileint);
    if(check == 1){
      stackptr = push(stackptr, fileint);
    }
  }
    
  if(fclose(fp) != 0){
    fprintf(stderr, "File close error");
    exit(1);
  }
  FILE * fileaddrO;
  fileaddrO = fopen(argv[2], "w");
  if(fileaddrO == NULL){
    fprintf(stderr, "Outfile open error\n");
    exit(1);
  }
  
  while(stackptr != NULL){
     fprintf(fileaddrO, "%d\n", pop(&stackptr)); 
  }
  if(fclose(fileaddrO) != 0){
    fprintf(stderr, "File close error");
  }
  return 0;
	 }
/*This is your standard push function. It takes in the old head of the linked list and the value to add to the stack, and creates a new node and inserts it into the linked list and stack. it returns a pointer to the new head of the stack.*/
Node *push(Node* oldTOS, int valueToPush){
  
  Node *newNodep;
  newNodep = malloc(sizeof(Node));

  if(newNodep == NULL){
    fprintf(stderr, "Memory Allocation Error\n");
    exit(1);
  }
  
    
    newNodep->value = valueToPush;
    newNodep->next = oldTOS;
    oldTOS = newNodep;
 
  
  return newNodep;
}
/*This is the standard pop function. It removes a node from the linked list, and returns its value. Stacks are FIFO.*/
int pop(Node** pstackptr){
  int poppedInt;
  Node* tempNode;
  if(*pstackptr != NULL){
    tempNode = *pstackptr;
    poppedInt = tempNode->value;
    *pstackptr = tempNode->next;
  }
  else {
    fprintf(stderr, "Pop called on Empty Stack\n");
    exit(1);
  }
  free(tempNode);

  return poppedInt;


}
