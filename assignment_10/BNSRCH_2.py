'''
Find the number of occurrences
'''
import sys

def find_pos(x):
    print('1 ' + str(x))
    sys.stdout.flush()
    t = int(input())
    return t
# ----------------- Do not modify anything above this line -----------------------
# Complete this function count(n, x), this returns 0 always and hence is wrong, it should return the number of occurrences of x in Chef's array
# You can use the function find_pos(x) to find the value of the element at position x (0 indexed)
# If the index is invalid or you use more than 40 queries to obtain the value, you will receive Wrong Answer
# Chef's array size is not more than 10 ** 5

def BinarySearchLeftlimit(len_arr, target):
    # define the search space
    n = len_arr
    left, right = 0, n-1
    while left <= right:
        mid = (left + right)//2
        if find_pos(left) == target:
            return left
        if find_pos(mid) == target:
            right = mid
        elif find_pos(mid) > target:
            right = mid-1
        else:
            left = mid+1
    return -1

# error in BinarySearchRightlimit function
def BinarySearchRightlimit(len_arr, target):
    # define the search space
    n = len_arr
    left, right = 0, n-1
    while left <= right:
        mid = (left + right)//2
        if find_pos(right) == target:
            return right
        if find_pos(mid) == target:
            left = mid
        elif find_pos(mid) > target:
            right = mid-1
        else:
            left = mid+1
    return -1 


def count(n, x):
    R = BinarySearchRightlimit(n, x)
    L = BinarySearchLeftlimit(n, x)
    print("the value of L and t is", L, R)
    if L >= 0:
        ans = R - L
        return ans + 1
    else:
        return 0
 
# ----------------- Do not modify anything below this line ----------------------- #
 
n = int(input())
x = int(input())
 
print('2 ' + str(count(n, x)))