t = int(input())
for _ in range(t):
    n, w, wr = map(int, input().split())
    li = list(map(int, input().split()))
    unique_weights = dict()
    set_of_weights = set(li)
    for weight in li:
        if unique_weights.get(weight):
            unique_weights[weight] += 1
        else:
            unique_weights[weight] = 1 
    sum_re = w-wr
    ans= 0
    for temp in unique_weights.keys():
        if unique_weights[temp] > 1:
            if unique_weights[temp]%2==0:
                ans += temp*unique_weights[temp]
            else:
                ans += temp*(unique_weights[temp]-1)
    if ans >= sum_re:
        print("YES")
    else:
        print("NO")
