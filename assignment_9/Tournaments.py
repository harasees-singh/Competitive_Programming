'''
4
1 3 2 3
'''
# using sets this time
import copy

def Intersection_parity(a, b):
    if len(a | b) < len(a) + len(b):
        return False
    return True

# this function will take the list and make pairs of the sets present in it
def modify_list(li):
    modified_list = []
    for i in range(0, len(li)-1, 2):
        modified_list.append(li[i] | li[i+1])       # bitwise or (union of sets)
    return modified_list




n = int(input())
li = list(map(int, input().split()))

for i in range(n):
    li[i] = {li[i]}

# print(li)
profitable_matches = 0
j = 0
match_count = n-1


# gathering my thoughts 
# need to make pairs and keep making pairs 
# number of times i need to make pairs should be n-1
while match_count:
    for i in range(0, (n)//2**j, 2):
        #print(i, i+1)
        #print(li)
        if len(li) == 1:
            match_count += 1
            continue
        else:
            pass
        parity = Intersection_parity(li[i], li[i+1])
        if parity:
            profitable_matches += 1
        

    #print(profitable_matches)
    li = copy.deepcopy(modify_list(li))
    #print(li)
    match_count -= 1
    j += 1
    
print(profitable_matches)
