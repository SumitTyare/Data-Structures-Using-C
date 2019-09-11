#include"headerfile.h"


//Function For Displaying Queue
void DisplayQueue(struct Node *Start)
{
  struct Node *Temp = NULL;

  if(Start == NULL)
    {
      printf("\nERROR : QUEUE IS EMPTY\n");
    }
  else
    {
      printf(" -> ");
      Temp = Start;
      while(Temp != NULL)
	{
	  printf(" %d -", Temp->iData);
	  Temp = Temp->Next;
	}

      printf(">");
    }

  printf("\n");
}


//Function For Counting Total Number Of Elements in Stack
int CountElements(struct Node *Start)
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



//Function For Creating New Node of Stack
void CreateNewNode(int iValue, struct Node *NewNode)
{
  NewNode->iData = iValue;
  NewNode->Next = NULL;
}


//Function For Push Element in Stack
void EnQueue(int iValue, struct Node **Start)
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


//Function For Pop Element From Stack
void DeQueue(struct Node **Start)
{
  struct Node *Temp = NULL;

  if(*Start == NULL)
    {
      printf("\nERROR : QUEUE IS EMPTY\n");
    }
  else if((*Start)->Next == NULL)
    {
      free(*Start);
      *Start = NULL;
    }
  else
    {
      Temp = *Start;
      while((Temp->Next)->Next != NULL)
	{
	  Temp = Temp->Next;
	}
   
      free(Temp->Next);
      Temp->Next = NULL;
    }
}
