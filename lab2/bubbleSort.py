import random
import time

def generate_random_array(length, min_val=0, max_val=100):
    return [random.randint(min_val, max_val-1) for _ in range(length)]

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]




arr = generate_random_array(10)

st = time.time()


bubble_sort(arr)
print(arr)

et = time.time()

elapsed_time = et - st
print('Execution time:', elapsed_time, 'seconds')


