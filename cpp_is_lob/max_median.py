n, k = map(int, input().split())
arr = [0]
arr += list(map(int, input().split()))
# copy = arr[:]
# copy.sort()
ans = 0
left = 1
right=n
while(left <= right):
    mid_ = (left+right)//2
    processed_vector = [0]
    prefix_min = [0]
    min_ = int(1e18)
    sum = 0
    mid = mid_
    for i in range(1, n+1):
        if(arr[i]>=mid): 
            sum+=1
        else:
            sum-=1
        processed_vector.append(sum)
        if(sum < min_):
            prefix_min.append(sum)
            min_=sum
        else:
            prefix_min.append(min_)
    
    parity = True
    for r in range(k, n+1):
        l = r-k
        if(prefix_min[l] < processed_vector[r]):
            left = mid_+1 
            ans = mid
            parity = False
            break
    if parity:
        right = mid_-1

print(ans)