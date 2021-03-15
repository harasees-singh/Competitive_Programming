for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    l.sort()
    ans = 0
    i = 0
    while i < n-1:
        count = 1
        #print(i)
        while i < n-1:
            if l[i] == l[i+1]:
                count += 1 
                i += 1 
            else:
                break
        if count > 1:
            ans += count - 1            # if n colors are same then need to mix n - 1 times. for example 1 1 2 2 3, here we have all these 1s and 2s so we can start by adding the last color
                                        # to the first copy color i.e. 1 in this case so that it becomes 4 and then simply add 4 to the next copy color that is 2 and so on 
        i += 1 
    print(ans)