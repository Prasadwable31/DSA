import java.util.*;

class node<T>
{
    public T data;
    public node<T> next;
}

class CirQueueX<T>
{
    private node<T> first;
    private node<T> last;
    private int iCount;

    public CirQueueX()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void enqueue(T no)
    {
        node<T> newn = null;

        newn = new node<T>();
        newn.data = no;
        newn.next = null;

        if((first == null) && (last == null))
        {
            first = newn;
            last = newn;

            last.next = first;
        }
        else
        {
            last.next = newn;
            last = newn;

            last.next = first;
        }

        iCount++;
    }

    public T dequeue()
    {
        T value;

        if((first == null) && (last == null))
        {
            System.out.println("Unable to delete Queue is empty");
            return null;
        }
        else if(first == last)
        {
            value = first.data;

            first = null;
            last = null;
        }
        else
        {
            value = first.data;

            first = first.next;
            last.next = first;
        }

        iCount--;
        return value;
    }

    public void Display()
    {
        node<T> temp = null;

        if((first == null) && (last == null))
        {
            return;
        }

        temp = first;
        
        do
        {
            System.out.print(" | "+temp.data+" | - ");
            temp = temp.next;
        }while(temp != last.next);

        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }
}

class CirQueue 
{
    public static void main(String[] args) 
    {
        CirQueueX<Integer> obj = new CirQueueX<Integer>();
        Scanner sc = new Scanner(System.in);

        int choice = 0;
        int value = 0;

        System.out.println("\n=============================================================");
        System.out.println("                    Circular Queue Manager                    ");
        System.out.println("=============================================================");

        while (true)
        {
            System.out.println("\n-------------------------------------------------------------");
            System.out.println("Please select an operation:");
            System.out.println("-------------------------------------------------------------");
            System.out.println(" 1 : Enqueue at rear");
            System.out.println(" 2 : Dequeue from front");
            System.out.println(" 3 : Display from front to rear");
            System.out.println(" 4 : Count total elements");
            System.out.println(" 0 : Exit");
            System.out.println("-------------------------------------------------------------");

            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            if(choice == 1)
            {
                System.out.print("Enter element to enqueue at rear: ");
                value = sc.nextInt();
                obj.enqueue(value);
            }
            else if(choice == 2)
            {
                value = obj.dequeue();
                System.out.println("Dequeued from front: " + value);
            }
            else if(choice == 3)
            {
                obj.Display();
            }
            else if(choice == 4)
            {
                System.out.println("Total elements in deque: " + obj.Count());
            }
            else if(choice == 0)
            {
                System.out.println("Thank you for using our Application!");
                break;
            }
            else
            {
                System.out.println("Invalid choice. Please try again.");
            }
        }

        sc.close();
    }
}