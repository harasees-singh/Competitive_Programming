for _ in range(int(input())):
    int(input())
    li = list(map(int,input().split()))
    large_val = float('inf')
    ans = 0
    for i in range(len(li)):
        if li[i]<large_val:
            large_val = li[i]
        ans+= li[i]
    print(ans)
        
