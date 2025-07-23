#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node * next;
    struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void EnqueueFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;

        *first = newn;
    }
}

void EnqueueLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
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

int DequeueFirst(PPNODE first, PPNODE last)
{
    int value = 0;
    PNODE temp = NULL;

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
        (*first)->prev = NULL;
        
        free(temp);
    }

    return value;
}

int DequeueLast(PPNODE first, PPNODE last)
{
    int value = 0;
    PNODE temp = NULL;

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
        temp = *last;

        value = temp->data;

        *last = (*last)->prev;
        (*last)->next = NULL;
        
        free(temp);
    }

    return value;
}

void DisplayFirst(PNODE first, PNODE last)
{
    if((first == NULL) && (last == NULL))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("NULL =");
    while (first != NULL)
    {
        printf(" | %d | = ",first->data);
        first = first->next;
    }
    
    printf("NULL\n");
}

void DisplayLast(PNODE first, PNODE last)
{
    if((first == NULL) && (last == NULL))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("NULL =");
    while (last != NULL)
    {
        printf(" | %d | = ",last->data);
        last = last->prev;
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
    PNODE tail = NULL;
    int choice = 0;
    int value = 0;
    int iRet = 0;

    printf("\n=============================================================\n");
    printf("                Doubly Ended Queue (Deque) Manager                    \n");
    printf("=============================================================\n");

    while(1)
    {
        printf("\n-------------------------------------------------------------\n");
        printf("Please select an operation:\n");
        printf("-------------------------------------------------------------\n");
        printf(" 1 : Enqueue at front\n");
        printf(" 2 : Enqueue at rear\n");
        printf(" 3 : Dequeue from front\n");
        printf(" 4 : Dequeue from rear\n");
        printf(" 5 : Display from front to rear\n");
        printf(" 6 : Display from rear to front\n");
        printf(" 7 : Count total elements\n");
        printf(" 0 : Exit\n");
        printf("-------------------------------------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        if(choice == 1)
        {
            printf("Enter element to enqueue at front: ");
            scanf("%d",&value);
            EnqueueFirst(&head, &tail, value);
        }
        else if(choice == 2)
        {
            printf("Enter element to enqueue at rear: ");
            scanf("%d",&value);
            EnqueueLast(&head, &tail, value);
        }
        else if(choice == 3)
        {
            value = DequeueFirst(&head, &tail);
            printf("Dequeued from front: %d\n",value);
        }
        else if(choice == 4)
        {
            value = DequeueLast(&head, &tail);
            printf("Dequeued from rear: %d\n",value);
        }
        else if(choice == 5)
        {
            DisplayFirst(head, tail);
        }
        else if(choice == 6)
        {
            DisplayLast(head, tail);
        }
        else if(choice == 7)
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
}