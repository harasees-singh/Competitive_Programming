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


# hear my latest idea. what we could do is that we could isert the required index of every frog at arr[i][2] and then we will have an idea of where every frog has to be 
# then we could loop through the list required no of times such that no 2 frogs have the same required index 

t = int(input())
for _ in range(t):
    n = int(input())
    q=100

    arr = [[0, 0, 0] for _ in range(q)]
    weights = list(map(int, input().split()))
    lengths = list(map(int, input().split()))

    # positioning = [0 for _ in range(100)]

    for i in range(len(weights)):
        arr[i][0], arr[i][1], arr[i][2] = weights[i], lengths[i], i

    count = 0

    for _ in range(200):
        for i in range(q-1):
            
            if arr[i][0] > arr[i+1][0]:
                while arr[i][2]< arr[i+1][2]:
                    arr[i][2]+=arr[i][1]            # the expected position will be incremented by 'jump length' until it is greater than the expected position of the lighter frog
                    count+=1

                for p in range(len(arr)):           # to resolve 2 frogs at the same position
                    if arr[i][2]==arr[p][2] and i!=p:
                        if arr[i][0]>arr[p][0]:
                            arr[i][2]+=arr[i][1]
                            count+=1
                        else:
                            arr[p][2]+=arr[p][1]        
                            count+=1

    print(count)
 
        

