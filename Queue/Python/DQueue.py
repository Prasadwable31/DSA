
class node:

    def __init__(self, no):
        self.data = no
        self.next = None
        self.prev = None

class DQueue:

    def __init__(self):
        self.first = None
        self.last = None
        self.iCount = 0

    def enqueuefirst(self, no):

        newn = node(no)

        if(self.first == None and self.last == None):
            self.first = newn
            self.last = newn

        else:
            newn.next = self.first
            self.first.prev = newn
            self.first = newn

        self.iCount += 1


    def enqueuelast(self, no):

        newn = node(no)

        if(self.first == None and self.last == None):
            self.first = newn
            self.last = newn

        else:
            self.last.next = newn
            newn.prev = self.last

            self.last = newn

        self.iCount += 1


    def dequeuefirst(self):

        if(self.first == None and self.last == None):
            print("Unable to delete Queue is empty")
            return None

        elif(self.first == self.last):
            iValue = self.first.data
            
            del self.first

            self.first = None
            self.last = None
    
        else:
            iValue = self.first.data

            self.first = self.first.next
            del self.first.prev
            self.first.prev = None

        self.iCount -= 1
        return iValue

    def dequeuelast(self):

        if(self.first == None and self.last == None):
            print("Unable to delete Queue is empty")
            return None

        elif(self.first == self.last):
            iValue = self.last.data
            
            del self.last

            self.first = None
            self.last = None
    
        else:
            iValue = self.last.data

            self.last = self.last.prev
            del self.last.next
            self.last.next = None

        self.iCount -= 1
        return iValue

    def Displayfirst(self):

        if(self.first == None and self.last == None):
            print("Queue is empty")
            return

        temp = self.first

        print("None <=> ",end="")

        while(temp != None):
            print(f"| {temp.data} | <=> ",end="");
            temp = temp.next

        print("None")


    def Displaylast(self):

        if(self.first == None and self.last == None):
            print("Queue is empty")
            return

        temp = self.last

        print("None <=> ",end="")

        while(temp != None):
            print(f"| {temp.data} | <=> ",end="");
            temp = temp.prev

        print("None")

    
    def Count(self):
        return self.iCount


def main():

    obj = DQueue()

    print("\n=============================================================");
    print("              Doubly Ended Queue (Deque) Manager                    ");
    print("=============================================================");

    while True:
        print("\n-------------------------------------------------------------")
        print("Please select an operation:")
        print("-------------------------------------------------------------")
        print(" 1 : Enqueue at front");
        print(" 2 : Enqueue at rear");
        print(" 3 : Dequeue from front");
        print(" 4 : Dequeue from rear");
        print(" 5 : Display from front to rear");
        print(" 6 : Display from rear to front");
        print(" 7 : Count total elements");
        print(" 0 : Exit");
        print("-------------------------------------------------------------")

        choice = int(input("Enter your choice : "))

        if choice == 1:
            value = int(input("Enter element to enqueue at front: "))
            obj.enqueuefirst(value)

        elif choice == 2:
            value = int(input("Enter element to enqueue at rear: "))
            obj.enqueuelast(value)

        elif choice == 3:
            iRet = obj.dequeuefirst()
            if iRet is not None:
                print(f"Dequeued from front: {iRet}")

        elif choice == 4:
            iRet = obj.dequeuelast()
            if iRet is not None:
                print(f"Dequeued from rear: {iRet}")

        elif choice == 5:
            obj.Displayfirst()

        elif choice == 6:
            obj.Displaylast()
        
        elif choice == 7:
            print(f"Total elements in Dqueue: {obj.Count()}")

        elif choice == 0:
            print("Thank you for using our Application!")
            break

        else:
            print("Invalid choice, please try again")

if __name__ == "__main__":
    main()