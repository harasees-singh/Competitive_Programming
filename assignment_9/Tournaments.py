'''
4
1 3 2 3
'''

# will use merge sort

count = 0   # number of non profitable matches

def merge(a, b):
    non_profitable = False

    global count
    n = len(a)
    m = len(b)

    ouput = [0]*(n+m)

    i, j, k = 0, 0, 0
    while i<n and j<m:

        if a[i] == b[j]:
            non_profitable = True           # if you find 2 elements same just increment the count which will reflect the fact that this match won't be porfitable

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
    
    if non_profitable:
        count += 1
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


n = int(input())
li = list(map(int, input().split()))
merge_sort(li, 0, n-1)

print(n-1-count)