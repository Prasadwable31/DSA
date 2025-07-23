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

void enqueue(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;

        (*last)->next = *first;
    }
    else
    {
        (*last)->next = newn;
        *last = newn;

        (*last)->next = *first;
    }
}

int dequeue(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;
    int value = 0;

    if((*first == NULL) && (*last == NULL))
    {
        printf("Unable to delete Queue is empty\n");
        return -1;
    }
    else if(*first == *last)
    {
        value = (*first)->data;

        free(*first);

        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;
        value = temp->data;

        *first = (*first)->next;
        (*last)->next = *first;
        
        free(temp);
    }

    return value;
}

void Display(PNODE first, PNODE last)
{
    if((first == NULL) && (last == NULL))
    {
        printf("Queue is empty\n");
        return;
    }

    do
    {
        printf(" | %d | - ",first->data);
        first = first->next;

    } while(first != last->next);

    printf("\n");
    
}

int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    if((first == NULL) && (last == NULL))
    {
        printf("Queue is empty\n");
        return 0;
    }

    do
    {
        iCount++;
        first = first->next;

    } while(first != last->next);

    return iCount;
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;
    int choice = 0;
    int value = 0;

    printf("\n=============================================================\n");
    printf("                       Circular Queue Manager                    \n");
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
            enqueue(&head, &tail, value);
        }
        else if(choice == 2)
        {
            value = dequeue(&head, &tail);
            if(value != -1)
            {
                printf("Dequeued from front: %d\n",value);
            }
        }
        else if(choice == 3)
        {
            Display(head, tail);
        }
        else if(choice == 4)
        {
            iRet = Count(head, tail);
            printf("Total elements in queque: %d\n",iRet);
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
};