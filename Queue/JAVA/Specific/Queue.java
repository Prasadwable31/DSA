import java.util.*;

class node
{
    public int data;
    public node next;
}

class QueueX
{
    private node first;
    private int iCount;

    public QueueX()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void enqueue(int no)
    {
        node newn = null;
        node temp = null;

        newn = new node();
        newn.data = no;
        newn.next = null;
        
        if (first == null) 
        {
            first = newn; 
        }
        else
        {
            temp = first;

            while (temp.next != null) 
            {
                temp = temp.next;    
            }

            temp.next = newn;
        }

        iCount++;
    }

    public int dequeue()
    {
        node temp = null;

        if(first == null)
        {
            System.out.println("Unable to delete Queue is empty");
            return -1;
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
        node temp = null;

        if(first == null) 
        {
            System.out.println("Queue is empty\n");
            return;
        }

        temp = first;

        while(temp != null) 
        {
            System.out.print("| "+temp.data+" | - ");
            temp = temp.next;    
        }

        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }
}

class Queue
{
    public static void main(String[] args) 
    {
        QueueX obj = new QueueX();
        Scanner sc = new Scanner(System.in);

        int choice = 0;
        int value = 0;

        System.out.println("\n=============================================================");
        System.out.println("                       Simple Queue Manager                    ");
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
                System.out.println("Total elements in queue: " + obj.Count());
            }
            else if(choice == 0)
            {
                System.out.println("Thank you for using the Queue Manager!");
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