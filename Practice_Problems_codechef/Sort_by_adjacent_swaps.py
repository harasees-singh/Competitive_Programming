def BubbleSortCustom(li):
    swaps = []

    for i in range(len(li)-1):
        swapped = False
        for j in range(len(li)-1-i):
            if li[j]>li[j+1]:
                li[j], li[j+1] = li[j+1], li[j]
                swapped = True
                swaps.append(j)
                
        if not swapped:
            return swaps

    return swaps


def InsertionSortCustom(li):

    swap_count = []
    for j in range(len(li)):
        key = li[j]
        i = j
        while i>=1 and key < li[i-1]:
            li[i] = li[i-1]
            swap_count.append(i-1)
            i -= 1
        li[i] = key
    return swap_count
    

# bubble sort taking 4.3 sec and insertion sort taking 0.3 sec



n = int(input())

li = list(map(int, input().split()))

swaps = InsertionSortCustom(li)

print(len(swaps))
for i in range(len(swaps)):
    print(swaps[i], end = ' ')