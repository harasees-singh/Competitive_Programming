def lessthan(x, y):
    return x[0] < y[0]
 
# complete this function
# the return value is wrong, you are to complete this function so that the return value is correct
# arr is a list of tuples where each tuple contains the pair (x, y)

# the first occurance of an element like a '2' or a '1' in a tuple will result into stable sorting always 
# think of placing all the tuples that are strictly less than the pivot into an array and then placing the pivot and then finally the tuples bigger than the pivot 
# incase of 2 or more tuples with the same zeroth element if the pivot is chosen to be the tuple that is further down the line then this pivot when placed in the new partitioned array
# will come before the tuple which was originally there and hence only the first occurances will produce stable sorts
first_occurance_tuple = {}

def choose_pivot(arr):
    for i in range(len(arr)):
        if arr[i][0] not in first_occurance_tuple.keys():
            first_occurance_tuple[arr[i][0]] = i            # store the index where sorting will be stable
            
    return sorted(list(first_occurance_tuple.values()))
 
# ---------------------------- Do not modify code below this line ------------------------------------
n = int(input())
arr_strip = list(map(int, input().split()))
arr = []
for i in range(0, 2*n, 2):
    arr.append((arr_strip[i], arr_strip[i+1]))
 
candidates = choose_pivot(arr)
 
print(len(candidates))
print(*candidates)
 