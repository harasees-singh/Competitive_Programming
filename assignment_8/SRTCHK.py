'''First line contains a single integer T, the number of testcases

The first line of each testcase contains a single integer n, the number of elements in the arrays

The second line of each testcase contains n space separated integers denoting the array A
The third line of each testcase contains n space separated integers denoting the array B'''


# could have written my own sort() but I will be wriring bubble sort as part of my homework anyway 
for i in range(int(input())):
	input()
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	a.sort()
	if a == b:
		print("yes")
	else:
		print("no")


