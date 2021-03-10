t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    li = list(map(int, input().split()))
    li.sort()
    ans = 1e10
    for i in range(n-k+1):
        if li[i+k-1] - li[i] < ans:
            ans = li[i+k-1] - li[i]
    print(ans)
        
        