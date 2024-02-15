import random


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

#print(shellSort(arr))
print(shell_sort(arr))
