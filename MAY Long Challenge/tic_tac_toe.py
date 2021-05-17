chessboard=[]
columns = []
def won(i):
    if i*3 in chessboard:
        return True
    if i*3 in columns:
        return True
    if [chessboard[i][i] for i in range(3)] == list(i*3):
        return True
    if [chessboard[2-i][i] for i in range(3)] == list(i*3):
        return True
def count(i):
    ans = 0
    for j in range(3):
        for k in range(3):
            if chessboard[j][k] == i:
                ans += 1
    return ans
for _ in range(int(input())):
    chessboard = [];columns=[]
    chessboard.append(input());chessboard.append(input());chessboard.append(input())
    column1 = chessboard[0][0]+chessboard[1][0]+chessboard[2][0];column2 = chessboard[0][1]+chessboard[1][1]+chessboard[2][1];column3 = chessboard[0][2]+chessboard[1][2]+chessboard[2][2]
    columns = [column1, column2, column3]
    if(count("X")-count("O")==1 or count("X")-count("O")==0):
        if won("X") and won("O"):
            print(3);continue
        if won("X") and count("X")-count("O")==1:
            print(1);continue
        if won("O") and count("X")==count("O"):
            print(1);continue
        if not won("X") and not won("O") and count("_")>=1:
            print(2);continue
        else:
            if not won("X") and not won("O"): 
                print(1);continue
            print(3);continue
    print(3)

