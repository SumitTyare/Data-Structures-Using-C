#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//User Defined Structure of Queue
struct Node
{
  int iData;
  struct Node *Next;
};


//Function Declaration OR Prototype
void DisplayQueue(struct Node *);
int CountElements(struct Node *);
void CreateNewNode(int, struct Node *);
void EnQueue(int, struct Node **);
void DeQueue(struct Node**);

