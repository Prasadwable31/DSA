#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void push(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    newn->next = *first;
    *first = newn;
}

int pop(PPNODE first)
{
    PNODE temp = NULL;
    int value = 0;

    if (*first == NULL)
    {
        printf("Unable to delete stack empty\n");
        return -1;
    }
    else
    {
        temp = *first;
        value = temp->data;

        *first = (*first)->next;
        free(temp);

        return value;
    }
}

void Display(PNODE first)
{
    if(first == NULL)
    {
        printf("Stack is empty\n");
    }

    while (first != NULL)
    {
        printf("| %d |\n",first->data);
        first = first->next;
    }
}

int Count(PNODE first)
{
    int iCount = 0;

    while (first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

int main()
{
    PNODE head = NULL;
    int choice = 0;
    int value = 0;
    int iRet = 0;

    printf("\n=================================================\n");
    printf("           Stack Manager (Linked List)      \n");
    printf("=================================================\n");

    while (1)
    {
        printf("\n-------------------------------------------\n");
        printf("Please choose an operation:\n");
        printf("-------------------------------------------\n");
        printf(" 1 : Push element onto stack\n");
        printf(" 2 : Pop element from stack\n");
        printf(" 3 : Display stack\n");
        printf(" 4 : Count elements in stack\n");
        printf(" 0 : Exit\n");
        printf("-------------------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&head, value);
        }
        else if(choice == 2)
        {
            iRet = pop(&head);
            if (iRet != -1)
            {
                printf("Popped element from stack: %d\n", iRet);
            }
        }
        else if(choice == 3)
        {
            printf("Current Stack:\n");
            Display(head);
        }
        else if(choice == 4)
        {
            iRet = Count(head);
            printf("Number of elements in stack: %d\n", iRet);
        }
        else if(choice == 0)
        {
            printf("Thank you for using Stack Manager!\n");
            break;
        }
        else
        {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
