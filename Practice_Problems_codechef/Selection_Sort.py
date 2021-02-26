def SelectionSort(li):
    for i in range(len(li)-1):
        j = i
        min = li[i]
        index = i
        
        for j in range(i, len(li)):
            if li[j] < min:
                min = li[j]
                index = j
                
        li[index], li[i] = li[i], li[index]
        for ele in li:
            print(ele, end = ' ')               # printing the state of the list after each iteration of the selection sort
        print()
    

n = int(input())
SelectionSort(list(map(int, input().split())))