import random
import time

def generate_random_array(length, min_val=0, max_val=100):
    return [random.randint(min_val, max_val-1) for _ in range(length)]



def bubble_sort(arr):
    #m = 0 # copy amount
    #c = 0 # comparison amount
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]: 
                arr[j], arr[j+1] = arr[j+1], arr[j]
                #m += 1
            #c += 1

    return arr
    #return m, c




arr = generate_random_array(100)

print(arr)

print(bubble_sort(arr))

# avarage c and m calculation
"""
all_m, all_c = 0, 0
for i in range(0, 100):
    arr = generate_random_array(100)
    m, c = bubble_sort(arr)
    all_m += m
    all_c += c
    
all_m /= 100
all_c /= 100

print(f"avarage m - {all_m}\navarabe c - {all_c}")"""


#time calculation
"""
arr = generate_random_array(10000)
st = time.time()
bubble_sort(arr)
et = time.time()

elapsed_time = et - st
print('Execution time:', elapsed_time, 'seconds')"""