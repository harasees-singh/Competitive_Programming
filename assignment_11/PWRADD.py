import sys
 
def add(a, b):
    print('1', a, b) 
    sys.stdout.flush()
    return int(input())
# --------------------- Do not touch anything above this line ----------------------
 
# The return value of this function is wrong, write the correct version of this function using the add(a, b) ...
# function defined above.
 
# Note that this function should return (a ** b) % m, you are guaranteed that add(a, b) returns (a + b) % m

    

def pwr(a, b):
    hidden_number = 1
    number_not_found = True
    while hidden_number < 10**9:
        #print(hidden_number)
        
        parity = add(hidden_number, 0)
        #print('parity', parity)
        if parity == 0:
            number_not_found = False
            break
        elif parity == hidden_number:
            pass
        else: # if hidden_num % m < hidden_num means we left m behind
            hidden_number = hidden_number - parity
            number_not_found = False
            break
        
        hidden_number *= 2
    
    if number_not_found:
        m =  (10**9 - add(10**9, 0))
    else:
        m = hidden_number # we found m

    return (a**b)%m



 
 
# --------------------- Do not touch anything below this line ----------------------
 
a, b = map(int, input().split())
ans = pwr(a, b)
print('2', ans)
 