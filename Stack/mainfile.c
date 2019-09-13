#include"helperfile.c"


int main(int argc, char *argv[])
{
  struct Node *Head = NULL;
  int iChoice = 0, iElement = 0, iAns = 0;

  while(1)
    {
      printf("\n-----STACK-----\n");
      printf("\n1. PUSH ELEMENT IN STACK\n");
      printf("2. POP ELEMENT FROM STACK\n");
      printf("3. COUNT ELEMENTS FROM STACK\n");
      printf("4. DISPLAY STACK\n");
      printf("5. EXIT\n");

      printf("\nENTER YOUR CHOICE : ");
      scanf("%d", &iChoice);
      
      switch(iChoice)
	{
	case 1:
	  printf("\nENTER ELEMENT : ");
	  scanf("%d", &iElement);
	  Push(iElement, &Head);
	  break;

	case 2:
	  Pop(&Head);
	  break;
	  
	case 3:
	  iAns = CountElements(Head);
	  printf("\nTOTAL ELEMENTS IN STACK : %d\n", iAns);
	  break;

	case 4:
	  DisplayStack(Head);
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
