'''You are given an array A of size n.

Find the element that is left in the array A when the following procedure (Steps 1-3 in that order) is done until the size of A is 1.

Step 1. Find the smallest element x in the array A and the second smallest element y
Step 2. Remove one occurrence of x and one occurrence of y from A

Step 3. Add the element (3∗x+2∗y)%100 to the array A'''
set_of_nums = []
n = int(input())
for i in range(n):
    set_of_nums.append(int(input()))


def replme_recursive(n):
    if n==1:
        print(set_of_nums[0])
    else:
        set_of_nums.sort()
        a = set_of_nums[0]
        b = set_of_nums[1]
        set_of_nums.pop(0)
        set_of_nums.pop(0)
        temp = (3*a +  2*b) % 100
        set_of_nums.append(temp)
        replme_recursive(len(set_of_nums))


replme_recursive(n)
