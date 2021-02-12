'''
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers W1,W2,…,WN.
The third line contains N space-separated integers L1,L2,…,LN.

ex
2 1 4 3
4 1 2 4

1 4 3 _ 2               jump 1 of 4 units
1 _ 3 4 2               jump 2 of 2 units
1 _ 3 _ 2 4             jump 3 of 2 units
1 _ 3 _ 2 _ _ 4         jump 4 of 2 units # now 4 is at the required position
1 _ _ _ 2 _ 3 4         jump 5 of 4 units 

total jumps = 5
find the index of the second lowest weight and the lowest weight and check if they are arranged properly or not and then do the same for the rest
'''

# the idea is to first move the second lowest weight to the second position and then do the same for every other weight. this ensures that the heaviest weight frog moves at the end and in a fashion such that minimum jumps are involved


# print(positioning)
t = int(input())
for _ in range(t):
    positioning = [[0, 0] for i in range(20)]
    n = int(input())
    weights = list(map(int, input().split()))
    jump_lengths = list(map(int, input().split()))
    for i in range(len(weights)):
        positioning[i][0], positioning[i][1] = weights[i], jump_lengths[i]

    # no problem till here

    reference_positioning = positioning[:]
    positioning_ = positioning[:]
    reference = weights[:]
    weights.sort()
    # print(weights)
    # print(reference)
    jump_count = 0
    for i in range(len(weights)-1):
        index_of_smaller = reference.index(weights[i])
        #print(index_of_smaller)
        index_of_greater = reference.index(weights[i+1])
        #print(index_of_greater)
        jump = reference_positioning[index_of_greater][1]
        temp = index_of_greater
        
        while index_of_smaller >= index_of_greater:
            index_of_greater+= jump
            jump_count+=1
        
        positioning_[index_of_greater][0] = positioning[temp][0]
    print(jump_count)
    
        
        
        