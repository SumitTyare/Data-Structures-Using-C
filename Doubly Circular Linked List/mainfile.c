#include"helperfile.c"

int main(int argc, char *argv[])
{
  struct Node *Head = NULL;
  int iPos = 0, iElement = 0, iAns = 0, iChoice = 0;

  while(1)
    {
      printf("\n\n-----DOUBLY CIRCULAR LINKED LIST-----\n");
      printf("\n1. INSERT ELEMENT AT FIRST\n");
      printf("2. INSERT ELEMENT AT LAST\n");
      printf("3. INSERT ELEMENT AT POSITION\n");
      printf("4. DELETE FIRST ELEMENT\n");
      printf("5. DELETE LAST ELEMENT\n");
      printf("6. DELETE ELEMENT AT POSITION\n");
      printf("7. COUNT THE TOTAL NUMBER OF ELEMENTS\n");
      printf("8. DISPLAY THE LINKED LIST\n");
      printf("9. DISPLAY THE LINKED LIST IN REVERSE ORDER\n");
      printf("10. EXIT\n");
      printf("\nENTER YOUR CHOICE : ");
      scanf("%d", &iChoice);
      
      switch(iChoice)
	{
	case 1:
	  printf("\nEnter The Element : ");
	  scanf("%d", &iElement);
	  InsertAtFirst(iElement, &Head);
	  break;

	case 2:
	  printf("\nEnter The Element : ");
	  scanf("%d", &iElement);
	  InsertAtLast(iElement, &Head);
	  break;

	case 3:
	  printf("\nEnter The Element : ");
	  scanf("%d", &iElement);
	  printf("Enter The Position Number : ");
	  scanf("%d", &iPos);
	  InsertAtPosition(iPos, iElement, &Head);
	  break;

	case 4:
	  DeleteFirst(&Head);
	  break;

	case 5:
	  DeleteLast(&Head);
	  break;

	case 6:
	  printf("\nEnter Position : ");
	  scanf("%d", &iPos);
	  DeleteFromPosition(iPos, &Head);
	  break;

	case 7:
	  iAns = CountNodes(Head);
	  printf("\nTOTAL NUMBER OF NODES IN LINKED LIST ARE : %d\n", iAns);
	  break;
	
	case 8:
	  printf("\nDISPLAYING LINKED LIST :\n");
	  DisplayLinkedList(Head);
	  break;

	case 9:
	  printf("\nDISPLAYING LINKED LIST IN REVERSE ORDER :\n");
	  DisplayLinkedListReverse(Head);
	  break;
	  
	case 10:
	  exit(0);
	  
	default:
	  printf("\nENTER CORRECT CHOICE...!!!\n");
	  break;
	}
    }

  return 0;
}
