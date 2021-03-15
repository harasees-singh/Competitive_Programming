def good(mid, w, h, n):
    if (mid//w)*(mid//h) >= n:
        return True
    return False

for _ in range(int(input())):
    n, h, w = map(int, input().split())
    left = 0 
    right = max(h, w)*n 
    while left <= right:
        mid = (left+right)//2
        if good(mid, w, h, n):
            ans = mid
            right = mid - 1 
        else:
            left = mid + 1 
    print(ans)
        
            