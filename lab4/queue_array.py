class CircularQueue():
    def __init__(self, capacity):
        self.capacity = capacity
        self.array = [None] * self.capacity  # Create an array of size 'capacity'
        self.size = 0
        self.front = 0
        self.rear = -1
    
    def is_empty(self):
        return self.size == 0

    def is_full(self):
        return self.size == self.capacity
    
    def enqueue(self, value):
        if self.is_full():
            print("Queue is full.")
            return
        
        self.rear = (self.rear + 1) % self.capacity
        self.array[self.rear] = value
        self.size += 1

    def dequeue(self):
        if self.is_empty():
            print("Queue is empty.")
            return None
        
        value = self.array[self.front]
        self.array[self.front] = None
        self.front = (self.front + 1) % self.capacity
        self.size -= 1
        return value

    def peek(self):
        if self.is_empty():
            print("Queue is empty.")
            return None
        
        return self.array[self.front]
    
    def display(self):
        if self.is_empty():
            print("Queue is empty.")
            return
        
        result = []
        for i in range(self.size):
            result.append(self.array[(self.front + i) % self.capacity])
        print(result)

def test():
    queue = CircularQueue(5)

    queue.enqueue(1)
    queue.enqueue(2)
    queue.enqueue(3)
    queue.enqueue(4)
    queue.enqueue(5)
    queue.enqueue(6)

    queue.display()

    n = queue.dequeue()
    print(n)

    queue.display()

    n = queue.dequeue()
    print(n)

    queue.display()

    queue.enqueue(5)
    queue.enqueue(5)

    n = queue.dequeue()
    print(n)

    queue.display()

if __name__ == "__main__":
    test()