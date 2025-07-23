#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

class Queue
{   
    private:
        struct node * first;
        int iCount;

    public:
    
        Queue()
        {
            this->first = NULL;
            this->iCount = 0;
        }

        void enqueue(int no)
        {
            struct node * newn = NULL;
            struct node * temp = NULL;

            newn = new node;
            newn->data = no;
            newn->next = NULL;

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                temp = first;

                while (temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = newn;
            }

            iCount++;
        }

        int dequeue()
        {
            struct node * temp = NULL;
            int value = 0;

            if(first == NULL)
            {
                cout<<"Unable to delete Queue is empty\n";
                return -1;
            }
            else
            {
                temp = first;
                value = temp->data;

                first = first->next;
                iCount--;
                delete temp;

                return value;
            }
        }

        void Display()
        {
            struct node * temp = NULL;

            if(first == NULL)
            {
                cout << "Queue is empty\n";
                return;
            }
            
            temp = first;

            while (temp != NULL)
            {
                cout<<"| "<<temp->data<<" | - ";
                temp = temp->next;
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
    Queue obj;

    int choice = 0;
    int value = 0;

    cout<<"\n============================================================="<<endl;
    cout<<"                       Simple Queue Manager                    "<<endl;
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