t = int(input())
for i in range(t):
    n = int(input())
    m = int(input())
    classes = {}
    time_stamps = []

    for j in range(n):
        start, end = map(int, input().split())
        if start in classes.keys():
            classes[start]+=1
        else:
            classes[start] = 1
            time_stamps.append(start)
        
        if end+1 in classes.keys():
            classes[end+1] -= 1
        else:
            time_stamps.append(end+1)
            classes[end+1] = -1
        
    ans = 0
    sum = 0
    time_stamps.sort()
    for i in time_stamps:
        sum += classes[i]
        ans = max(sum, ans)
    
    print(ans)
        
