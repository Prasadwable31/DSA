#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class CirQueueX
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:

        CirQueueX() 
        {
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;        
        }

        void enqueue(int no)
        {
            PNODE newn = NULL;
            
            newn = new NODE;
            newn->data = no;
            newn->next = NULL;

            if((first == NULL) && (last == NULL))
            {   
                first = newn;
                last = newn;

                last->next = first;
            }
            else
            {
                last->next = newn;
                last = newn;

                last->next = first;
            }

            iCount++;
        }

        int dequeue()
        {
            int value = 0;
            PNODE temp = NULL;

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
                temp = first;
                value = temp->data;

                first = first->next;
                last->next = first;

                delete temp;
            }

            iCount--;
            return value;
        }

        void Display()
        {
            PNODE temp = NULL;

            if((first == NULL) && (last == NULL))
            {
                return;
            }

            temp = first;
    
            do
            {
                cout<<" | "<<temp->data<<" | - ";
                temp = temp->next;
            } while (temp != last->next);
            
            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }
};


int main()
{
    CirQueueX obj;

    int choice = 0;
    int value = 0;

    cout<<"\n============================================================="<<endl;
    cout<<"                    Circular Queue Manager                    "<<endl;
    cout<<"============================================================="<<endl;

    while (true)
    {
        cout<<"\n-------------------------------------------------------------"<<endl;
        cout<<"Please select an operation:"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<" 1 : Enqueue at rear"<<endl;
        cout<<" 2 : Dequeue from front"<<endl;
        cout<<" 3 : Display from front to rear"<<endl;
        cout<<" 4 : Count total elements"<<endl;
        cout<<" 0 : Exit"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice == 1)
        {
            cout<<"Enter element to enqueue at rear: ";
            cin>>value;
            obj.enqueue(value);
        }
        else if(choice == 2)
        {
            value = obj.dequeue();
            cout<<"Dequeued from front: "<<value<<endl;
        }
        else if(choice == 3)
        {
            obj.Display();
        }
        else if(choice == 4)
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
