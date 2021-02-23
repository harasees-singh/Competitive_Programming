def BubbleSortCustom(li):
    swaps = 0
    
    indices_swapped = str()
    for i in range(len(li)-1):
        swapped = False
        for j in range(len(li)-1-i):
            if li[j]>li[j+1]:
                li[j], li[j+1] = li[j+1], li[j]
                swapped = True
                swaps += 1
                indices_swapped += f' {j}'
        if not swapped:
            return swaps, indices_swapped
    
    return swaps, indices_swapped


n = int(input())
li = list(map(int, input().split()))

swaps, indices_swapped = BubbleSortCustom(li)

print(swaps)
print(indices_swapped[1:])      # don't want to print the starting space though xd

