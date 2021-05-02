for _ in range(int(input())):
    n, l, r = map(int, input().split())
    c = list(map(int, input().split()))
    dic_l = {}
    dic_r = {}
    for i in range(l):
        if c[i] in dic_l.keys():
            dic_l[c[i]] += 1
        else:
            dic_l[c[i]] = 1
    for i in range(l, n):
        # print(i)
        if c[i] in dic_r.keys():
            dic_r[c[i]] += 1
        else:
            dic_r[c[i]] = 1
    # print(dic_l, dic_r)
    for i in dic_l.keys():
        if i in dic_r.keys():
            ans = min(dic_r[i], dic_l[i])
            r -= ans
            l-=ans
            dic_l[i] -= ans
            dic_r[i] -= ans
    cost = abs((l-r)//2) + min(l, r)
    # print(dic_l, dic_r)
    cnt = 0
    if r > l:
        li = sorted(dic_r.values())
        i = len(li) - 1
        # print(li)
        while r > l and i >= 0:
            r -= li[i]//2
            l += li[i]//2
            i -= 1 
        # print(l, r)
        if r > l:
            cost += (r-l)//2

        # for i in dic_r.keys():
            
        #     cnt += dic_r[i]//2
        #     dic_r[i] %=2
        #     cost += dic_r[i]
        #     if cost > (r-l) // 2:
        #         cost = (r-l)//2
        #     if 2 *cnt > r - l:
        #         cost += 2*cnt - (r-l)
    else:
        li = sorted(dic_l.values())
        # li = sorted(dic_r.values())
        i = len(li) - 1
        while l > r and i >= 0:
            l -= li[i]//2
            r += li[i]//2
            i -= 1 
        if l > r:
            cost += (l-r)//2
        # for i in dic_l.keys():
        #     cnt += dic_l[i]//2
        #     # cost += dic_l[i]//2
        #     dic_l[i] %=2
        #     cost += dic_l[i]
        #     if cost > (l-r) // 2:
        #         cost = (l-r)//2
        #     if 2 *cnt > l - r:
        #         cost += 2*cnt - (l-r)
    
    # cost += abs((l-r)//2)
    print(cost)

