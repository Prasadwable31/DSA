import java.util.*;

class node
{
    public int data;
    public int prio;
    public node next;
    public node prev;
}

class PriQueueX
{
    private node first;
    private node last;
    private int iCount;
    
    public PriQueueX()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void enqueue(int no, int pri)
    {
        node newn = null;

        newn = new node();
        newn.data = no;
        newn.prio = pri;
        newn.next = null;
        newn.prev = null;

        if((first == null) && (last == null))
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            newn.prev = last;

            last = newn;
        }
        
        iCount++;
    }

    public int dequeue()
    {
        node temp = null;
        node iMax = null;

        if((first == null) && (last == null))
        {
            System.out.println("Unable to delete Queue is empty");
            return -1;
        }
        else if(first == last)
        {
            iMax = first;

            first = null;
            last =  null;
        }
        else
        {
            temp = first;
            iMax = first;

            while(temp != null)
            {
                if(iMax.prio < temp.prio)
                {
                    iMax = temp;
                }

                temp = temp.next;
            }

            if(iMax == first)
            {
                first = first.next;
            
                first.prev = null;
            }
            else if(iMax == last)
            {
                last = last.prev;

                last.next = null;
            }
            else
            {
                iMax.next.prev = iMax.prev;
                iMax.prev.next = iMax.next;
            }
        }

        iCount--;
        return iMax.data;
    }

    public void Display()
    {
        node temp = null;

        if((first == null) && (last == null))
        {
            System.out.println("Queue is empty");
            return;
        }

        temp = first;

        System.out.println("Data | Priority");
        while(temp != null)
        {
            System.out.print(" | "+temp.data+" | "+temp.prio+" | - ");
            temp = temp.next;
        }

        System.out.println("null");
    }

    public int Count()
    {
        return iCount;
    }
}

class PriQueue 
{
    public static void main(String[] args) 
    {
        PriQueueX obj = new PriQueueX();
        Scanner sc = new Scanner(System.in);

        int choice = 0;
        int value = 0;
        int prio = 0;

        System.out.println("\n=============================================================");
        System.out.println("                   Priority Queue Manager                     ");
        System.out.println("=============================================================");

        while (true)
        {
            System.out.println("\n-------------------------------------------------------------");
            System.out.println("Please select an operation:");
            System.out.println("-------------------------------------------------------------");
            System.out.println(" 1 : Enqueue (Enter data with priority)");
            System.out.println(" 2 : Dequeue (Remove element with highest priority)");
            System.out.println(" 3 : Display queue elements");
            System.out.println(" 4 : Count total elements");
            System.out.println(" 0 : Exit");
            System.out.println("-------------------------------------------------------------");

            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            if(choice == 1)
            {
                System.out.print("Enter element to enqueue: ");
                value = sc.nextInt();

                System.out.print("Enter priority of the element: ");
                prio = sc.nextInt();

                obj.enqueue(value, prio);
            }
            else if(choice == 2)
            {
                value = obj.dequeue();
                if(value != -1)
                {
                    System.out.println("Dequeued element with highest priority: " + value);
                }
            }
            else if(choice == 3)
            {
                obj.Display();
            }
            else if(choice == 4)
            {
                System.out.println("Total elements in priority queue: " + obj.Count());
            }
            else if(choice == 0)
            {
                System.out.println("Thank you for using the Priority Queue Manager!");
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