#print("hele", flush=True)
# -3, 3
import sys
def BinarySearch():
    # lx, rx, ly, ry = -10, 10, -10, 10
    lx, rx, ly, ry = int(-2e18), int(2e18), int(-2e18), int(2e18)
    while lx <= rx and ly <= ry:
        midx = (lx+rx)//2
        midy = (ly+ry)//2
        print(1, midx, midy, flush=True)
        sys.stdout.flush()
        answer = input()
        if answer == "O":
            return "truck destroyed"
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
        
t, q, d = map(int, input().split())
for i in range(t):
    BinarySearch()


