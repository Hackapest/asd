import random
import time

def generate_random_array(length, min_val=0, max_val=100):
    return [random.randint(min_val, max_val-1) for _ in range(length)]
 
def shell_sort(arr):
    n = len(arr)

    gaps = [2**i-1 for i in range(1, n + 1) if 2**i-1 <= n]
    gaps.reverse()

    #m = 0 # copy amount
    #c = 0 # comparison amount

    for gap in gaps:
        
        for i in range(gap, n):
            
            temp = arr[i]
            
            j = i

            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                #m += 1
                #c += 1
                j -= gap
            

            arr[j] = temp
            #m += 1

    return arr
    #return m, c


arr = generate_random_array(1000)
shell_sort(arr)


# avarage c and m calculation
"""
all_m, all_c = 0, 0
for i in range(0, 2):
    arr = generate_random_array(10000)
    m, c = shell_sort(arr)
    all_m += m
    all_c += c
    
all_m /= 2
all_c /= 2

print(f"avarage m - {all_m}\navarabe c - {all_c}")
"""

# time measurment
"""
arr = generate_random_array(10000)
st = time.time()

shell_sort(arr)

et = time.time()

elapsed_time = et - st
print('Execution time:', elapsed_time, 'seconds')
"""