# do minimum number of adjacent swaps to sort a list 
# print the minimum swap count

def BubbleSortCustom(li):
    swaps = 0

    for i in range(len(li)-1):
        swapped = False
        for j in range(len(li)-1-i):
            if li[j]>li[j+1]:
                li[j], li[j+1] = li[j+1], li[j]
                swapped = True
                swaps += 1
                
        if not swapped:
            return swaps

    return swaps

def insertion_sort(arr):
	for i in range(1, len(arr)):
		key = arr[i] # this element will be now inserted at it's correct position
		j = i - 1 # because the right place of insertion will be on left
		while j >= 0 and key < arr[j]:
			arr[j+1] = arr[j]
			j -= 1
		arr[j+1] = key
		
	return

def InsertionSortCustom(li):

    swap_count = 0
    for j in range(len(li)):
        key = li[j]
        i = j
        while i>=1 and key < li[i-1]:
            li[i] = li[i-1]
            swap_count += 1
            i -= 1
        li[i] = key
    return swap_count
    

# bubble and insertion sort both are giving TLE need something better


for _ in range(int(input())):
    n = int(input())
    li = list(map(int, input().split()))
    
    swaps = InsertionSortCustom(li)
    #print()
    #insertion_sort(li)
    #print(li)
    
    print(swaps)