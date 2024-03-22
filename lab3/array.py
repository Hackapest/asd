import random
import string


class DoublyLinkedList:
    def __init__(self):
        self.array = []
    
    def insert_at_start(self, data):
        self.array.insert(0, data)
    
    def insert_at_end(self, data):
        self.array.append(data)
    
    def pop_element(self, index):
        if index < len(self.array):
            return self.array.pop(index)
        else:
            print("Element not found in the array.")

    def insert_after_index(self, index, data):
        if index < len(self.array):
            self.array.insert(index + 1, data)
        else:
            print("Index out of range.")
    
    def insert_before_index(self, index, data):
        if index < len(self.array):
            self.array.insert(index, data)
        else:
            print("Index out of range.")

    def print_arr(self):
        for i in self.array:
            print(i)

    def lab_task(self, letter):
        for i in range(0, len(self.array)):            
            if self.array[i][0] == letter:
                self.array[i] = self.array[i].capitalize()
            if len(self.array[i]) % 2 == 1:
                self.array[i] += ("!")

    def personalised_task(self):
        if 2 < len(self.array):
            self.array[2] = self.array[-1]

def generate_random_string():
    length = random.randint(4, 10)
    random_string = ''.join(random.choice(string.ascii_letters) for _ in range(length))
    return random_string


def main():
    my_list = DoublyLinkedList()

    my_list.insert_at_start(generate_random_string())
    my_list.insert_at_start(generate_random_string())
    my_list.insert_at_start(generate_random_string())
    my_list.insert_at_start("aasldkfj")
    my_list.insert_at_start("aasasdf")
    my_list.insert_at_start("aaserg")

    my_list.lab_task("a")

    my_list.print_arr()
    print(50*"_")

    my_list.insert_before_index(3, "test")

    my_list.print_arr()
    print(50*"_")

    my_list.pop_element(0)

    my_list.print_arr()
    print(50*"_")

    my_list.personalised_task()

    my_list.print_arr()
    print(50*"_")



main()