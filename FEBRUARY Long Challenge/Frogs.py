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

# for frog sort you need to find a method such that you can loop through a list or someting and then whenver an element with higher index is lesser than an element with a lower index you need to do something such that this issue is resolved
# now we just need to find this kind of code
# the problem is created by all the zeroes that are created on the way when you move an element from it's original position we could pop that position 
# instead of using a list to do all this we could use some other logic

arr = [[0, 0, 0] for _ in range(100)]
weights = list(map(int, input().split()))
lengths = list(map(int, input().split()))

positioning = [0 for _ in range(100)]

for i in range(len(weights)):
    arr[i][0], arr[i][1] = weights[i], lengths[i]

for i in range(100):
    if arr[i][0] > arr[i+1][0]:
        temp = i
        temp +=arr[i][2]      # index to be increased by the jump size
        while positioning[temp] != 0:
            temp += arr[i][2]

        positioning[temp] = arr[i][0]
        
        
        
        '''if positioning[temp] == 0:            
            positioning[temp] = arr[i][0] # updating the positioning list so that we have an idea of position of all the frogs at the end
        else:
            temp+=arr[i][2]
            positioning[temp] = arr[i][0]'''

        

