li = [1, 2, 3, 4]


def find_pos(x):
    return li[x]

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


def BinarySearchRightlimit(len_arr, target):
    # define the search space
    n = len_arr
    left, right = 0, n-1
    while left <= right:
        mid = (left + right)//2
        if find_pos(right) == target:
            return right
        if find_pos(mid) == target:
            left = mid+1
        elif find_pos(mid) > target:
            right = mid-1
        else:
            left = mid+1
    if find_pos(right) == target:
        return right
    return -1 

def count(n, x):
    R = BinarySearchRightlimit(n, x)
    L = BinarySearchLeftlimit(n, x)
    print("the value of L and R is", L, R)
    if L >= 0:
        ans = R - L
        return ans + 1
    else:
        return 0
print(count(len(li), 4))