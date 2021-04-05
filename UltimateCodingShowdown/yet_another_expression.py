# cook your dish here
import sys
sys.setrecursionlimit = 10000000
import math
 
def checkPerfectSquare(N, start, last):
    
    
    while start<=last:
        mid = int((start + last) / 2) 
        if (mid * mid == N):
            return mid
        elif (mid * mid > N):
            last = mid-1
        else:
            start = mid+1
    if (start > last): 
        return -1

t = int(input())
for _ in range(t):
    a = int(input())
    b, c = 0, 0
    
    count = 0
    for i in range(1, a+1):
        for j in range(1, a + 1):
            b, c = i, j
            if checkPerfectSquare(a+(b**(2*c)), 0, a+(b**(2*c))) != -1:
                count += 1
    print(count)