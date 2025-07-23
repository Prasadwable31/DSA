#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node * next;
};

class Stack
{
    private:
        struct node * first;
        int iCount;

    public:

        Stack()
        {
            this->first = NULL;
            this->iCount = 0;
        }

        void push(int no)
        {
            struct node * newn = NULL;
            
            newn = new node;
            newn->data = no;
            newn->next = NULL;

            newn->next = first;
            first = newn;

            iCount++;
        }

        int pop()
        {
            struct node * temp = NULL;
            int value = 0;

            if(first == NULL)
            {
                cout<<"Unable to delete stack empty\n";
                return -1;
            }
            else
            {
                temp = first;

                first = first->next;
                value = temp->data;

                delete temp;
                iCount--;

                return value;
            }
        }

        void Display()
        {
            struct node * temp;

            if (first == NULL)
            {
                cout << "Stack is empty\n";            
            }

            temp = first;

            while (temp != NULL)
            {
                cout<<"| "<<temp->data<<" |\n";
                temp = temp->next;
            }
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    Stack obj;
    int iRet = 0;
    int choice = 0;
    int value = 0;

    cout << "\n=======================================" << endl;
    cout << "               Stack Manager          " << endl;
    cout << "=========================================\n";

    while (true)
    {
        cout << "\n-------------------------------" << endl;
        cout << "1 : Push element into stack" << endl;
        cout << "2 : Pop element from stack" << endl;
        cout << "3 : Display stack elements" << endl;
        cout << "4 : Count elements in stack" << endl;
        cout << "0 : Exit" << endl;
        cout << "-------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value to push: ";
            cin >> value;
            obj.push(value);
        }
        else if (choice == 2)
        {
            iRet = obj.pop();
            if (iRet != -1)
            {
                cout << "Popped element: " << iRet << "\n";
            }
        }
        else if (choice == 3)
        {
            obj.Display();
        }
        else if (choice == 4)
        {
            iRet = obj.Count();
            cout << "Number of elements: " << iRet << "\n";
        }
        else if (choice == 0)
        {
            cout << "Exiting application...\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}