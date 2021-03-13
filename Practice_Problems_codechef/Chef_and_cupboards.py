import math
def find_maximum(A, B):
    probable_answer = 2*(A+B)/6 - (math.sqrt(4*((A+B)**2) - 12*A*B))/6
    return math.floor(probable_answer), math.ceil(probable_answer)

def Volume(x, a, b):
    return x*(a-x)*(b-x)

for _ in range(int(input())):
    A, B = map(int, input().split())
    X1, X2 = find_maximum(A, B)
    if Volume(X1, A, B) > Volume(X2, A, B):
        ans = X1
        vol = Volume(X1, A, B)
    elif Volume(X1, A, B) == Volume(X2, A, B):
        ans = min(X1, X2)
        vol = Volume(X1, A, B)
    else:
        ans = X2
        vol = Volume(X2, A, B)
    print(ans,vol)
    
    
    
    
    
    
    
    