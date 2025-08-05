
class node:

    def __init__(self, no):
        self.data = no
        self.next = None
        self.prev = None

class DoublyLLL:

    def __init__(self):
        self.first = None
        self.iCount = 0

    
    def InsertFirst(self, no):
        newn = node(no)

        if(self.first == None):
            self.first = newn

        else:
            
            newn.next = self.first
            self.first.prev = newn
            self.first = newn

        self.iCount += 1


    def InsertLast(self, no):
        newn = node(no)

        if(self.first == None):
            self.first = newn

        else:
            temp = self.first

            while(temp.next != None):
                temp = temp.next

            temp.next = newn
            newn.prev = temp

        self.iCount += 1


    def InsertAtPos(self, no, pos):

        if((pos < 1) or (pos > self.iCount+1)):
            print("Invalid Positon")
            return
        
        if(pos == 1):
            self.InsertFirst(no)

        elif(pos == self.iCount+1):
            self.InsertLast(no)

        else:
            newn = node(no)
            temp = self.first

            for i in range(1, pos-1, 1):
                temp = temp.next

            newn.next = temp.next
            temp.next.prev = newn
            temp.next = newn
            newn.prev = temp

            self.iCount += 1

    
    def DeleteFirst(self):

        if(self.first == None):
            print("Unable to delete Linked List is empty")
            return
        
        elif(self.first.next == None):
            del self.first
            self.first = None

        else:
            
            self.first = self.first.next
            del self.first.prev
            self.first.prev = None

        self.iCount -= 1


    def DeleteLast(self):

        if(self.first == None):
            print("Unable to delete Linked List is empty")
            return
        
        elif(self.first.next == None):
            del self.first
            self.first = None

        else:
            temp = self.first
            
            while(temp.next != None):
                temp = temp.next

            temp.prev.next = None
            del temp

        self.iCount -= 1


    def DeleteAtPos(self, pos):

        if((pos < 1) or (pos > self.iCount)):
            print("Invalid Positon")
            return
        
        if(pos == 1):
            self.DeleteFirst()

        elif(pos == self.iCount):
            self.DeleteLast()

        else:
            temp = self.first

            for i in range(1, pos-1, 1):
                temp = temp.next

            target = temp.next

            temp.next = target.next
            temp.next.prev = temp
            del target

            self.iCount -= 1


    def Display(self):

        if(self.first == None):
            print("Linked List is Empty")
            return

        temp = self.first
        
        print("None <=>",end="")
        while(temp != None):
            print(f" | {temp.data} | <=>",end="")
            temp = temp.next

        print(" None")

    
    def Count(self):
        return self.iCount


def main():
    obj = DoublyLLL()

    print("\n=============================================================")
    print("                    Doubly Linear Linked List                 ")
    print("=============================================================")

    while True:
        print("\n-------------------------------------------------------------")
        print(" Please select an option:")
        print("-------------------------------------------------------------")
        print("1. Insert new node at first position")
        print("2. Insert new node at last position")
        print("3. Insert new node at given position")
        print("4. Delete the node at first position")
        print("5. Delete the node at last position")
        print("6. Delete the node at given position")
        print("7. Display all elements of LinkedList")
        print("8. Count all elements of LinkedList")
        print("0. Terminate the application")
        print("-------------------------------------------------------------")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            no = int(input("Enter the data you want to insert : "))
            obj.InsertFirst(no)

        elif choice == 2:
            no = int(input("Enter the data you want to insert : "))
            obj.InsertLast(no)

        elif choice == 3:
            no = int(input("Enter the data you want to insert : "))
            pos = int(input("Enter the position at which you want to insert new node : "))
            obj.InsertAtPos(no, pos)

        elif choice == 4:
            print("Deleting the first element form LinkedList")

            obj.DeleteFirst()

        elif choice == 5:
            print("Deleting the last element form LinkedList")

            obj.DeleteLast()

        elif choice == 6:
            print("Deleting the element from given position form Linked List")

            pos = int(input("Enter the position at which you want to delete the node : "))
            obj.DeleteAtPos(pos)

        elif choice == 7:
            print("Elements of the Linked List are : ")

            obj.Display()

        elif choice == 8:
            print(f"Number of elements in the Linked List are : {obj.Count()}")

        elif choice == 0:
            print("Thank you for using our application")
            break

        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()