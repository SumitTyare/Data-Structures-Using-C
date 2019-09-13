#include"headerfile.h"


//Function For Displaying Stack
void DisplayStack(struct Node *Start)
{
  struct Node *Temp = NULL;

  if(Start == NULL)
    {
      printf("\nERROR : STACK IS EMPTY\n");
    }
  else
    {
      Temp = Start;
      while(Temp != NULL)
	{
	  printf("%d\n", Temp->iData);
	  printf("|\n");
	  Temp = Temp->Next;
	}
    }
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
void Push(int iValue, struct Node **Start)
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
void Pop(struct Node **Start)
{
  struct Node *Temp = NULL;

  if(*Start == NULL)
    {
      printf("\nERROR : STACK IS EMPTY\n");
    }
  else
    {
      Temp = *Start;
      *Start = (*Start)->Next;
      free(Temp);
      Temp = NULL;
    }
}
