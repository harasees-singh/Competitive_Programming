# time complexity of chef's code from line 9-12 is O(n) 
# Note: time complexity of in operator depends on the type of container and here chef used a list and therefore it will be O(n)
# for sets this will be O(1)
n = int(input())
arr = []
for i in range(0, n):
    x = int(input())
    arr.append(x)
q = int(input())

arr = set(arr)

print(1)        # chef's time complexity is O(n) because he/she is using in operator on a list

for i in range(0, q):
    x = int(input())
    if x in arr:
        print('yes')
    else:
        print('no')