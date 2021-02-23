def SelectionSortCustom(li):
    number_of_swaps = 0
    swaps = []
    for i in range(len(li)):
        min = i
        for j in range(i+1, len(li)):
            if li[j] < li[min]:
                min = j
        if min!=i:
            li[min], li[i] = li[i], li[min]
            number_of_swaps += 1
            swaps.append((f'{i} {min}'))
    
    return li, number_of_swaps, swaps
    
#li = [1,2,1,6,4,64,2,4,5,7,3,4]
n = int(input())
li = list(map(int, input().split()))
new_list, number_of_swaps, swaps =  SelectionSortCustom(li)
print(number_of_swaps)

for itera in range(len(swaps)):
    print(swaps[itera])
       




