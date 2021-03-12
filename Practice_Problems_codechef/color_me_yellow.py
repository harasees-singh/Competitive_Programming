def find_possible_triplets(r, b):
    return min(r, b, (r+b)//3)
t = int(input())
for _ in range(t):
    n, r, g, b = map(int, input().split())
    max_number_columns_possible = (r + g + b)//3
    if max_number_columns_possible >= n:
        if r >= n and b >= n:
            ans = n
        else:
            ans = min(r, b)
    else:
        if g >= min(r, b):
            # green surplus
            ans = min(r, b)
        else:
            # green are lesser in number
            ans = g + find_possible_triplets(r - g, b - g)
            
    print(ans)
            
            
            
            
def no_of_columns(n, r, g, b):
    a = min(n, r, b)
    lo = 0
    hi = a
    ans = 0
    while lo<=hi:
        mid = lo + (hi-lo)//2
        if 3*(mid-1) + 1 < (r + g + b):
            ans = mid
            lo = mid + 1
        else:
            hi = mid - 1
    return ans


t = int(input())
for i in range(t):
    n, r, g, b = list(map(int, input().split()))
    a = no_of_columns(n, r, g, b)
    print(a)
            
            