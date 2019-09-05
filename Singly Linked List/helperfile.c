#include"headerfile.h"

//Function For Displaying The Linked List
void DisplayLinkedList(struct Node *Head)
{
  struct Node *Temp = NULL;
  
  Temp = Head;
  while(Temp != NULL)
    {
      printf("%d -> ", Temp->iData);
      Temp = Temp->Next;
    }

  printf(" NULL\n");
}


//Function For Counting The Total Elements in Linked List
int CountNodes(struct Node *Start)
{
  struct Node *Temp = NULL;
  int iCnt = 0;

  Temp = Start;
  while(Temp != NULL)
    {
      iCnt++;
      Temp = Temp->Next;
    }

  return iCnt;
}


//Function For Creating New Node
void CreateNewNode(int iValue, struct Node *NewNode)
{ 
  NewNode->iData = iValue;
  NewNode->Next = NULL;
}


//Function For Inserting Element at First Position in The Linked List
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
      *Start = NewNode;
    }
}


//Function For Inserting Element at Last Position in The Linked List
void InsertAtLast(int iValue, struct Node **Start)
{
  struct Node *NewNode = NULL;
  struct Node *Temp = NULL;
  
  NewNode = (struct Node *)malloc(sizeof(struct Node));

  CreateNewNode(iValue, NewNode);
  
  if(*Start == NULL)
    {
      *Start = NewNode;
    }
  else
    {
      Temp = *Start;
      
      while((Temp->Next) != NULL)
      {
	Temp = (Temp->Next);
      }

      Temp->Next = NewNode;
    }  
}


//Function For Inserting Element at Given Position in The Linked List
void InsertAtPosition(int iPos, int iElement, struct Node **Start)
{
  int iCnt = 0, iTotalNodes = 0;
  struct Node *Temp = NULL;
  struct Node *NewNode = NULL;

  NewNode = (struct Node *)malloc(sizeof(struct Node));

  CreateNewNode(iElement, NewNode);

  iTotalNodes = CountNodes(*Start);

  if((iPos <= 0) || (iPos > (iTotalNodes + 1)))
    {
      printf("\nENTERED POSITION NUMBER IS NOT VALID...!!!\n");
    }
  else if((iPos == 1))
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
  struct Node *Temp = NULL;
  
  if(*Start == NULL)
    {
      printf("\nERROR : LINKED LIST IS EMPTY\n");
    }
  else if((*Start)->Next == NULL)
    {
      free(*Start);
      *Start = NULL;
    }
  else
    {
      Temp = *Start;
      *Start = (*Start)->Next;
      free(Temp);
      Temp = NULL;
    }
}


//Function For Deleting Element at Last Position in The Linked List
void DeleteLast(struct Node **Start)
{
  struct Node *Temp = NULL;

  Temp = *Start;

  if(Temp == NULL)
    {
      printf("\nERROR : LINKED LIST IS EMPTY\n");
    }
  else if(Temp->Next == NULL)
    {
      free(Temp);
    }
  else
    {
      while((Temp->Next)->Next != NULL)
	{
	  Temp = Temp->Next;
	}
      
      free(Temp->Next);
      Temp->Next = NULL;
    }
}


//Function For Deleting Element from Given Position in The Linked List
void DeleteFromPosition(int iPos, struct Node **Start)
{
  struct Node *Temp = NULL, *Temp2 = NULL;
  int iCnt = 0, iTotalNodes = 0;

  iTotalNodes = CountNodes(*Start);

  if(*Start == NULL)
    {
      printf("\nERROR : LINKED LIST IS EMPTY\n");
    }
  else if((iPos <= 0) || (iPos > iTotalNodes))
    {
      printf("\nENTERED POSITION NUMBER IS NOT VALID...!!!\n");
    }
  else if(iPos == 1)
    {
      DeleteFirst(Start);
    }
  else if(iTotalNodes == iPos)
    {
      DeleteLast(Start);
    }
  else
    {
      Temp = *Start;
      while(iCnt != (iPos - 2))
	{
	  iCnt++;
	  Temp = Temp->Next;
	}

      Temp2 = Temp->Next;
      Temp->Next = (Temp->Next)->Next;
      free(Temp2);
    }
}

