# could take funny words in pairs and if they are 'different' then add 2 to the count of good names
# trying to improve upon the brute force method :)
# import time

# could first make potential pairs and then check if after replacing their first letters they happen to be funny or not

# but that was what i did the last time too and it resulted in tle

# remember 'hell' and 'test' they did generate 'hest tell' which was a good name as 'hest' and 'tell' were not funny but 'hell' and 'test' were funny

t = int(input())

for _ in range(t):
    n = int(input())

    s = input().split()
    left = {}

    for x in s:
        if x[1:] not in left:
            left[x[1:]] = {x[0]}
        else:
            left[x[1:]].add(x[0])
    total = 0

    for k1,v1 in left.items():
        for k2,v2 in left.items():
            if k1 != k2:
                total += len(v1.difference(v2))*len(v2.difference(v1))

    print(total)