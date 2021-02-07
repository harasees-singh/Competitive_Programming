T = int(input())
inputs = []

for i in range(T):

    for _ in range(T):
        inputs.append(list(map(int, input().split())))
    

    
    for i in range(T):


        sum = inputs[i][1] + inputs[i][2]
        sum_to_check_divisiblity = sum
        next_digit = 0
        for j in range(inputs[i][0] - 2):
            next_digit = sum%10
            sum = sum*10 + next_digit
            sum_to_check_divisiblity += next_digit
        
        if sum_to_check_divisiblity%3 == 0:
            print("YES")
        else:
            print("NO")