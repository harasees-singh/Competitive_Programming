import math

N = 10**6 +5
res = [0 for _ in range(N)]

def sieve():
    v = [0 for _ in range(N)]
    prime = [True for _ in range(N)]

    for p in range(2, math.floor(math.sqrt(N))):

        if prime[p] == True:
            for i in range(p*p, N, p):
                prime[i] = False

    for p in range(N):
        if prime[p]:
            v.append(p)

    count = 0
    j=0
    for i in range(N):
        if v[j]<=i:
            count+=1
            j+=1
        res[i] = count


sieve()
t = int(input())
while(t):
    x, y = map(int, input().split())

    if res[x]<=y:
        print("Chef")
    
    else:
        print("Divyam")
    t-=1