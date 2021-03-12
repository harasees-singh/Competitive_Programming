'''
3
2 2 3
6 3 3
'''

n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
tuples = [(A[i], B[i]) for i in range(n)]
tuples.sort(key = lambda x:x[1], reverse = True)                                # sort according to the second element in the tuple

i = 0
while i < n-1:  
    count = 0
    j = i
    while j < n-1:
        if tuples[j][1] == tuples[j+1][1]:                                      # if 2 tuples have the same first element
            count += 1
            j += 1 
        else:
            break
    if count != 0:
        tuples[(i):(j+1)] = sorted(tuples[(i):(j+1)], key = lambda x:x[0])      # slice the list such that the sliced part has all the second elements same, 
                                                                                # then return a sorted slice (sorted according to the first element) and fit it in the sliced part

    i = j+1
    
for j in range(n):
    print(tuples[j][0], tuples[j][1], end = ' ')
    
    