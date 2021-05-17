from itertools import count
from math import gcd
import sys
number, x = 82589933, 2
can = 0
for cycle in count(1):
    y = x
    
    for i in range(2 ** cycle):
        x = (x * x + 1) % number
        factor = gcd(x - y, number)
        can+=1
        if factor > 1:
            print("factor is", factor)
            print("iteration count:", can)
            sys.exit()