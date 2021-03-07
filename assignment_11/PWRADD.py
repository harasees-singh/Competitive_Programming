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
    res = 1
    for _ in range(0, b):
        temp = 0
        for i in range(0, a):
            temp = add(temp, res)
        res = temp
    return res
 
 
# --------------------- Do not touch anything below this line ----------------------
 
a, b = map(int, input().split())
ans = pwr(a, b)
print('2', ans)
 