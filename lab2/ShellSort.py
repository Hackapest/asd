import random
import time

def generate_random_array(length, min_val=0, max_val=100):
    return [random.randint(min_val, max_val-1) for _ in range(length)]

def shell_sort(arr):
    n = len(arr)
    gap = 1
    counter = 1

    while gap <= n:
        
        for i in range(gap, n):
            
            temp = arr[i]
            
            j = i
            
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            
            arr[j] = temp

        counter += 1
        gap = 2 ** counter - 1

    return arr


arr = generate_random_array(100)

st = time.time()

shell_sort(arr)

et = time.time()

elapsed_time = et - st
print('Execution time:', elapsed_time, 'seconds')

