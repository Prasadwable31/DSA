import java.util.*;

class node<T>
{
    public T data;
    public node<T> next;
}

class StackX<T>
{
    private node<T> first;
    private int iCount;

    public StackX()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void push(T no)
    {
        node<T> newn = null;

        newn = new node<T>();
        newn.data = no;
        newn.next = null;

        newn.next = first;
        first = newn;

        iCount++;
    }

    public T pop()
    {
        node<T> temp = null;

        if(first == null)
        {
            System.out.println("Unable to delete stack empty");
            return null;
        }
        else
        {
            temp = first;

            first = first.next;
            iCount--;

            return temp.data;
        }

    }

    public void Display()
    {
        node<T> temp = null;

        temp = first;

        while(temp != null)
        {
            System.out.println("| "+temp.data+" |");
            temp = temp.next;
        }
    }

    public int Count()
    {
        return iCount;
    }
}

class GenStack
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        StackX<Integer> obj = new StackX<Integer>();
        int value = 0, choice = 0;

        System.out.println("===================================================");
        System.out.println("                   Stack Manager                   ");
        System.out.println("===================================================");

        while(true)
        {
            System.out.println("\n---------------------------------------------");
            System.out.println("Stack Operations Menu");
            System.out.println("---------------------------------------------");
            System.out.println("1 : Push element");
            System.out.println("2 : Pop element");
            System.out.println("3 : Display stack");
            System.out.println("4 : Count elements");
            System.out.println("5 : Exit");
            System.out.println("---------------------------------------------");
            System.out.print("Enter your choice: ");
            choice = sobj.nextInt();

            if(choice == 1)
            {
                System.out.print("Enter element to push: ");
                value = sobj.nextInt();
                obj.push(value);
                System.out.println("Element pushed successfully.");
            }
            else if(choice == 2)
            {
                value = obj.pop();
                if(value != -1)
                {
                    System.out.println("Popped element is: " + value);
                }
            }
            else if(choice == 3)
            {
                System.out.println("Current stack:");
                obj.Display();
            }
            else if(choice == 4)
            {
                value = obj.Count();
                System.out.println("Number of elements in stack: " + value);
            }
            else if(choice == 5)
            {
                System.out.println("Thank you for using stack manager.");
                break;
            }
            else
            {
                System.out.println("Invalid choice. Please try again.");
            }
        }

        sobj.close();
    }
}