# could take funny words in pairs and if they are 'different' then add 2 to the count of good names
# trying to improve upon the brute force method :)
# import time
import itertools 
t = int(input())
# time_start = time.time()
for _ in range(t):
    n = int(input())
    
    funny_names = set(map(str, input().split()))

    # could first make potential pairs and then check if after replacing their first letters they happen to be funny or not

    # but that was what i did the last time too and it resulted in tle

    # remember 'hell' and 'test' they did generate 'hest tell' which was a good name as 'hest' and 'tell' were not funny but 'hell' and 'test' were funny

    funny_names_pairs = tuple(itertools.combinations(funny_names, 2))
    count=0

    for i in range(len(funny_names_pairs)):
        if funny_names_pairs[i][0][0]!=funny_names_pairs[i][1][0] and funny_names_pairs[i][0][1:]!=funny_names_pairs[i][1][1:]:
            if funny_names_pairs[i][0][0]+funny_names_pairs[i][1][1:] not in funny_names and funny_names_pairs[i][1][0]+funny_names_pairs[i][0][1:] not in funny_names:
                count+=2
            '''if time.time()-time_start>=9.99:
                print(count)
    '''
    print(count)
    
    
