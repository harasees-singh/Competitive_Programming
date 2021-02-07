'''A number N is called good if the sum of the factors less than N is equal to the number N.
You're given a number N, now check if the number N is good or not. Print "YES"(without quotes)
if it's a good number, otherwise print "NO" (without quotes).'''
import math
N = int(input())

sum = 0
if N==1 or N==3:
    print("YES")
    exit(0)


for i in range(2, math.ceil(math.sqrt(N))):
    if N%i==0 and i!=N/i:
        sum +=i
        sum +=N/i
    elif i == N/i:
        sum +=i
        
#else:
#    for i in range(2, N//2+1):
#        if N%i==0:
#            sum +=i
            
    

if sum+1==N:
    print("YES")
else:
    print("NO")