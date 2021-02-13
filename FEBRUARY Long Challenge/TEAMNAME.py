# could take funny words in pairs and if they are 'different' then add 2 to the count of good names
# trying to improve upon the brute force method :)


t = int(input())
for _ in range(t):
    n = int(input())
   
    funny_names = list(map(str, input().split()))

    # could first make potential pairs and then check if after replacing their first letters they happen to be funny or not

    # but that was what i did the last time too and it resulted in tle

    # remember 'hell' and 'test' they did generate 'hest tell' which was a good name as 'hest' and 'tell' were not funny but 'hell' and 'test' were funny

    
    
