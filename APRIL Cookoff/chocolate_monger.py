for _ in range(int(input())):
    n, x = map(int, input().split())
    
    li = list(map(int, input().split()))
    if n==x:
        print(0)
        continue
    unordered_types = set(li)
    print(min(len(unordered_types), n-x))
