#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;

class DQueueX
{
    private: 
        PNODE first;
        PNODE last;
        int iCount = 0;

    public:

        DQueueX()
        {
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void enqueuefirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if((first == NULL) && (last == NULL))
            {
                first = newn;
                last = newn;
            }
            else
            {
                newn->next = first;
                first->prev = newn;

                first = newn;
            }

            iCount++;
        }

        void enqueuelast(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if((first == NULL) && (last == NULL))
            {
                first = newn;
                last = newn;
            }
            else
            {
                last->next = newn;
                newn->prev = last;

                last = newn;
            }

            iCount++;
        }

        int dequeuefirst()
        {
            int value = 0;

            if((first == NULL) && (last == NULL))
            {
                cout<<"Unable to delete Queue is empty\n";
                return -1;
            }
            else if(first == last)
            {
                value = first->data;

                delete first;

                first = NULL;
                last = NULL;
            }
            else
            {
                value = first->data;
                first = first->next;

                delete first->prev;

                first->prev = NULL;
            }

            iCount--;
            return value;
        }

        int dequeuelast()
        {
            int value = 0;

            if((first == NULL) && (last == NULL))
            {
                cout<<"Unable to delete Queue is empty\n";
                return -1;
            }
            else if(first == last)
            {
                value = last->data;

                delete last;

                first = NULL;
                last = NULL;
            }
            else
            {
                value = last->data;
                last = last->prev;

                delete last->next;

                last->next = NULL;
            }

            iCount--;
            return value;
        }

        void DisplayFirst()
        {
            PNODE temp = NULL;

            if((first == NULL) && (last == NULL))
            {
                cout << "Deque is empty\n";
                return;
            }

            temp = first;

            cout<<"Deque (Front to Rear): \n = ";
            while(temp != NULL)
            {
                cout<<" | "<<temp->data<<" | = ";
                temp = temp->next;
            }

            cout<<"\n";
        }

        void DisplayLast()
        {
            PNODE temp = NULL;

            if((first == NULL) && (last == NULL))
            {
                cout << "Deque is empty\n";
                return;
            }

            temp = last;

            cout<<"Deque (Rear to Front): \n = ";
            while(temp != NULL)
            {
                cout<<" | "<<temp->data<<" | = ";
                temp = temp->prev;
            }

            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    DQueueX obj;

    int choice = 0;
    int value = 0;

    cout<<"\n============================================================="<<endl;
    cout<<"               Doubly Ended Queue (Deque) Manager             "<<endl;
    cout<<"============================================================="<<endl;

    while (true)
    {
        cout<<"\n-------------------------------------------------------------"<<endl;
        cout<<"Please select an operation:"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<" 1 : Enqueue at front"<<endl;
        cout<<" 2 : Enqueue at rear"<<endl;
        cout<<" 3 : Dequeue from front"<<endl;
        cout<<" 4 : Dequeue from rear"<<endl;
        cout<<" 5 : Display from front to rear"<<endl;
        cout<<" 6 : Display from rear to front"<<endl;
        cout<<" 7 : Count total elements"<<endl;
        cout<<" 0 : Exit"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice == 1)
        {
            cout<<"Enter element to enqueue at front: ";
            cin>>value;
            obj.enqueuefirst(value);
        }
        else if(choice == 2)
        {
            cout<<"Enter element to enqueue at rear: ";
            cin>>value;
            obj.enqueuelast(value);
        }
        else if(choice == 3)
        {
            value = obj.dequeuefirst();
            cout<<"Dequeued from front: "<<value<<endl;
        }
        else if(choice == 4)
        {
            value = obj.dequeuelast();
            cout<<"Dequeued from rear: "<<value<<endl;
        }
        else if(choice == 5)
        {
            obj.DisplayFirst();
        }
        else if(choice == 6)
        {
            obj.DisplayLast();
        }
        else if(choice == 7)
        {
            cout<<"Total elements in deque: "<<obj.Count()<<endl;
        }
        else if(choice == 0)
        {
            cout<<"Thank you for using the Deque Manager!"<<endl;
            break;
        }
        else
        {
            cout<<"Invalid choice. Please try again."<<endl;
        }
    }

    return 0;
}