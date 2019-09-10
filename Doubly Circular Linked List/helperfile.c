#include"headerfile.h"

//Function For Displaying Linked List
void DisplayLinkedList(struct Node *Start)
{
  struct Node *Temp = NULL;

  if(Start == NULL)
    {
      printf("\nERROR : LINKED LIST IS EMPTY\n");
    }
  else
    {
      Temp = Start;
      do
	{
	  printf(" %d ->", Temp->iData);
	  Temp = Temp->Next;
	}
      while(Temp != Start);
    }

  printf("\n");
}


//Function For Displaying Linked List in Reverse Order
void DisplayLinkedListReverse(struct Node *Start)
{
  struct Node *Temp1 = NULL, *Temp2 = NULL;

  if(Start == NULL)
    {
      printf("\nERROR : LINKED LIST IS EMPTY\n");
    }
  else
    {
      Temp1 = Start;
      while(Temp1->Next != Start)
	{
	  Temp1 = Temp1->Next;
	}

      Temp2 = Temp1;
  
      do
	{
	  printf(" %d ->", Temp1->iData);
	  Temp1 = Temp1->Prev;
	}
      while(Temp1 != Temp2);
    }
  
  printf("\n");
}


//Function For Counting Total Number of Elements in Linked List
int CountNodes(struct Node *Start)
{
  struct Node *Temp = NULL;
  int iCnt = 0;

  if(Start != NULL)
    {
      Temp = Start;
      do
	{
	  iCnt++;
	  Temp = Temp->Next;
	}
      while(Temp != Start);
    }

  return iCnt;
}


//Function For Creating New Node
void CreateNewNode(int iValue, struct Node *NewNode)
{
  NewNode->Prev = NewNode;
  NewNode->iData = iValue;
  NewNode->Next = NewNode;
}


//Function For Inserting Element At First Position
void InsertAtFirst(int iValue, struct Node **Start)
{
  struct Node *NewNode = NULL;

  NewNode = (struct Node *)malloc(sizeof(struct Node));

  CreateNewNode(iValue, NewNode);

  if(*Start == NULL)
    {
      *Start = NewNode;
    }
  else
    {
      NewNode->Next = *Start;
      NewNode->Prev = (*Start)->Prev;
      ((*Start)->Prev)->Next = NewNode;
      (*Start)->Prev = NewNode;
      *Start = NewNode;
    }
}


//Function For Inserting Element At Last Position
void InsertAtLast(int iValue, struct Node **Start)
{
  struct Node *NewNode = NULL;

  NewNode = (struct Node *)malloc(sizeof(struct Node));

  CreateNewNode(iValue, NewNode);

  if(*Start == NULL)
    {
      *Start = NewNode;
    }
  else
    {
      NewNode->Prev = (*Start)->Prev;
      NewNode->Next = *Start;
      ((*Start)->Prev)->Next = NewNode;
      (*Start)->Prev = NewNode;
    }
}


//Function For Inserting Element Given Position
void InsertAtPosition(int iPos, int iElement, struct Node **Start)
{
  struct Node *NewNode = NULL, *Temp = NULL;
  int iTotalNodes = 0, iCnt = 0;
  
  NewNode = (struct Node *)malloc(sizeof(struct Node));

  CreateNewNode(iElement, NewNode);

  iTotalNodes = CountNodes(*Start);

  if((iPos <= 0) || (iPos > (iTotalNodes + 1)))
    {
      printf("\nERROR : ENTER VALID POSITION NUMBER\n");
    }
  else if(iPos == 1)
    {
      InsertAtFirst(iElement, Start);
    }
  else if(iPos == (iTotalNodes + 1))
    {
      InsertAtLast(iElement, Start);
    }
  else
    {
      Temp = *Start;
      while(iCnt != (iPos - 2))
	{
	  Temp = Temp->Next;
	  iCnt++;
	}

      NewNode->Prev = Temp;
      NewNode->Next = Temp->Next;
      (Temp->Next)->Prev = NewNode;
      Temp->Next = NewNode;
    }
}



//Function For Delete The First Element of Linked List
void DeleteFirst(struct Node **Start)
{
  struct Node *Temp = NULL;
  
  if(*Start == NULL)
    {
      printf("\nERROR : LINKED LIST IS EMPTY\n");
    }
  else if((*Start)->Next == *Start)
    {
      free(*Start);
      *Start = NULL;
    }
  else
    {
      Temp = *Start;
      ((*Start)->Prev)->Next = (*Start)->Next;
      ((*Start)->Next)->Prev = (*Start)->Prev;
      *Start = (*Start)->Next;
      free(Temp);
      Temp = NULL;
    }
}



//Function For Delete The Last Element of Linked List
void DeleteLast(struct Node **Start)
{
  struct Node *Temp = NULL;
  
  if(*Start == NULL)
    {
      printf("\nERROR : LINKED LIST IS EMPTY\n");
    }
  else if((*Start)->Next == *Start)
    {
      free(*Start);
      *Start = NULL;
    }
  else
    {
      Temp = (*Start)->Prev;
      (((*Start)->Prev)->Prev)->Next = *Start;
      (*Start)->Prev = ((*Start)->Prev)->Prev;
      free(Temp);
      Temp = NULL;
    }
}


//Function For Delete The Element From Given Position Linked List
void DeleteFromPosition(int iPos, struct Node **Start)
{
  struct Node *Temp = NULL;
  int iTotalNodes = 0, iCnt = 0;

  iTotalNodes = CountNodes(*Start);

  if(*Start == NULL)
    {
      printf("\nERROR : LINKED LIST IS EMPTY\n");
    }
  else if((iPos <=0) || (iPos > iTotalNodes))
    {
      printf("\nERROR : ENTER VALID POSITION NUMBER\n");
    }
  else if(iPos == 1)
    {
      DeleteFirst(Start);
    }
  else if(iPos == iTotalNodes)
    {
      DeleteLast(Start);
    }
  else
    {
      Temp = *Start;
      while(iCnt != (iPos - 1))
	{
	  iCnt++;
	  Temp = Temp->Next;
	}

      (Temp->Prev)->Next = Temp->Next;
      (Temp->Next)->Prev = Temp->Prev;
      free(Temp);
      Temp = NULL;
    }
}
