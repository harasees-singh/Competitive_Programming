import random
 
def lessthan(x, y):
    return x < y
 
def quick_sort(arr, l, r):
    if r <= l:
        return
    # select a pivot uniformly randomly from [l, r]
    pivot_index = arr.index(max(arr))
    pivot_index = random.randint(l, r)
    pivot = arr[pivot_index]
 
    # partition_index = first index that is greater than or equal to pivot among the integers read so far
    partition_index = l
    arr[r], arr[pivot_index] = arr[pivot_index], arr[r]
    for index in range(l, r+1):
        if lessthan(arr[index], pivot):
            # swap arr[index] to the beginning of the array
            arr[index], arr[partition_index] = arr[partition_index], arr[index]
 
            # increase partition size, more number of elements less than pivot found
            partition_index += 1
 
    arr[partition_index], arr[r] = arr[r], arr[partition_index]
    quick_sort(arr, l, partition_index - 1)
    quick_sort(arr, partition_index+1, r)
 
# using the function
i = int(input())

for j in range(i):                      # if all the elements are the same the list will always be shortened by 1 unit and we will hit worst case each time 
    print(f'{10} ', end='')