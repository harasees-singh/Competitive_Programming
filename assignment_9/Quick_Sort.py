import sys
sys.setrecursionlimit(10**4)

def merge(a, b):
    n = len(a)
    m = len(b)

    ouput = [0]*(n+m)

    i, j, k = 0, 0, 0
    while i<n and j<m:

        if a[i]<b[j]:
            ouput[k] = a[i]
            i+=1
            k+=1
        
        else:
            ouput[k] = b[j]
            j+=1
            k+=1

    while(j<m):         # if i was exhausted
        ouput[k] = b[j]
        j+=1
        k+=1
    
    while(i<n):         # if j was exhausted
        ouput[k] = a[i]
        i+=1
        k+=1
    
    return ouput


# space complexity: O(n+m)
# time complexity: O(n+m)


# merge sort says if you have an unsorted list 
# divide your list into 2 equal halves 
# sort the left half recursively 
# sort the right half recursively



def merge_sort(arr, left, right):

    if left == right:
        # base case
        return [arr[left]] # or return [arr[right]]

    mid = (left+right)//2

    left_half = merge_sort(arr, left, mid)
    right_half = merge_sort(arr, mid+1, right)
    ouput = merge(left_half, right_half)
    return ouput

from random import randrange
def partition(li, left, right):
    '''p is the position of the pivot'''
    p = randrange(left, right)
    i = left
    pivot = li[p]
    li[p], li[right] = li[right], li[p]         # place the position to the far right so that it does not get swapped in between
    for j in range(left, right+1):
        #print(j, p)
        if li[j]<pivot:
            
            li[i], li[j] = li[j], li[i]
            i+=1
    
    li[right], li[i] = li[i], li[right]         # swap the pivot with li[i] so that it belongs where it should
    
    return i        # i will be the final pivot index

def QuickSort(li, left, right):
    if left>=right:
        return 
    
    pivot_index = partition(li, left, right)

    QuickSort(li, left, pivot_index-1)
    QuickSort(li, pivot_index+1, right)
    
    return
for i in range(int(input())):
    n = int(input())
    temp = list(map(int, input().split()))
    '''QuickSort(temp, 0, n-1)'''       # TLE
    temp = merge_sort(temp, 0, n-1)
    #temp.sort()
    for p in range(len(temp)):
        print(temp[p], end=" ")
    print()

# sample = [3,7,6,4,8,2]
# QuickSort(sample, 0, len(sample)-1)     # passing the left and the right indices
# print(sample)