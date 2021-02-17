# example [1, 2, 3]
# we wish to print
# []
# [1]
# [2]
# [3]
# [1, 2]
# [2, 3]
# [1, 3]
# [1, 2, 3]
# not necessarily in the same order as above 

# need some on/off mecahnism so that each number possess both on and off states at different points of time

# we could make a list of numbers and then assume that it has some amount of subsets already 
# then we could take all it's elements and then once append a new element to them.
# then append all these new lists to the older list will older subsets 
# keep doing until you exhaust all the elements 


def Subsets(l):
    ans = [[]]
    
    
    for i in range(len(l)):
        temporary_list = ans[:]
        num = l[i]
        for j in range(len(ans)):
            temporary_list[j] = temporary_list[j] + [l[i]]
        ans = ans + temporary_list

    return ans

for i in range(int(input())):
    p = int(input())
    q = [i for i in range(1, p+1)]
    ans = Subsets(q)
    for j in range(len(ans)):
        for k in range(len(ans[j])):
            print(ans[j][k], end=" ")
        print()
    
