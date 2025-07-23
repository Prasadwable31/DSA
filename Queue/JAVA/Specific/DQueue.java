import java.util.*;

class node
{
    public int data;
    public node next;
    public node prev;
}

class DQueueX
{
    private node first;
    private node last;
    private int iCount;

    public DQueueX()
    {
        this.first = null;;
        this.last = null;
        this.iCount = 0;
    }

    public void enqueuefirst(int no)
    {
        node newn = null;

        newn = new node();
        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if((first == null) && (last == null))
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;

            first = newn;
        }

        iCount++;
    }

    public void enqueuelast(int no)
    {
        node newn = null;

        newn = new node();
        newn.data = no;
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

    public int dequeuefirst()
    {  
        int value = 0;

        if((first == null) && (last == null))
        {
            System.out.println("Unable to delete Queue is empty");
            return -1;
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
            first.prev = null;
        }

        iCount--;
        return value;
    }

    public int dequeuelast()
    {  
        int value = 0;

        if((first == null) && (last == null))
        {
            System.out.println("Unable to delete Queue is empty");
            return -1;
        }
        else if(first == last) 
        {
            value = last.data;

            first = null;
            last = null;
        }
        else
        {
            value = last.data;

            last = last.prev;
            last.next = null;
        }

        iCount--;
        return value;
    }

    public void DisplayFirst()
    {
        node temp = null;

        if((first == null) && (last == null))
        {
            System.out.println("Queue is empty");
            return;
        }

        temp = first;

        System.out.println("Deque (Front to Rear): ");
        System.out.print(" - ");
        while (temp != null) 
        {
            System.out.print("| "+temp.data+" | - ");
            temp = temp.next;    
        }

        System.out.println();
    }

    public void DisplayLast()
    {
        node temp = null;

        if((first == null) && (last == null))
        {
            System.out.println("Queue is empty");
            return;
        }

        temp = last;

        System.out.println("Deque (Rear to Front): ");
        System.out.print(" = ");
        while (temp != null) 
        {
            System.out.print("| "+temp.data+" | = ");
            temp = temp.prev;    
        }

        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }
}

class DQueue 
{
    public static void main(String A[]) 
    {
        DQueueX obj = new DQueueX();

        Scanner sc = new Scanner(System.in);
        int choice = 0;
        int value = 0;

        System.out.println("\n=============================================================");
        System.out.println("               Doubly Ended Queue (Deque) Manager             ");
        System.out.println("=============================================================");

        while (true) 
        {
            System.out.println("\n-------------------------------------------------------------");
            System.out.println("Please select an operation:");
            System.out.println("-------------------------------------------------------------");
            System.out.println(" 1 : Enqueue at front");
            System.out.println(" 2 : Enqueue at rear");
            System.out.println(" 3 : Dequeue from front");
            System.out.println(" 4 : Dequeue from rear");
            System.out.println(" 5 : Display from front to rear");
            System.out.println(" 6 : Display from rear to front");
            System.out.println(" 7 : Count total elements");
            System.out.println(" 0 : Exit");
            System.out.println("-------------------------------------------------------------");
            
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            if (choice == 1) 
            {
                System.out.print("Enter element to enqueue at front: ");
                value = sc.nextInt();

                obj.enqueuefirst(value);
            } 
            else if (choice == 2) 
            {
                System.out.print("Enter element to enqueue at rear: ");
                value = sc.nextInt();
                
                obj.enqueuelast(value);
            }
            else if (choice == 3) 
            {
                value = obj.dequeuefirst();
                
                System.out.println("Dequeued from front: " + value);
            } 
            else if (choice == 4) 
            {
                value = obj.dequeuelast();

                System.out.println("Dequeued from rear: " + value);
            } 
            else if (choice == 5) 
            {
                obj.DisplayFirst();
            } 
            else if (choice == 6) 
            {
                obj.DisplayLast();
            } 
            else if (choice == 7) 
            {
                System.out.println("Total elements in deque: " + obj.Count());
            } 
            else if (choice == 0) 
            {
                System.out.println("Thank you for using the Deque Manager!");
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