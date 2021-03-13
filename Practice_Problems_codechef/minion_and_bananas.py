import math
def good(mid, h, pile_sizes):
    ans = 0
    for i in range(len(pile_sizes)):
        ans += pile_sizes[i]//mid 
        if pile_sizes[i]%mid != 0:
            ans += 1
    if ans <= h:
        return True
    return False
    
for _ in range(int(input())):
    n, h = map(int, input().split())
    pile_sizes = list(map(int, input().split()))
    pile_sizes.sort()
    total_bananas = sum(pile_sizes)
    left = 1
    right = pile_sizes[-1]
    while left <= right:
        mid = (left + right)//2
        if good(mid, h, pile_sizes):
            ans = mid
            right = mid - 1 
        else:
            left = mid + 1
    print(ans)