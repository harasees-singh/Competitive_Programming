# make a tree dictionary with key as node number and value as a list of 2 integers containing left child node number and right child node number
# take both a and b list as input and zip them a[i]: b[i]
# identify the permutations and for each set of nodes that were permuted check whether the permutation is good or not by traversing the tree starting from the node containing the smallest value because all the 
# larger values will definitely lie somewhere down the road.
# check recursively whether it all the elements in the permutation lie on a straight line or not.
# if yes then the flag remains True else the falg is set to False and we print '0' as the answer. 
for _ in range(int(input())):
    flag = True
    n, s = map(int, input().split())
    tree = dict()
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
    i = 0
    
    while i < len(original_values) and len(set_of_values):  # stop when you have successfully divided all the elements into their respective permutations
        current_element = original_values[i]
        i+=1
        if current_element in set_of_values:
            if original_permuted[current_element] == current_element :
                set_of_values.remove(current_element)
                
            else:
                ordered_set_of_permuted_values = list()
                start = current_element
                ans = -1
                temp = start
                
                while ans != start:
                    ans = original_permuted[temp]
                    set_of_values.remove(ans)
                    ordered_set_of_permuted_values.append(ans)
                    temp = ans

                ordered_set_of_permuted_values.sort()

                '''
                debugging ahead
                '''
                print(ordered_set_of_permuted_values)
                # now we need to traverse through the tree
                
                itera = 1
                root = original_values.index(ordered_set_of_permuted_values[0]) + 1 # root is the node corres to first value in the permutation
                while flag and itera < len(ordered_set_of_permuted_values):
                    

                    while True:
                        if original_values[root-1] == ordered_set_of_permuted_values[itera]:   # found the node now move forward in search of next node
                            break
                        
                        current_node_value = ordered_set_of_permuted_values[itera]  # we need to search the tree for this value
                        if tree.get(root):
                            child1, child2 = tree[root]
                        else:
                            child1, child2 = None, None
                        

                        if current_node_value > original_values[root-1]: # original_values[root-1] corresponds to the value written on the current node and tells us whether we need to go to the right or to the left
                            if child1 and child2:
                                ValueOfChild1 = original_values[child1 - 1]
                                ValueOfChild2 = original_values[child2 - 1]
                                if ValueOfChild1 > ValueOfChild2:
                                    root = child1
                                else:
                                    root = child2
                            elif child1:
                                root = child1
                            else:
                                # tree traversal complete 
                                flag = False
                                break
                        else:
                            if child1 and child2:
                                ValueOfChild1 = original_values[child1 - 1]
                                ValueOfChild2 = original_values[child2 - 1]
                                if ValueOfChild1 > ValueOfChild2:
                                    root = child2
                                else:
                                    root = child1
                            elif child1: # child 2 is None
                                root = child1
                            else:       # no children
                                # tree traversal complete 
                                flag = False
                                break
                    print("value of root is ", root)
                    print("the flag is currently ", flag)
                    itera += 1
      
        

    if flag:
        print(1)
    else:
        print(0)

#print(tree)