#print("hele", flush=True)
# 1 2
import sys
lx, rx, ly, ry = 0, 0, 0, 0
def HellFire(midx, midy, answer):
    global lx, rx, ly, ry
    if answer == "O":
        return "success"
    elif answer == "PY":
        rx = midx-1
    elif answer == "NY":
        lx = midx+1
    elif answer == "XP":
        ry = midy-1
    elif answer == "XN":
        ly = midy+1
    elif answer == "PP":
        rx = midx - 1
        ry = midy - 1
    elif answer == "PN":
        rx = midx - 1
        ly = midy + 1
    elif answer == "NP":
        lx = midx + 1
        ry = midy - 1
    elif answer == "NN":
        lx = midx + 1
        ly = midy + 1
    else:
        if answer == "FAILED":
            print("failed either due to excess queries or invalid attack statement")
            exit(0)
    return "proceed"
        
def RingOfFire():
    global lx, ly, rx, ry
    print(2, lx, ly, rx, ry)
    sys.stdout.flush()
    answer = input()
    if answer == "O":
        return "success"
    if answer == "IN":
        return "proceed"
    if answer == "OUT":
        lx-=2
        rx+=2
        ly-=2
        ry+=2
        return RingOfFire()
    
    


def BinarySearch():
    # lx, rx, ly, ry = -10, 10, -10, 10
    global lx,rx,ly,ry
    lx, rx, ly, ry = int(-2e18), int(2e18), int(-2e18), int(2e18)
    while lx <= rx and ly <= ry:
        midx = (lx+rx)//2
        midy = (ly+ry)//2
        print(1, midx, midy, flush=True)
        sys.stdout.flush()
        answer = input()
        output1 = HellFire(midx, midy, answer)
        if output1 == "success":
            return
        output2 = RingOfFire()
        if output2 == "success":
            return
        
        


t, q, d = map(int, input().split())
for i in range(t):
    if d==0:
        lx, rx, ly, ry = int(-2e18), int(2e18), int(-2e18), int(2e18)
        while lx <= rx and ly <= ry:
            midx = (lx+rx)//2
            midy = (ly+ry)//2
            print(1, midx, midy, flush=True)
            sys.stdout.flush()
            answer = input()
            if answer == "O":
                break
            elif answer == "PY":
                rx = midx-1
            elif answer == "NY":
                lx = midx+1
            elif answer == "XP":
                ry = midy-1
            elif answer == "XN":
                ly = midy+1
            elif answer == "PP":
                rx = midx - 1
                ry = midy - 1
            elif answer == "PN":
                rx = midx - 1
                ly = midy + 1
            elif answer == "NP":
                lx = midx + 1
                ry = midy - 1
            elif answer == "NN":
                lx = midx + 1
                ly = midy + 1
            else:
                if answer == "FAILED":
                    print("failed either due to excess queries or invalid attack statement")
                    exit(0)
    else:
        BinarySearch()


