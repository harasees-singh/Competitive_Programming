import math
arr = [
    ['_', '_', '_'],
    ['_', '_', '_'],
    ['_', '_', '_']
]
b = True


###############################################




def best_move():
    best_score = -5000000000
    for i in range(3):
        for j in range(3):
            if arr[i][j] == "_":
                arr[i][j] = "O"
                score = minimax(0)
                arr[i][j] = '_'
                if score > best_score:
                    best_score = score
                    ai_move = [i, j]

    arr[ai_move[0]][ai_move[1]] = "O"
    

###############################################

def minimax(ismaximizing):
    if win(arr, 'O') == 'O' : #AMD won
        return 1
    elif win(arr, "X") == 'X':
        return -1 
    elif draw(arr):
        return 0


    if ismaximizing == 1:       # move = 1 means ai's turn
        best_score = -500000000
        for i in range(3):
            for j in range(3):
                if arr[i][j] == "_" :
                    arr[i][j] = "O"
                    score = minimax(0)
                    arr[i][j] = "_"
                    best_score = max(score, best_score)
        return best_score        

                
            
    elif ismaximizing == 0:
        best_score = 5000000000
        for i in range(3):
            for j in range(3):
                if arr[i][j] == '_':
                    arr[i][j] = 'X'
                    score = minimax(1)
                    arr[i][j] = "_"
                    best_score = min(score, best_score)
        return best_score

    



###############################################
def win(n, character):
    # horizontal
    for i in range(3):
        if n[i][0] == character and n[i][1] == character and n[i][2] == character:
            return character
        
    # vertical
    for j in range(3):
        if n[0][j] == character and n[1][j] == character and n[2][j] == character:
            return character

    # diagonal
    if n[0][0] == character and n[1][1] == character and n[2][2] == character:
        return character
    elif n[0][2] == character and n[1][1] == character and n[2][0] == character:
        return character

################################################

def draw(n):
    for i in range(3):
        for j in range(3):
            if n[i][j] == '_':
                return False
    return True
    
#################################################
for i in range(3):
    for j in range(3):
        print(arr[i][j], end='  ')
    print('\n')

print("I will choose first...")

print("after i choose, enter valid position in the format 'x, y' with one space between ',' and 'y' also ranges of x and y are from 0 to 2 including both")
print("note that 'x' represents row no. and 'y'represents column no.")

arr[1][1] = "O"

for i in range(3):
    for j in range(3):
        print(arr[i][j], end='  ')
    print('\n')

while True:

    print('---------------------------------------')

    

    
    x1, y1 = list(map(int, input('Player1: ').split(', ')))    
    
    # print(x1, y1, x2, y2)

    if x1 > 2 or y1 > 2:
        print('Enter valid values(0 to 2) and TRY AGAIN')
        break
    if arr[x1][y1] != '_':
        print("huh! you think you can fool me??!! enter valid inputs again")
        x1, y1 = list(map(int, input('Player1: ').split(', '))) 

    if arr[x1][y1] == '_':
        arr[x1][y1] = 'X'
        # print(arr)
        # b = False
        for i in range(3):
            for j in range(3):
                print(arr[i][j], end='  ')
            print('\n')
        
        print("-------------------------------------")
        
        if not draw(arr):
            winner = win(arr, 'X')
            if winner == 'X':
                print('Humans won, AI failed!!')
                break
        else:
            print('MATCH DRAWN')
            break
    
    best_move()
    

    for i in range(3):
        for j in range(3):
            print(arr[i][j], end='  ')
        print('\n')
    
    print("-------------------------------------")
    
    if not draw(arr):
        winner = win(arr, 'O')
        if winner == 'O':
            print('A microprocessor just beat you sucker!!!')
            break
    else:
        print('MATCH DRAWN')
        break



    