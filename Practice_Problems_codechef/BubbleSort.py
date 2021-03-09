n = int(input())
l = list(map(int, input().split()))


def BubbleSort(l):
    for j in range(len(l)):
        swaps = False
        for i in range (len(l) - j - 1):
            if l[i] > l[i+1]:
                l[i], l[i+1] = l[i+1], l[i]
                swaps = True
        if swaps == False:
            return l
        else:
            for i in range(len(l)):
                print(l[i], end= " ")
            print()
				
	
BubbleSort(l)

	
	