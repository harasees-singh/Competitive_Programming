'''
3
2 2 3
6 3 3
'''
def revese(arr):
    ans = []
    for i in range(len(arr) - 1, -1, -1):
        ans.append(arr[i])
    return ans
    
n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
tuples = [(A[i], B[i]) for i in range(n)]
tuples.sort(key = lambda x:x[1], reverse = True)

i = 0
while i < n-1:
    count = 0
    j = i
    while j < n-1:
        if tuples[j][1] == tuples[j+1][1]:
            count += 1
            j += 1 
        else:
            break
    if count != 0:
        tuples[(i):(j+1)] = sorted(tuples[(i):(j+1)], key = lambda x:x[0]) 

    i = j+1
    
for j in range(n):
    print(tuples[j][0], tuples[j][1], end = ' ')
    
    