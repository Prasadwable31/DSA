#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    int prio;
    struct node<T> * next;
    struct node<T> * prev;
};

template <class T>
class PriQueueX
{
    private:
        struct node<T> * first;
        struct node<T> * last;
        int iCount;

    public:

        PriQueueX()
        {
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void enqueue(T no, int pri)
        {
            struct node<T> * newn = NULL;

            newn = new node<T>;
            newn->data = no;
            newn->prio = pri;
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

        T dequeue()
        {
            struct node<T> * iMax = NULL;
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
                iMax = first;

                while(temp != NULL)
                {
                    if(iMax->prio < temp->prio)
                    {
                        iMax = temp;
                    }

                    temp = temp->next;
                }

                value = iMax->data;

                if(iMax == first)
                {
                    first = first->next;
                    first->prev = NULL;

                    delete iMax;
                }
                else if(iMax == last)
                {
                    last = last->prev;
                    last->next = NULL;

                    delete iMax;
                }
                else
                {
                    iMax->next->prev = iMax->prev;
                    iMax->prev->next = iMax->next;

                    delete iMax;
                }
            }

            iCount--;
            return value;
        }

        void Display()
        {
            struct node<T> * temp = NULL;

            temp = first;

            cout<<"Data | Priority\n";
            while (temp != NULL)
            {
                cout<<" | "<<temp->data<<" | "<<temp->prio<<" | -";
                temp = temp->next;
            }

            cout<<" NULL\n";
            
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    PriQueueX<int> * obj = new PriQueueX<int>();

    int choice = 0;
    int value = 0;
    int prio = 0;

    cout<<"\n============================================================="<<endl;
    cout<<"                   Priority Queue Manager                     "<<endl;
    cout<<"============================================================="<<endl;

    while (true)
    {
        cout<<"\n-------------------------------------------------------------"<<endl;
        cout<<"Please select an operation:"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<" 1 : Enqueue (Enter data with priority)"<<endl;
        cout<<" 2 : Dequeue (Remove element with highest priority)"<<endl;
        cout<<" 3 : Display queue elements"<<endl;
        cout<<" 4 : Count total elements"<<endl;
        cout<<" 0 : Exit"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice == 1)
        {
            cout<<"Enter element to enqueue: ";
            cin>>value;
            cout<<"Enter priority of the element: ";
            cin>>prio;

            obj->enqueue(value, prio);
        }
        else if(choice == 2)
        {
            value = obj->dequeue();
            if(value != -1)
            {
                cout<<"Dequeued element with highest priority: "<<value<<endl;
            }
        }
        else if(choice == 3)
        {
            obj->Display();
        }
        else if(choice == 4)
        {
            cout<<"Total elements in priority queue: "<<obj->Count()<<endl;
        }
        else if(choice == 0)
        {
            cout<<"Thank you for using the Priority Queue Manager!"<<endl;
            break;
        }
        else
        {
            cout<<"Invalid choice. Please try again."<<endl;
        }
    }

    return 0;
}
