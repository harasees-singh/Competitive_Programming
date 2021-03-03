import sys
import random
 
arr = []
queries_count = 0
def find_pos(x):
    global queries_count
    queries_count = queries_count + 1
    if queries_count > 40:
        print('error, took more than 40 queries')
        print('hidden array = ', arr, 'x = ', x)
        exit()
 
    if x < 0 or x >= len(arr):
        print('error, index out of range')
        print('hidden array = ', arr, 'x = ', x)
        exit()
    return arr[x]
    
# ----------------- Do not modify anything above this line -----------------------
# copy your solution here
def BinarySearchLeftlimit(len_arr, target):
    # define the search space
    n = len_arr
    left, right = 0, n-1
    while left <= right:
        mid = (left+right)//2
        Mid_element = find_pos(mid)
        if Mid_element  >= target:
            right = mid - 1
        else:
            left = mid + 1
    
    index = max(left, right)
    if find_pos(index) == target:
        return index
    else:
        return -1

# error in BinarySearchRightlimit function
def BinarySearchRightlimit(len_arr, target):
    # define the search space
    n = len_arr
    left, right = 0, n-1
    while left <= right:
        mid = (left+right)//2
        Mid_element = find_pos(mid)
        if Mid_element  <= target:
            left = mid + 1
        else:
            right = mid - 1
    
    index = min(left, right)
    if find_pos(index) == target:
        return index
    else:
        return -1

def count(n, x):
    R = BinarySearchRightlimit(n, x)
    L = BinarySearchLeftlimit(n, x)
    #print("the value of L and t is", L, R)
    if L >= 0:
        ans = R - L
        return ans + 1
    else:
        return 0
 
# ----------------- Do not modify anything below this line -----------------------
 
n = random.randint(1, 100000)
dict = {}
for _ in range(0, n):
    app = random.randint(0, 100000)
    arr.append(app)
    dict[app] = dict.get(app, 0) + 1
 
arr = sorted(arr)

for _ in range(1, 1000):
    queries_count = 0
    x = random.randint(0, 100000)
    ans = count(len(arr), x)
    if ans != dict[x]:
        print('Wrong answer, expected = ', dict[x], 'got = ', ans)
        print('hidden array = ', arr, 'x = ', x)
        exit()
 
print('Correct Answer!')