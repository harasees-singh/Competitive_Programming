N, M, Q = list(map(int, input().split()))
M = M + 1
N = N + 1


arr = [[1 for i in range(M)]for j in range(N)]


j = 0

for p in range(N):
    arr[p][0] = 0

for p in range(M):
    arr[0][p] = 0

j = 0

list_answers = []



def move_one_step_in_four_directions(x, y):

    
        
    
    arr[x][y] = 0

    if x>1 and arr[x-1][y] != 0:                       # up
        move_one_step_in_four_directions(x - 1, y)

    if x < N-1  and arr[x+1][y] != 0:                  # down
        move_one_step_in_four_directions(x + 1, y)

    if y>1 and arr[x][y-1] != 0:                       # left
        move_one_step_in_four_directions(x, y - 1)

    if y<M-1 and arr[x][y+1] != 0:                     # right
        move_one_step_in_four_directions(x, y + 1)
    
    if arr[list_of_inputs[p][3]][list_of_inputs[p][4]] ==  0:
            return True
    

list_of_inputs = []
for p in range(Q):
    list_of_inputs.append(tuple(map(int, input().split())))

for p in range(Q):
    # [event, x_1, y_1, x_2, y_2] = list(map(int, input().split()))
    if list_of_inputs[p][0] == 1:
        y_1_ = list_of_inputs[p][2]
        x_1_ = list_of_inputs[p][1]
        while y_1_ <= list_of_inputs[p][4]:
            
            arr[list_of_inputs[p][1]][y_1_] = 0
            arr[list_of_inputs[p][3]][y_1_] = 0
            y_1_ = y_1_ + 1
            
        while x_1_ <= list_of_inputs[p][3]:
            
            arr[x_1_][list_of_inputs[p][2]] = 0
            arr[x_1_][list_of_inputs[p][4]] = 0
            x_1_ = x_1_ + 1
    

    #print(arr[x_2][y_2])
    #print(arr)
    if list_of_inputs[p][0] == 2:
        # w = [list_of_inputs[p][1], list_of_inputs[p][2]]
        # print(arr[x_2][y_2])
        
        parity = arr[list_of_inputs[p][3]][list_of_inputs[p][4]]
        if(move_one_step_in_four_directions(list_of_inputs[p][1], list_of_inputs[p][2]) and parity):
            #list_answers.append("YES")
            print("YES")
        else:
            #list_answers.append("NO")
            print("NO")
            
    
    
# using recursion that i don't know how to use but will try
