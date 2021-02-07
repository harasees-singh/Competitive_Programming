import math
nth_prime = int(input()) - 1

j = 0
box = 1
list = [2]

def prime(num):
    if num == 2:
        return True
    if num == 3:
        return True
    if num % 2 == 0:
        return False

    for i in range(3, math.floor(math.sqrt(num)) + 1, 2):
        if num % i == 0:
            return False
    return True
    
    
while j < nth_prime:
    var = 0
    box += 2
    if prime(box):
        list.append(box)
        j += 1
        
for j in range(len(list)):
    print(list[j], end=' ')