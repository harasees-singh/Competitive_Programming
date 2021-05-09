import sys
sys.setrecursionlimit(int(1e6))
children_counter = dict()
parent_child = dict()

final_ans=0

def DF_Traversal(parent):
    if not parent_child.get(parent):        # if not a parent
        children_counter[parent]=0
        return 0
    children=0
    for i in range(len(parent_child[parent])):
        children += 1 + DF_Traversal(parent_child[parent][i])

    children_counter[parent]=children
    return children

def DF_Value_distribution(parent, value):
    global final_ans
    final_ans+=value%MOD_val
    
    if not parent_child.get(parent):
        return 

    children_list = parent_child[parent]
    children_list.sort(reverse=True, key=lambda x:children_counter[x])
    curr = value
    for i in range(len(children_list)):
        DF_Value_distribution(children_list[i], curr)
        curr = value*(i+2)
    

MOD_val= int(1e9 + 7)
for _ in range(int(input())):
    
    final_ans=0
    children_counter={}
    parent_child={}
    n, x = map(int, input().split())
    remaining_nodes = set()
    parents_boolean = [False]*(n+1)
    for i in range(n-1):
        u, v = map(int, input().split())
        
        parents_boolean[1] = True
        if parents_boolean[u]:
            if parent_child.get(u):
                parent_child[u].append(v)
            else:
                parent_child[u] = [v]
            parents_boolean[v] = True
        elif parents_boolean[v]:
            if parent_child.get(v):
                parent_child[v].append(u)
            else: 
                parent_child[v] = [u]
            parents_boolean[u] = True
        else:
            remaining_nodes.add((u, v))
    
    to_be_removed = set()
    while(len(remaining_nodes)):
        
        for tuple_of_nodes in remaining_nodes:
            u = tuple_of_nodes[0]
            v = tuple_of_nodes[1]
            
            if parents_boolean[u]:
                # print(u, v)
                if parent_child.get(u):
                    parent_child[u].append(v)
                else:
                    parent_child[u] = [v]
                parents_boolean[v] = True
                to_be_removed.add(tuple_of_nodes)

            elif parents_boolean[v]:
                # print("elif", u, v)
                if parent_child.get(v):
                    parent_child[v].append(u)
                else: 
                    parent_child[v] = [u]
                parents_boolean[v] = True
                to_be_removed.add(tuple_of_nodes)

        remaining_nodes=remaining_nodes-to_be_removed
        to_be_removed = set()
            

        # minimum = min(u, v)
        # maximum = max(u, v)
        # if parent_child.get(minimum):
            # parent_child[minimum].append(maximum)
        # else:
            # parent_child[minimum] = [maximum]
    DF_Traversal(1)           # to count children
    # for parent in parent_child.keys():
        # print(parent, parent_child[parent])
    # print('-----------------')
    # for c in children_counter.keys():
    #     print(c, children_counter[c])
    #     print()
    DF_Value_distribution(1, x)
    print(final_ans)

