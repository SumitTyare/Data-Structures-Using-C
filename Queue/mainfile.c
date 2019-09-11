#include"helperfile.c"

int main(int argc, char *argv[])
{
  struct Node *Head = NULL;
  int iChoice = 0, iElement = 0, iAns = 0;

  while(1)
    {
      printf("\n-----QUEUE-----\n");
      printf("\n1. ENQUEUE ELEMENT IN QUEUE\n");
      printf("2. DEQUEUE ELEMENT FROM QUEUE\n");
      printf("3. COUNT ELEMENTS FROM QUEUE\n");
      printf("4. DISPLAY QUEUE\n");
      printf("5. EXIT\n");

      printf("\nENTER YOUR CHOICE : ");
      scanf("%d", &iChoice);
      
      switch(iChoice)
	{
	case 1:
	  printf("\nENTER ELEMENT : ");
	  scanf("%d", &iElement);
	  EnQueue(iElement, &Head);
	  break;

	case 2:
	  DeQueue(&Head);
	  break;
	  
	case 3:
	  iAns = CountElements(Head);
	  printf("\nTOTAL ELEMENTS IN QUEUE : %d\n", iAns);
	  break;

	case 4:
	  DisplayQueue(Head);
	  break;

	case 5:
	  exit(0);

        default:
	  printf("\nENTER VALID CHOICE...!!!\n");
	  break;
	}
    }

  return 0;
}
