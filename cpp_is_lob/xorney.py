for _ in range(int(input())):
    l, r = map(int, input().split())
    total = (r-l+1)
    if total%2 == 0:
        if (total//2) %2 == 0: print("Even")
        else:
            print("Odd")
    else:
        if l%2 == 0:
            if (total//2) %2 == 0 :print("Even")
            else:
                print("Odd")
        else:
            if (total//2 + 1)%2 == 0: print("Even")
            else:
                print("Odd")