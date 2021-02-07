# return the maximum distance astronaut has to travel to reach a space station city in flatland from all possible cities
import math
import os
import random
import re
import sys

# input n the no. of cities and m the no. space stations and subsequent lines input their positions.
def flatlandSpaceStations(n, c):
    c.sort()
    print(c)
    max = 0
    for i in range(0, len(c)-1):
        distance = (-c[i]+c[i+1])//2
        if max<distance:
            max = distance
    if c.count(0) == 0:
        if max<c[0]:
            max = c[0]
    if c.count(n-1) == 0:
        if max<n-1-c[-1]:
            max = n-1-c[-1]
        
    return max
    

nm = input().split()

n = int(nm[0])

m = int(nm[1])

c = list(map(int, input().rstrip().split()))

result = flatlandSpaceStations(n, c)
print(result)
