'''You're given a number N. Print the first N numbers of the below-given pattern separated by space.

10,2,20,4,30,6,40,8,50,.... '''
N = int(input())
i = 1
while N>0:
    print(10*i, end=" ")
    N-=1
    print(i*2, end=" ")
    N-=1
    i+=1
