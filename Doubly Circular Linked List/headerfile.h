#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//User Defined Data-Type For Creating a Node
struct Node
{
  int iData;
  struct Node *Next;
  struct Node *Prev;
};


//Function Declarations OR Prototypes
void DisplayLinkedList(struct Node *);
void DisplayLinkedListReverse(struct Node *);
int CountNodes(struct Node *);
void CreateNewNode(int, struct Node *);
void InsertAtFirst(int, struct Node **);
void InsertAtLast(int, struct Node **);
void InsertAtPosition(int, int, struct Node **);
void DeleteFirst(struct Node **);
void DeleteLast(struct Node **);
void DeleteFromPosition(int, struct Node **);

