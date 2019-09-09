#include"headerfile.h"

//Function For Displaying The Linked List
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
	  printf(" %d -> ", Temp->iData);
	  Temp = Temp->Next;
	}
      while(Temp != Start);
    }

  printf("\n");
}

//Function For Counting The Total Elements in Linked List
int CountNodes(struct Node *Start)
{
  struct Node *Temp = NULL;
  int iCnt = 0;

  Temp = Start;
  if(Start != NULL)
    {
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
  NewNode->iData = iValue;
  NewNode->Next = NewNode;
}


//Function For Inserting Element at First Position in The Linked List
void InsertAtFirst(int iValue, struct Node **Start)
{
  struct Node *NewNode = NULL, *Temp = NULL;

  NewNode = (struct Node *)malloc(sizeof(struct Node));
  
  CreateNewNode(iValue, NewNode);

  if(*Start == NULL)
    {
      *Start = NewNode;
    }
  else
    {
      Temp = *Start;
      while(Temp->Next != *Start)
	{
	  Temp = Temp->Next;
	}

      Temp->Next = NewNode;
      NewNode->Next = *Start;
      *Start = NewNode;
    }
}

//Function For Inserting Element at Last Position in The Linked List
void InsertAtLast(int iValue, struct Node **Start)
{
  struct Node *NewNode = NULL, *Temp = NULL;

  NewNode = (struct Node *)malloc(sizeof(struct Node));

  CreateNewNode(iValue, NewNode);
  
  if(*Start == NULL)
    {
      *Start = NewNode;
    }
  else
    {
      Temp = *Start;
      while(Temp->Next != *Start)
	{
	  Temp = Temp->Next;
	}
      
      NewNode->Next = *Start;
      Temp->Next = NewNode;
    }
}

//Function For Inserting Element at Given Position in The Linked List
void InsertAtPosition(int iPos, int iValue, struct Node **Start)
{
  struct Node *NewNode = NULL, *Temp = NULL;
  int iTotalNodes = 0, iCnt = 0;
  
  NewNode = (struct Node *)malloc(sizeof(struct Node));

  CreateNewNode(iValue, NewNode);

  iTotalNodes = CountNodes(*Start);
  
  if((iPos <= 0) || (iPos > (iTotalNodes + 1)))
    {
      printf("\nERROR : ENTER VALID POSITION\n");
    }
  else if(iPos == 1)
    {
      InsertAtFirst(iValue, Start);
    }
  else if(iPos == (iTotalNodes + 1))
    {
      InsertAtLast(iValue, Start);
    }
  else
    {
      Temp = *Start;
      while(iCnt != (iPos - 2))
	{
	  iCnt++;
	  Temp = Temp->Next;
	}

      NewNode->Next = Temp->Next;
      Temp->Next = NewNode;
    }
}

//Function For Deleting Element from First Position in The Linked List
void DeleteFirst(struct Node **Start)
{
  struct Node *Temp1 = NULL, *Temp2 = NULL;
  
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
      Temp1 = Temp2 = *Start;
      
      while(Temp1->Next != *Start)
	{
	  Temp1 = Temp1->Next;
	}

      *Start = (*Start)->Next;
      Temp1->Next = *Start;
      free(Temp2);
      Temp2 = NULL;
    }
}

//Function For Deleting Element from Last Position in The Linked List
void DeleteLast(struct Node **Start)
{
  struct Node *Temp1 = NULL, *Temp2 = NULL;
  
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
      Temp1 = *Start;
      while((Temp1->Next)->Next != *Start)
	{
	  Temp1 = Temp1->Next;
	}

      Temp2 = Temp1->Next;
      Temp1->Next = *Start;
      free(Temp2);
      Temp2 = NULL;
    }
}


//Function For Deleting Element from Given Position in The Linked List
void DeleteFromPosition(int iPos, struct Node **Start)
{
  struct Node *Temp1 = NULL, *Temp2 = NULL;
  int iTotalNodes = 0, iCnt = 0;

  iTotalNodes = CountNodes(*Start);

  if(*Start == NULL)
    {
      printf("\nERROR : LINKED LIST IS EMPTY\n");
    }
  else if((iPos <= 0) || (iPos > iTotalNodes))
    {
      printf("\nERROR : ENTER VALID POSITION\n");
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
      Temp1 = *Start;
      while(iCnt != (iPos - 2))
	{
	  iCnt++;
	  Temp1 = Temp1->Next;
	}

      Temp2 = Temp1->Next;
      Temp1->Next = (Temp1->Next)->Next;
      free(Temp2);
      Temp2 = NULL;
    }
}
