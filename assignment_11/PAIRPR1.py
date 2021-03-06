import math
def prime(n):
    if n == 2:
        return True
    if n == 3:
        return True
    if n%2 == 0:
        return False
    for i in range(3, math.floor(math.sqrt(n))+1, 2):
        if n%i == 0:
            return False
    return True
    
t = int(input())
for i in range(t):
    n = int(input())
    boolean = True
    for j in range(2, n//2 + 1):
        if prime(j) and prime(n-j):
            print(j, n-j)
            boolean = False
            break
    if boolean:    
        print(-1, -1)
            