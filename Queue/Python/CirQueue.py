
class node:

    def __init__(self, no):
        self.data = no
        self.next = None

class CirQueue:

    def __init__(self):
        self.first = None
        self.last = None
        self.iCount = 0

    def enqueue(self, no):

        newn = node(no)

        if(self.first == None and self.last == None):
            self.first = newn
            self.last = newn

            self.last.next = self.first

        else:
            self.last.next = newn
            self.last = newn

            self.last.next = self.first

        self.iCount += 1

    def dequeue(self):

        if(self.first == None and self.last == None):
            print("Unable to delete Queue is empty")
            return None

        elif(self.first == self.last):
            iValue = self.first.data

            del self.first

            self.first = None
            self.last = None

        else:
            temp = self.first
            iValue = temp.data

            self.first = self.first.next
            self.last.next = self.first
            del temp

        self.iCount -= 1
        return iValue

    def Display(self):

        if(self.first == None and self.last == None):
            print("Queue is empty")
            return

        temp = self.first

        while(True):
            print(f" | {temp.data} | ->",end="")
            temp = temp.next

            if(temp == self.last.next):
                break

    def Count(self):
        return self.iCount

def main():

    obj = CirQueue()

    print("=============================================================");
    print("                       Circular Queue Manager                    ");
    print("=============================================================");

    while True:
        print("\n-------------------------------------------------------------")
        print("Please select an operation:")
        print("-------------------------------------------------------------")
        print(" 1 : Enqueue at rear")
        print(" 2 : Dequeue from front")
        print(" 3 : Display from front to rear")
        print(" 4 : Count total elements")
        print(" 0 : Exit")
        print("-------------------------------------------------------------")

        choice = int(input("Enter your choice : "))

        if choice == 1:
            value = int(input("Enter element to enqueue at rear: "))
            obj.enqueue(value)

        elif choice == 2:
            iRet = obj.dequeue()
            if iRet is not None:
                print(f"Dequeued from front: {iRet}")

        elif choice == 3:
            obj.Display()

        elif choice == 4:
            print(f"Total elements in Queue: {obj.Count()}")

        elif choice == 0:
            print("Thank you for using our Application!")
            break

        else:
            print("Invalid choice, please try again")


if __name__ == "__main__":
    main()