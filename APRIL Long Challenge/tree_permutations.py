# make a tree dictionary with key as node number and value as a list of 2 integers containing left child node number and right child node number
# take both a and b list as input and zip them a[i]: b[i]
# identify the permutations and for each set of nodes that were permuted check whether the permutation is good or not by traversing the tree starting from the node containing the smallest value because all the 
# larger values will definitely lie somewhere down the road.
# check recursively whether it all the elements in the permutation lie on a straight line or not.
# if yes then the flag remains True else the falg is set to False and we print '0' as the answer. 
# An ancestor of a node is any other node on the path from the node to the root. 
import sys 
import copy
sys.setrecursionlimit(1000000000)
def TraverseTheTree(index, flag, root):
    
    if index >= len(ordered_set_of_permuted_values):
        return True

    if root==None:
        return False

    if tree.get(root) == None:
        tree[root] = [None, None]

    if permuted_values[root-1] == ordered_set_of_permuted_values[index]:
        

        ans1 = TraverseTheTree(index+1, True, tree[root][0])
        ans2 = TraverseTheTree(index+1, True, tree[root][1])
        return ans1 or ans2
    else:
        return TraverseTheTree(index, True, tree[root][0]) or TraverseTheTree(index, True, tree[root][1])

    
permuted_values = list()
original_values = list()
ordered_set_of_permuted_values = list()
tree = dict()
for _ in range(int(input())):
    flag = True
    n, s = map(int, input().split())
    if n==1:
        a = int(input())
        b = int(input())
        if a==b:
            print(1)
        else:
            print(0)
        continue
    tree.clear()
    for i in range(1, n):
        parent, child = map(int, input().split())
        if tree.get(parent):
            tree[parent][1] = child
        else:
            tree[parent] = [child, None]
        
    # tree completed in memory
    original_values = list(map(int, input().split()))
    permuted_values = list(map(int, input().split()))
    original_permuted = dict(zip(original_values, permuted_values))
    # print(original_permuted, type(original_permuted))
    # permuted_original = dict(zip(permuted_values, original_values))
    set_of_values = set(original_values)
    copy_set = copy.deepcopy(set_of_values)

    i = 0
    
    while i < len(original_values) and len(set_of_values) and flag:  # stop when you have successfully divided all the elements into their respective permutations
        current_element = original_values[i]
        i+=1
        if current_element in set_of_values:
            if original_permuted[current_element] == current_element :  # but what if there are multiple copies of an element
                set_of_values.remove(current_element)
                
            else:
                ordered_set_of_permuted_values.clear()
                start = current_element
                ans = -1
                temp = start
                
                while ans != start:
                    
                    ans = original_permuted[temp]
                    if ans in copy_set:
                        set_of_values.remove(ans)
                        ordered_set_of_permuted_values.append(ans)
                        temp = ans
                    else:
                        flag = False
                        break

                # ordered_set_of_permuted_values.sort()

                '''
                debugging ahead
                '''
                #print(ordered_set_of_permuted_values)
                # now we need to traverse through the tree
                
                itera = 1
                if flag:
                    root = original_values.index(ordered_set_of_permuted_values[0]) + 1 # root is the node corres to first value in the permutation
                while flag and itera < len(ordered_set_of_permuted_values):
                    
                    if TraverseTheTree(0, True, 1):
                        flag = True
                    else:
                        flag = False
                
                    #print("value of root is ", root)
                    #print("the flag is currently ", flag)
                    itera += 1
    
    if flag:
        print(1)
    else:
        print(0)

#print(tree)
