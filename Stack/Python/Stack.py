
class node:
    
    def __init__(self, no):
        self.data = no
        self.next = None

class Stack:

    def __init__(self):
        self.first = None
        self.iCount = 0

    def push(self, no):

        newn = node(no)

        if(self.first == None):
            self.first = newn

        else:
            newn.next = self.first
            self.first = newn

        self.iCount += 1
        
    def pop(self):

        if(self.first == None):
            print("Unable to delete stack empty")

        else:
            temp = self.first
            self.first = self.first.next

            iValue = temp.data
            del temp

            self.iCount -= 1
            return iValue
        
    def Display(self):

        temp = self.first

        while(temp != None):
            print(f"| {temp.data} | -> ",end="")
            temp = temp.next
        
        print("None")

    def Count(self):
        return self.iCount
        

def main():

    obj = Stack()

    print("\n=================================================")
    print("           Stack Manager (Linked List)      ")
    print("=================================================")

    while True:
        print("\n-------------------------------------------")
        print("Please choose an operation : ")
        print("---------------------------------------------")
        print(" 1 : Push element onto stack")
        print(" 2 : Pop element from stack")
        print(" 3 : Display stack")
        print(" 4 : Count elements in stack")
        print(" 0 : Exit")
        print("-------------------------------------------\n")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            no = int(input("Enter number to push: "))
            obj.push(no)
            print(f"{no} pushed onto the stack.")
        
        elif choice == 2:
            iRet = obj.pop()
            if iRet != -1:
                print(f"Popped element: {iRet}")
        
        elif choice == 3:
            print("Elements of stack:")
            obj.Display()
        
        elif choice == 4:
            print(f"Number of elements in stack: {obj.Count()}")
        
        elif choice == 0:
            print("Thank you for using Stack Manager!")
            break
        
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()