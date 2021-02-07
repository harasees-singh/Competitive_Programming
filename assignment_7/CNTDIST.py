'''
First line contains an integer n, the size of the array Next n lines each contain a single integer, the elements of the array
'''
n = int(input())
set_from_array = []
for i in range(n):
    i = int(input())
    set_from_array.append(i)
set_from_array = set(set_from_array)
print(2)                # printing time complexity of chef's code
print(len(set_from_array))
# print(type(set_from_array))