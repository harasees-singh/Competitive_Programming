'''You're given a number N. Print the first N lines of the below-given pattern.

1
2 3 2
3 4 5 4 3
4 5 6 7 6 5 4
5 6 7 8 9 8 7 6 5'''
n = int(input())
sum = 1
for row in range(n):
    for column in range(2*row+1):
        if column<=row:
            print(sum, end=" ")
            sum+=1

        if column==row+1:
            sum-=2
            print(sum, end=" ")
        if column>row+1:
            sum-=1
            print(sum, end=" ")
    if row:        
        sum+=1
    print()
    