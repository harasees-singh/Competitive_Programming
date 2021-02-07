'''You're given a number N. Print the first N numbers of the below-given pattern separated by space.

10,2,20,4,30,6,40,8,50,.... 
Bonus (not checked): Try to implement this using recursive function, f(n) that prints the sequence up to n numbers.'''

n = int(input())
def series_finder_recursive_n_(n):
    if n==2:
        return 2
    if n==1:
        return 10

    else:
        if n%2 == 0:
            value = 2+series_finder_recursive_n_(n-2)
        else:
            value = 10+series_finder_recursive_n_(n-2)

    return value




for i in range(1, n+1):
    print(series_finder_recursive_n_(i), end=" ")
    
    