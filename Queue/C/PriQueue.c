#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int prio;
    struct node * next;
    struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void enqueue(PPNODE first, PPNODE last, int no, int pri)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->prio = pri;
    newn->next = NULL;
    newn->prev = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last)->next = newn;
        newn->prev = *last;

        *last = newn;   
    }
}

int dequeue(PPNODE first, PPNODE last)
{
    int value = 0;
    PNODE iMax = NULL;
    PNODE temp = NULL;

    if((*first == NULL) && (*last == NULL))
    { 
        printf("Unable to delete Queue is empty\n");
        return -1;
    }
    else if (*first == *last)
    {
        value = (*first)->data;
        free(*first);

        *first = NULL;
        *last = NULL;
    }
    else
    {
        iMax = *first;
        temp = *first;

        while(temp != NULL)
        {
            if (iMax->prio < temp->prio)
            {
                iMax = temp;
            }

            temp = temp->next;
        }

        value = iMax->data;

        if(iMax == *first) 
        {
            *first = (*first)->next;
            (*first)->prev = NULL;

            free(iMax);
        }
        else if(iMax == *last) 
        {
            *last = (*last)->prev;
            (*last)->next = NULL;

            free(iMax);
        }
        else
        {
            iMax->next->prev = iMax->prev;
            iMax->prev->next = iMax->next;

            free(iMax);
        }
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

    printf("NULL =");

    while(first != NULL)
    {
        printf(" | %d | %d | = ",first->data, first->prio);
        first = first->next;
    }

    printf("NULL\n");
}

int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    if((first == NULL) && (last == NULL))
    {
        printf("Queue is empty\n");
        return 0;
    }

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;
    int choice = 0;
    int value = 0;
    int prio = 0;

    printf("\n=============================================================\n");
    printf("                       Priority Queue Manager                    \n");
    printf("=============================================================\n");

    while(1)
    {
        printf("\n-------------------------------------------------------------\n");
        printf("Please select an operation:\n");
        printf("-------------------------------------------------------------\n");
        printf(" 1 : Enqueue (Enter data with priority)\n");
        printf(" 2 : Dequeue (Remove element with highest priority)\n");
        printf(" 3 : Display queue elements\n");
        printf(" 4 : Count total elements\n");
        printf(" 0 : Exit\n");
        printf("-------------------------------------------------------------\n");

        printf("Enter your choice: \n");
        scanf("%d",&choice);

        if(choice == 1)
        {
            printf("Enter element to enqueue : \n");
            scanf("%d",&value);
            printf("Enter priority of the element: \n");
            scanf("%d",&prio);
            enqueue(&head, &tail, value, prio);
        }
        else if(choice == 2)
        {
            value = dequeue(&head, &tail);          // "If multiple jobs have same highest priority, the first inserted is removed first."

            if(value != -1)
            {
                printf("Dequeued element with highest priority: %d\n",value);
            }
        }
        else if(choice == 3)
        {
            Display(head, tail);
        }
        else if(choice == 4)
        {
            iRet = Count(head, tail);
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
};