from sortedcontainers import SortedDict
n=int(input())
arr=[int(x) for x in input().split()]
popped = set()
if n==1:
    print(1)
    print(arr[0],0)
else:
    
    track=SortedDict()
    for i in range(n):
        curr=arr[i]
        
        if curr not in track and curr not in popped:
            track[curr]=[i,0]
        elif curr in popped:
            continue
        else:
            if track[curr][1]==0:
                track[curr][1]= i-track[curr][0]
                track[curr][0]=i
            elif (i-track[curr][0]) != track[curr][1]:
                track.pop(curr); popped.add(curr);
            elif (i-track[curr][0]) == track[curr][1]:
                track[curr][0]=i
            
    print(len(track))
    for i in track.keys():
        print(i,track[i][1])