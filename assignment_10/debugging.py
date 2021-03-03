'''li = [1, 2, 3, 4]






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

def run_program(x):
    if x <= 23:
        return True
    return False

def BinarySearch(arr):
    # define the search space
    n = len(arr)
    left, right = 0, n-1
    while left <= right:
        mid = (left +right)//2
        if run_program(mid):
            left = mid + 1
        else:
            right = mid - 1
    return min(left, right)

print(BinarySearch([x for x in range(10**6)]))
'''
'''import sys
import random
 
limit = 0
count = 0
 
def run_program(m):
    global count
    count = count + 1
    if count > 31:
        print("Took more than 31 queries for limit = " + str(limit))
        exit()
    if m <= limit:
        return True
    else:
        return False
 
 
# ------------------- Do not touch anything above this line -------------------------------------
import array as ar
# copy your solution here
def BinarySearch():
    # define the search space
    n = 10**9
    left, right = 0, n-1
    while left <= right:
        mid = (left +right)//2
        if run_program(mid):
            left = mid + 1
        else:
            right = mid - 1
    return min(left, right)
# complete the function below, use run_program(x) to determine if Chef's program can consume x bytes
# The result will be True if it can and False otherwise
# If you call the function run_program more than 31 times, you will get a wrong answer verdict
def find_memory_limit():
    
    return BinarySearch()
# ------------------- Do not touch anything below this line -------------------------------------
 
for _ in range(0, 1000):
    limit = random.randint(1, 999999999)
    count = 0
    found = find_memory_limit()
    if found != limit:
        print('Error found limit = ' + str(found) + ', when actual limit = ' + str(limit))
        exit()
 
print('your program passed 1000 random testcases!')'''
 
import sys
import random

li = [1, 2, 4, 4, 4, 4, 4, 7, 8, 8, 9, 9]
def find_pos(x):
    return li[x]
arr = []
queries_count = 0


'''def find_pos(x):
    global queries_count
    queries_count = queries_count + 1
    if queries_count > 40:
        print('error, took more than 40 queries')
        print('hidden array = ', arr, 'x = ', x, 'len_of_array = ', len(arr))
        exit()
 
    if x < 0 or x >= len(arr):
        print('error, index out of range')
        print('hidden array = ', arr, 'x = ', x)
        exit()
    return arr[x]'''
    
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
        
#print( len(li),  BinarySearchRightlimit(len(li), 4), BinarySearchLeftlimit(len(li), 4), BinarySearchRightlimit(len(li), 4) - BinarySearchLeftlimit(len(li), 4) + 1)

def count(n, x):
    R = BinarySearchRightlimit(n, x)
    L = BinarySearchLeftlimit(n, x)
    print("the value of L and R is", L, R)
    if L >= 0:
        ans = R - L
        return ans + 1
    else:
        return 0
 

print(count(len(li), int(input())))
# ----------------- Do not modify anything below this line -----------------------
 
'''n = random.randint(1, 100000)
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

'''