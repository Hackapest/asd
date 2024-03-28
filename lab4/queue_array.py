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
    n = input("Input a number: ")
    for char in n:
        if not char.isdigit():
            print("Incorrect input")
            return None
    return int(n)

def get_operator():
    n = input("Input an operator: ")
    if len(n) != 1:
        print("Incorrect input")
        return None
    elif n in ['+', '-', '*', '/']:
        return n
    else:
        print("Incorrect input")
        return None

def perform_operation(operator, operand1, operand2):
    match operator:
        case '+':
            return operand1 + operand2
        case '-':
            return operand1 - operand2
        case '*':
            return operand1 * operand2
        case '/':
            if operand2 != 0:
                return operand1 / operand2
            else:
                print("Division by zero")
                return None
        case _:
            print("Incorrect input")
            return None

def main():
    queue = Queue()
    while True:
        if queue.size() < 2:
            n = get_number()
            if n == None:
                continue
            queue.enqueue(n)
        elif queue.size() == 2:
            operator = get_operator()
            if operator == None:
                continue
            result = perform_operation(operator, queue.dequeue(), queue.dequeue())
            if result == None:
                continue
            queue.enqueue(result)
        print(queue.items)


main()   