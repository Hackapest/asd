class Queue:
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        if not self.is_empty():
            return self.items.pop(0)
        else:
            return None

    def peek(self):
        if not self.is_empty():
            return self.items[0]
        else:
            return None

    def is_empty(self):
        return len(self.items) == 0

    def size(self):
        return len(self.items)
    
def get_number():
    n = ""
    input("Input a number: ", n)
    for char in n:
        if not char.isdigit():
            print("Incorrect input")
            return None
    return int(n)

def get_operator():
    n = ""
    input("Input an operator: ", n)
    if len(n) != 1:
        print("Incorrect input")
        return None
    elif n in ['+', '-', '*', '/']:
        return n
    else:
        print("Incorrect input")
        return None