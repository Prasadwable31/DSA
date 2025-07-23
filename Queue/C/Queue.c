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

void enqueue(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if (*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
}

int dequeue(PPNODE first)
{
    PNODE temp = NULL;
    int value = 0;

    if(*first == NULL)
    {
        printf("Unable to delete Queue is empty\n");
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
        printf("Queue is empty\n");
        return;
    }

    while (first != NULL)
    {
        printf("| %d | - ",first->data);
        first = first->next;
    }
    
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    if(first == NULL)
    {
        printf("Queue is empty\n");
        return 0;
    }

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
    int iRet = 0;
    int choice = 0;
    int value = 0;

    printf("\n=============================================================\n");
    printf("                       Simple Queue Manager                    \n");
    printf("=============================================================\n");

    while(1)
    {
        printf("\n-------------------------------------------------------------\n");
        printf("Please select an operation:\n");
        printf("-------------------------------------------------------------\n");
        printf(" 1 : Enqueue at rear\n");
        printf(" 2 : Dequeue from front\n");
        printf(" 3 : Display from front to rear\n");
        printf(" 4 : Count total elements\n");
        printf(" 0 : Exit\n");
        printf("-------------------------------------------------------------\n");

        printf("Enter your choice: \n");
        scanf("%d",&choice);

        if(choice == 1)
        {
            printf("Enter element to enqueue at rear: \n");
            scanf("%d",&value);
            enqueue(&head, value);
        }
        else if(choice == 2)
        {
            value = dequeue(&head);
            if(value != -1)
            {
                printf("Dequeued from front: %d\n",value);
            }
        }
        else if(choice == 3)
        {
            Display(head);
        }
        else if(choice == 4)
        {
            iRet = Count(head);
            printf("Total elements in deque: %d\n",iRet);
        }
        else if(choice == 0)
        {
            printf("Thank you for using our Application!\n");
            break;
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}