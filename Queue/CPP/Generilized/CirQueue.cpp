#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node<T> * next;
};

template <class T>
class CirQueueX
{
    private:
        struct node<T> * first;
        struct node<T> * last;
        int iCount;

    public:

        CirQueueX() 
        {
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;        
        }

        void enqueue(T no)
        {
            struct node<T> * newn = NULL;
            
            newn = new node<T>;
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

        T dequeue()
        {
            struct node<T> * temp = NULL;
            T value;

            if((first == NULL) && (last == NULL))
            {
                cout<<"Unable to delete Queue is empty\n";
                return NULL;
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
            struct node<T> * temp = NULL;

            temp = first;
            
            if((first == NULL) && (last == NULL))
            {
                cout << "Queue is empty\n";
                return;
            }
    
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
    CirQueueX<int> * obj = new CirQueueX<int>();

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
            obj->enqueue(value);
        }
        else if(choice == 2)
        {
            value = obj->dequeue();
            cout<<"Dequeued from front: "<<value<<endl;
        }
        else if(choice == 3)
        {
            obj->Display();
        }
        else if(choice == 4)
        {
            cout<<"Total elements in deque: "<<obj->Count()<<endl;
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
