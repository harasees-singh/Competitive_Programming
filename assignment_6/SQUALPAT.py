'''You're given a number N. Print the first N lines of the below-given pattern.

1 2 3 4 5
10 9 8 7 6
11 12 13 14 15
20 19 18 17 16
21 22 23 24 25
30 29 28 27 26'''
N = int(input())
parity = -1
for n in range(N):
    row = [i for i in range(n*5+1, (n+1)*5+1)]
    if parity==1:
        row.reverse()
        for j in range(5):
            print(row[j], end=" ")
        
        
        
    else:
        for j in range(5):
            print(row[j], end=" ")
        
    
    parity*=-1
    print()