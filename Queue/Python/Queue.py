
class node:

    def __init__(self, no):
        self.data = no
        self.next = None

class Queue:

    def __init__(self):
        self.first = None
        self.iCount = 0

    def enqueue(self, no):

        newn = node(no)

        if(self.first == None):
            self.first = newn

        else:
            temp = self.first

            while(temp.next != None):
                temp = temp.next

            temp.next = newn

        self.iCount += 1

    def dequeue(self):

        if(self.first == None):
            print("Unable to delete Queue is empty")

        else:
            temp = self.first
            iValue = temp.data

            self.first = self.first.next
            
            del temp

            self.iCount -= 1
            return iValue

    def Display(self):

        if(self.first == None):
            print("Queue is empty")
            return

        temp = self.first

        while(temp != None):
            print(f"| {temp.data} | -> ",end="");
            temp = temp.next

        print("None")

    def Count(self):
        return self.iCount

def main():

    obj = Queue()

    print("\n=============================================================");
    print("                       Simple Queue Manager                    ");
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