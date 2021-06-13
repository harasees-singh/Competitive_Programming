n=int(input())
arr=[int(x) for x in input().split()]
popped = [0]*int(1e6)
if n==1:
    print(1)
    print(arr[0],0)
else:
    
    track={}
    for i in range(n):
        curr=arr[i]
        
        if curr not in track and not popped[curr]:
            track[curr]=[i,0]
        elif popped[curr]:
            continue
        else:
            if track[curr][1]==0:
                track[curr][1]= i-track[curr][0]
                track[curr][0]=i
            elif (i-track[curr][0]) != track[curr][1]:
                track.pop(curr); popped[curr]=1;
            elif (i-track[curr][0]) == track[curr][1]:
                track[curr][0]=i
            
    # print(track)
    # print(len(track))
    keys=[]
    for i in track:
        keys.append(i)
    keys.sort()
    print(len(keys))
    for i in keys:
        print(i,track[i][1])