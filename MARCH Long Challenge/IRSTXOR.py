import math
def Binary(integer):
    string = ''
    while integer:
        string += str(integer%2)
        integer = integer//2
    string = string[::-1]
    return string

def XOR_Inverse(binary, target):
    # need to prepend zeroes 
    length_of_binary = len(binary)
    length_of_target = len(target)
    if length_of_target > length_of_binary:
        binary = '0'*(length_of_target - length_of_binary) + binary
    else:
        target = '0'*(length_of_binary - length_of_target) + target
    
    ans = ''
    #print(binary, 'target =', target)
    for j in range(len(binary)):
        i = len(binary)-j-1
        if target[i] == '0':
            #print('target 0 encountered ', binary[i], 'to be appended on the front')
            ans = binary[i] + ans
        else:
            ans = str(1 ^ int(binary[i])) + ans
        #print('currently ans is ', ans)
    return ans

def Integer(binary):
    ans = 0
    for j in range(len(binary)):
        i = len(binary) - j -1
        ans += int(binary[i])*(2**j)
        
    return ans

t = int(input())
for _ in range(t):
    c = int(input())
    li = []
    logarithm = math.log(c, 2)
    if float(logarithm//1) == logarithm:
        logarithm = int(logarithm) + 1
    else:
        logarithm = math.ceil(logarithm)
    max_ = 0
    C = Binary(c)
    for i in range(2**logarithm):
        A = Binary(i)
        B = XOR_Inverse(A, C)
        b = Integer(B)
        a = Integer(A)
        #print('candidate B ', B, '=', Integer(B),' a XOR b = ', a^b)
        #print()
        
        if b<2**logarithm:
            temp = a*b
            if temp > max_:
                max_ = temp
        
    
    print(max_)

        
    
        