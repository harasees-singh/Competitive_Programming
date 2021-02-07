''' 
The first line contains a single integer n, the number of elements of the array A.

The next n lines each contain a space separated integer, denoting elements of the array A.

'''
n = int(input())
arr = []
ans = 0
sum = 0
for i in range(0, n):
    x = int(input())
    arr.append(x)

for i in range(1, n):
    ans += arr[i]*(sum+arr[i-1])
    sum += arr[i-1]

print(2)                # time complexity of chef's code
print(ans)