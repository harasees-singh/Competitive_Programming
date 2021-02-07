'''The problem we have is the following: given a permutation of 1,2,…,n,
 generate the next permutation in lexicographic order. For example, for 2314 the answer is 2341.'''
#The first line of the input contains two integers, N and K. This is followed by K lines, each of which contains one permutation of 1,2,…,N.
#
#Output:
#The output should consist of K lines. Line i should contain the lexicographically next permutation correponding to the permutation on line i+1 in the input.

# of the numbers are arranged in descending order in the end then find the first point where that order breaks and swap it then and there
# ex 2457983 [983] is in descending so leave it as it now swap 7 and 9 and then arrange [783] in ascending order and that should be the answer
# so the answer should be [[[[[[2459378]]]]]]

# start iterating from the back and the moment you find the descending order break swap: [arr[i-1]<arr[i] swap(arr[i-1], arr[i]) and then sort the list from i to -1]

# correct for the most part just instead of swapping them you need to find the number least number which is greater than a[i-1] and then swap them and then mayber sort the list starting from the very next element
numbers = []
def least_num_greater_than_arg_after_index_j(j): #j is the index of the number we just swapped so now it is the index of the 
    min = numbers[j+1]
    index = j+1
    for i in range(j, len(numbers)-1):
        if numbers[i+1]>numbers[j] and numbers[i+1]<min:            # j = 3 so min is set to 9
            min = numbers[i+1]                                      # loop starts from 3 and goes till the second last element
            index = i+1
    return index
            



n, k = map(int, input().split())
for i in range(k):
    numbers = list(map(int, input().split()))
    for j in range(1, len(numbers)+1):
        if numbers[-j-1]<numbers[-j]:
            index = least_num_greater_than_arg_after_index_j(len(numbers)-j-1)      # for j = 3 if is satisfied 
            numbers[index], numbers[-j-1] = numbers[-j-1], numbers[index]           # 7-3-1 is 3 so index = least_num_blah(3) the index returned should be 5
            list_to_be_sorted = numbers[-j::1]
            for _ in range(j):
                numbers.pop()
            list_to_be_sorted.sort()
            numbers.extend(list_to_be_sorted)
            # print(numbers)

            for _ in range(len(numbers)):
                print(numbers[_], end=" ")
            
            print()

            break
            



