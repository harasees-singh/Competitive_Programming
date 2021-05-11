import sys
import copy
sys.setrecursionlimit(50)

hellya = set()
def recursion(chessboard, xcount, ocount):
    if abs(xcount-ocount) > 1:
        return
    for i in range(3):
        print("row iterator")
        for j in range(3):
            print("column iterator")
            if chessboard[i][j]=='_':
                copy_chessboard = copy.deepcopy(chessboard)
                copy_chessboard[i][j]='X'
                recursion(copy_chessboard, xcount+1, ocount)
                for itera in range(3):
                    print("string typecast for X")
                    copy_chessboard[itera]=str(copy_chessboard[itera])
                hellya.add(tuple(copy_chessboard))

                if xcount > ocount:
                    copy_2_chessboard = copy.deepcopy(chessboard)
                    copy_2_chessboard[i][j]='O'
                    
                    recursion(copy_2_chessboard, xcount, ocount+1)
                    for itera in range(3):
                        print("string typecast for O")
                        copy_2_chessboard[itera]=str(copy_2_chessboard[itera])
                    hellya.add(tuple(copy_2_chessboard))
    return


for _ in range(int(input())):
    chessboard=[]
    
    for i in range(3):
        chessboard.append(list(input()))
    print(chessboard)
    input_=[['_']*3, ['_']*3, ['_']*3]
    # hellya.add(("hey", "what", "up"))
    print(input_)
    # print(type(str(input_)))
    # print(input_)
    # print(chessboard)
    # print(type(tuple(chessboard)))
    recursion(input_, 0, 0)
    if tuple(chessboard) in hellya:
        print("yes")
    else:
        print("no")
    
    