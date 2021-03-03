import sys
 
def run_program(m):
    print('1 ' + str(m))
    sys.stdout.flush()
    r = int(input())
    if r == 0:
        return False
    elif r == 1:
        return True
    exit()
 
# ------------------- Do not touch anything above this line -------------------------------------
 
# complete the function below, use run_program(x) to determine if Chef's program can consume x bytes
# The result will be True if it can and False otherwise
# If you call the function run_program more than 31 times, you will get a wrong answer verdict
def BinarySearch():
    # define the search space
    n = 10**9
    left, right = 0, n-1
    while left <= right:
        mid = (left +right)//2      # this binary search is custom. custom in the sense it finds the highest possible element which satisfies the given condition which is 
                                    # being just big enough to not exceed the memory limit or in other words the bisect_right kind of thing
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
print('2 ' + str(find_memory_limit()))
    
