def flip(bit):
    if bit=='1':
        return '0'
    return '1'


mid = 0
for _ in range(int(input())):
    s = input()
    l = 0
    r = 2**(10**6)
    mid = (l+r)//2
    mid=mid>>1
    i = len(s)-1
    while mid!=0 :
        while i>= 0:
            bit = mid&1
            if int(s[i]) == bit:
                i-=1
                mid = mid>>1
            else:
                i-=1
        if i == 0:      # we traversed the entire list
            pass
    