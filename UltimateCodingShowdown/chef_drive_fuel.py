import sys
sys.setrecursionlimit = 999999999

def drive(s, f, i):
    bool1, bool2, bool3 = True, True, True
    if s[i] == '0':
        return False
    if i == len(s) - 1:
        return True

    if i+f<len(s) and s[i+f] == '1':
        bool1 = drive(s, f, i+f)
    if i+f-1<len(s) and s[i+f-1] == '1':
        bool2 = drive(s, f, i+f-1)
    if i+f+1<len(s) and s[i+f+1] == '1':
        bool3 = drive(s, f, i+f+1)
    
    return False
    return bool1 or bool2 or bool3
    


for _ in range(int(input())):
    n, f = map(int, input().split())
    s = input()
    bool = drive(s, f, 0)
    if bool:
        print("YES")
    else:
        print("NO")