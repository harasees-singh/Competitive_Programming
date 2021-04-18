for t in range(int(input())):
    n, q = map(int, input().split())
    li = list(map(int, input().split()))
    dp = [0 for _ in range(n)]
    dp[0] = li[0]
    for i in range(1, n):
        dp[i] = dp[i-1] | (dp[i-1] & li[i]) | li[i]
    print(dp[n-1])
    for Query in range(q):
        x, y = map(int, input().split())
        new_li = li
        new_li[x-1] = y
        dp = [0 for _ in range(n)]
        dp[0] = new_li[0]
        for j in range(1, n):
            dp[j] = dp[j-1] | (dp[j-1] & new_li[j]) | new_li[j]
        print(dp[n-1])
    