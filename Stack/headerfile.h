#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//User Defined Structure of Stack
struct Node
{
  int iData;
  struct Node *Next;
};


//Function Declaration OR Prototype
void DisplayStack(struct Node *);
int CountElements(struct Node *);
void CreateNewNode(int, struct Node *);
void Push(int, struct Node **);
void Pop(struct Node**);

