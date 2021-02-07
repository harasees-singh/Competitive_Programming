T = int(input())

for _ in range(T):
    N, H, Y1, Y2, L = map(int, input().split())
    
    count = 0
    
    while(N > 0):
        
        obstacles = list(map(int, input().split()))
        if obstacles[0] == 1 and H - Y1 <= obstacles[1]:
            count+=1
        elif obstacles[0]==2 and Y2 >= obstacles[1]:
            count+=1
        else:
            if L > 1:
                L-=1
                count+=1
            else:
                break        
        N-=1
    print(count)
    # y1 is duck and y2 is jump x is the height of the barrier and L is the number of times it can destroy the barrier with alchemy in case
    # it is unable to duck or jump past it 
    # print out the number of barriers boy can pass in each test case
    # type 1 barrier will need you to duck such that H - y1 <= x
    # type 2 barrier will need you to jump at least x amount such that y2 >= x