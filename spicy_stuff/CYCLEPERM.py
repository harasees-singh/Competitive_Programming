'''Input:
The first line of the input is a positive integer N indicating the length of the permutation.
The next line contains N integers and is a permutation of 1,2,...,N.

Output:
The first line of the output must contain a single integer k denoting the number of cycles in the permutation. 
Line 2 should describe the first cycle, line 3 the second cycle and so on and line k+1 should describe the kth cycle.'''

# idea: loop through the list. make arr[i] = 0 whenever you leave the ith position keep looping until all the elements are not equal to zero. append arr[i] to some answer list



n = int(input())

# print(type(map(int, [1, 2, 3])))
arr = list(map(int, input().split()))
answer = []
count = 0
temporary = 0
while arr!=[0]*len(arr):
    var = temporary
    iteration_success = False
    sub_answer = []

    while arr[var]!=0:
        temp = var
        sub_answer.append(temp+1)
        var = arr[var]-1
        arr[temp] = 0
        iteration_success = True

    temporary+=1
    

    if iteration_success:
        count+=1
        sub_answer.append(sub_answer[0])
        answer.append(sub_answer)
    
    # print(answer)
    

print(count)
for i in range(count):
    for _ in range(len(answer[i])):
        print(answer[i][_], end=" ")
    print()




