#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//User Defined Structure for Linked List
struct Node
{
  int iData;
  struct Node *Next;
};


//Function Declaratin OR Function Prototype
void DisplayLinkedList(struct Node *);
void CreateNewNode(int, struct Node *);
void InsertAtFirst(int, struct Node **);
void InsertAtLast(int, struct Node **);
void InsertAtPosition(int, int, struct Node **);
int CountNodes(struct Node *);
void DeleteFirst(struct Node **);
void DeleteLast(struct Node **);
void DeleteFromPosition(int, struct Node **);
