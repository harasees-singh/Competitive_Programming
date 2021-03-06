def Symmetric(arr):
    for i in range(len(arr)):
        for j in range(len(arr)):
            if arr[i][j] != arr[j][i]:
                return False
    return True

def Triangular(arr):
    first_bool = True
    second_bool = True
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            if arr[i][j] != 0:
                first_bool = False
                break
        for j in range(0, i):
            if arr[i][j] != 0:
                second_bool = False
                break
    if first_bool or second_bool:
        return True
            
def Diagonal(arr):
    for i in range(len(arr)):
        first_bool = True
    second_bool = True
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            if arr[i][j] != 0:
                first_bool = False
                break
        for j in range(0, i):
            if arr[i][j] != 0:
                second_bool = False
                break
            
    if first_bool and second_bool:
        return True
                
                
    
            

t = int(input())


for j in range(t):
    n = int(input())
    li = []
    for i in range(n):
        li.append(list(map(int, input().split())))
    s, t, d = 0, 0, 0
    if Symmetric(li):
        s = 1
    if Triangular(li):
        t = 1
    if Diagonal(li):
        d = 1
    
    print(s+2*t+4*d)

