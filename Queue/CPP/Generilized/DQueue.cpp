#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node<T> * next;
    struct node<T> * prev;
};

template <class T>
class DQueueX
{
    private: 
        struct node<T> * first;
        struct node<T> * last;
        int iCount = 0;

    public:

        DQueueX()
        {
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void enqueuefirst(T no)
        {
            struct node<T> * newn = NULL;

            newn = new node<T>;
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

        void enqueuelast(T no)
        {
            struct node<T> * newn = NULL;

            newn = new node<T>;
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

        T dequeuefirst()
        {
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
                value = first->data;
                first = first->next;

                delete first->prev;

                first->prev = NULL;
            }

            iCount--;
            return value;
        }

        T dequeuelast()
        {
            T value;

            if((first == NULL) && (last == NULL))
            {
                cout<<"Unable to delete Queue is empty\n";
                return NULL;
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
            struct node<T> * temp = NULL;

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
            struct node<T> * temp = NULL;

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
    DQueueX<int> * obj = new DQueueX<int>();

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
            obj->enqueuefirst(value);
        }
        else if(choice == 2)
        {
            cout<<"Enter element to enqueue at rear: ";
            cin>>value;
            obj->enqueuelast(value);
        }
        else if(choice == 3)
        {
            value = obj->dequeuefirst();
            cout<<"Dequeued from front: "<<value<<endl;
        }
        else if(choice == 4)
        {
            value = obj->dequeuelast();
            cout<<"Dequeued from rear: "<<value<<endl;
        }
        else if(choice == 5)
        {
            obj->DisplayFirst();
        }
        else if(choice == 6)
        {
            obj->DisplayLast();
        }
        else if(choice == 7)
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