import sys
m = 0
queries = 0
input_a, input_b = 0, 0
def add(a, b):
    global m
    global queries
    if a < 0 or a > 1000000000:
        print('invalid arguments to add, input too large or negative')
        exit()
    if b < 0 or b > 1000000000:
        print('invalid arguments to add, input too large or negative')
        exit()
    queries += 1
    if queries > 10000:
        print('too many queries for a = ', a, 'b = ', b, 'm = ', m)
    return (a + b) % m
# --------------------- Do not touch anything above this line ----------------------
 
# The return value of this function is wrong, write the correct version of this function using the add(a, b) ...
# function defined above.
 
# Note that this function should return (a ** b) % m, you are guaranteed that add(a, b) returns (a + b) % m
def mul(a, b):
    res = 0
    for _ in range(0, b):
        res = add(res, a)
    return res
 
def pwr(a, b):
    res = 1
    for _ in range(0, b):
        res = mul(res, a)
    return res
 
 
 
 
# --------------------- Do not touch anything below this line ----------------------
 
def power(a, b, m):
    res = 1
    for _ in range(0, b):
        res = (res * a) % m
    return res
 
import random
 
for _ in range(0, 1):
    # input_a, input_b = random.randint(1, 100), random.randint(1, 100)
    # m = random.randint(2, 1000000000)
    input_a, input_b, m = 57, 15, 609816743
    got = pwr(input_a, input_b)
    print(got)
    expected = power(input_a, input_b, m)
    if expected != got:
        print('Wrong answer, expected = ', expected, 'got = ', got)
        print('a = ', input_a, 'b = ', input_b, 'm = ', m)
        exit()
print('Ok!')