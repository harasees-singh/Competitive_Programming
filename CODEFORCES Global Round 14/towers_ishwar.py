for _ in range(int(input())):
    n, m, x = [int(x) for x in input().split()]
    h = [int(x) for x in input().split()]
    idx =[]
    for i in range(n):
        idx.append(i)
    idx_sorted = sorted(idx, key=lambda i:h[i]) #index sorted by height of block
    ans = [0]*n ; count = 0
    #print(idx_sorted)
    for i in idx_sorted:
        ans[i] = count + 1
        count = (count + 1)%m
        # print(count)
    print("YES")
    print(*ans)