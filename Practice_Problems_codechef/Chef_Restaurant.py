'''
1
4 5
5 7
9 10
2 3
20 30
5
6
7
35
1
'''
def BinarySearch(tuples, target):
    left = 0 
    right = len(tuples)-1
    ans = -1
    while left <= right:
        
        mid = (left + right)//2         # mid is the index of the target tuple
        
        if tuples[mid][0] > target:
            right = mid - 1 
            ans = mid
        else:
            left = mid + 1
    return ans                  # if ans == -1 then it will point to the last tuple 

        
            
    
for _ in range(int(input())):
    n, m = map(int, input().split())
    tuples = []
    for i in range(n):
        tuples.append(tuple(map(int, input().split())))
    
    #print(tuples)
    tuples.sort()
    i=0
    for i in range(m):
        time = int(input())
        ans = BinarySearch(tuples, time)
        if ans == 0:
            print(tuples[0][0] - time)
        else:
            if ans == -1:
                if time >= tuples[-1][0] and time < tuples[-1][1]:
                    print(0)
                else:
                    print(-1)
            else:
                just_previous_tuple = tuples[ans - 1]
                if just_previous_tuple[1] > time:
                    print(0)
                else:
                    print(tuples[ans][0] - time)
        
        
    
        