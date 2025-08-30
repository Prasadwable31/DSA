
class node:
    def __init__(self, no, pri):
        self.data = no
        self.prio = pri
        self.next = None
        self.prev = None

class PriQueue:

    def __init__(self):
        self.first = None
        self.last = None
        self.iCount = 0

    def enqueue(self, no, pri):
        newn = node(no, pri)

        if(self.first == None and self.last == None):

            self.first = newn
            self.last = newn

        else:

            self.last.next = newn
            newn.prev = self.last

            self.last = newn

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
            iMax = self.first
            temp = self.first

            while(temp != None):
                if(iMax.prio < temp.prio):
                    iMax = temp

                temp = temp.next

            iValue = iMax.data

            if(iMax == self.first):
                self.first = self.first.next
                self.first.prev = None

            elif(iMax == self.last):
                self.last = self.last.prev
                self.last.next = None

            else:
                iMax.next.prev = iMax.prev
                iMax.prev.next = iMax.next

            del iMax

        self.iCount -= 1
        return iValue


    def Display(self):

        if(self.first == None):
            print("Queue is empty")
            return

        temp = self.first

        print("None <=> ",end="")

        while(temp != None):
            print(f"| {temp.data} | {temp.prio} | <=> ",end="");
            temp = temp.next

        print("None")


    def Count(self):
        return self.iCount


def main():
    obj = PriQueue()

    print("\n=============================================================");
    print("                     Priority Queue Manager                    ");
    print("=============================================================");

    while True:
        print("\n-------------------------------------------------------------")
        print("Please select an operation:")
        print("-------------------------------------------------------------")
        print(" 1 : Enqueue (Enter data with priority)")
        print(" 2 : Dequeue (Remove element with highest priority)")
        print(" 3 : Display queue elements")
        print(" 4 : Count total elements")
        print(" 0 : Exit")
        print("-------------------------------------------------------------")

        choice = int(input("Enter your choice : "))

        if choice == 1:
            value = int(input("Enter element to enqueue: "))
            prio = int(input("Enter priority of the element: "))
            obj.enqueue(value, prio)

        elif choice == 2:
            iRet = obj.dequeue()            # "If multiple jobs have same highest priority, the first inserted is removed first."

            if iRet is not None:
                print(f"Dequeued element with highest priority: {iRet}")

        elif choice == 3:
            obj.Display()

        elif choice == 4:
            print(f"Total elements in Priority Queue: {obj.Count()}")

        elif choice == 0:
            print("Thank you for using our Application!")
            break

        else:
            print("Invalid choice, please try again")


if __name__ == "__main__":
    main()