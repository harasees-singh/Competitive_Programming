for t in range(int(input())):
    n, k = map(int, input().split())
    li = list(map(int, input().split()))
    dp=[0 for i in range(n)]
    dp[0] = li[0]
    for j in range(1, n):
        dp[j] = dp[j-1] | li[j]
    dp2 = [0 for p in range(n)]
    dp[0] = li[-1]
    for l in range(1, n):
        dp[l] = dp[l-1] | li[n-l-1]
    print(dp[-1])
    for _ in range(k):
        x, v = map(int, input().split())
        ans = v | dp[x-2] | dp2[n-x-1]
        li[x-1] = v
        print(ans)