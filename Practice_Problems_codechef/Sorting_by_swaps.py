# do minimum number of adjacent swaps to sort a list 
# print the minimum swap count
ans = 0   
def Merge(left, right):
    global ans
    i, j = 0, 0
    ans_to_be_returned = []
    while i < len(left) and j < len(right):
        if left[i]<right[j]:
            ans_to_be_returned.append(left[i])
            i += 1 
        else:
            ans_to_be_returned.append(right[j])
            j += 1
            ans += len(left) - i 
    if i == len(left):
        ans_to_be_returned = ans_to_be_returned + right[j:]
    else:
        ans_to_be_returned = ans_to_be_returned + left[i:]
    return ans_to_be_returned
         
# bubble and insertion sort both are giving TLE need something better
def MergeSortCustom(arr, l, r):
    if l == r:
        return [arr[l]]
    mid = (l+r)//2
    left = MergeSortCustom(arr, l, mid)
    right = MergeSortCustom(arr, mid + 1, r)
    final_ = Merge(left, right)
    return final_
    
for _ in range(int(input())):
    ans = 0
    n = int(input())
    li = list(map(int, input().split()))
    MergeSortCustom(li, 0, len(li) - 1)
    print(ans)