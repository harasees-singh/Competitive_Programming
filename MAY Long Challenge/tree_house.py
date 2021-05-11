import sys
sys.setrecursionlimit(int(1e6))
children_counter = dict()
parent_child = dict()
MOD_val= int(1e9 + 7)
parents_boolean = []
final_ans=0

def DF_Traversal(parent):
    if not parent_child.get(parent):        # if not a parent
        children_counter[parent]= (0, 0)
        return 0, 1
    children=0
    leaf = 0
    for i in range(len(parent_child[parent])):
        answer = DF_Traversal(parent_child[parent][i])
        children += 1 + answer[0]
        leaf += answer[1]
        
    children_counter[parent]=(children, leaf)
    return children, leaf

def DF_Value_distribution(parent, value):
    global final_ans
    final_ans+=value%MOD_val
    final_ans=final_ans%MOD_val
    
    if not parent_child.get(parent):
        return 

    children_list = parent_child[parent]
    children_list.sort(reverse=True, key=lambda x:children_counter[x])              # this is not causing tle
    curr = value
    for i in range(len(children_list)):
        DF_Value_distribution(children_list[i], curr)
        curr += value
    
# def put_them_in_the_tree(tuple_):
#     u = tuple_[0]
#     v = tuple_[1]
    
#     if parents_boolean[u]:
#         # print(u, v)
#         if parent_child.get(u):
#             parent_child[u].append(v)
#         else:
#             parent_child[u] = [v]
#         parents_boolean[v] = True
        

#     elif parents_boolean[v]:
#         # print("elif", u, v)
#         if parent_child.get(v):
#             parent_child[v].append(u)
#         else: 
#             parent_child[v] = [u]
#         parents_boolean[v] = True
        

for _ in range(int(input())):
    
    final_ans=0
    children_counter={}
    parent_child={}
    n, x = map(int, input().split())
    remaining_nodes = set()
    parents_boolean = [False]*(n+1)
    nodes_left_for_mapping = dict()
    adjacency_list = [[] for i in range(n+1)]
    for i in range(n-1):
        u, v = map(int, input().split())
        adjacency_list[u].append(v)
        adjacency_list[v].append(u)
    for i in range(1, n+1):
        parents_boolean[i]=True
        parent_child[i]=[]
        for children in range(len(adjacency_list[i])):
            if not parents_boolean[adjacency_list[i][children]]:
                parent_child[i].append(adjacency_list[i][children])
    


        # parents_boolean[1] = True
        # if parents_boolean[u]:
        #     if parent_child.get(u):
        #         parent_child[u].append(v)
        #     else:
        #         parent_child[u] = [v]
        #     parents_boolean[v] = True
        # elif parents_boolean[v]:
        #     if parent_child.get(v):
        #         parent_child[v].append(u)
        #     else: 
        #         parent_child[v] = [u]
        #     parents_boolean[u] = True
        
        # else:
        #     # remaining_nodes.add((u, v))
        #     nodes_left_for_mapping[u]=(u,v)
        #     nodes_left_for_mapping[v]=(u,v)

        # if u in nodes_left_for_mapping:
        #     put_them_in_the_tree(nodes_left_for_mapping[u])

        # if v in nodes_left_for_mapping:
        #     put_them_in_the_tree(nodes_left_for_mapping[v])

            
    
    # to_be_removed = set()
    # while(len(remaining_nodes)):
        
    #     for tuple_of_nodes in remaining_nodes:
    #         u = tuple_of_nodes[0]
    #         v = tuple_of_nodes[1]
            
    #         if parents_boolean[u]:
    #             # print(u, v)
    #             if parent_child.get(u):
    #                 parent_child[u].append(v)
    #             else:
    #                 parent_child[u] = [v]
    #             parents_boolean[v] = True
    #             to_be_removed.add(tuple_of_nodes)

    #         elif parents_boolean[v]:
    #             # print("elif", u, v)
    #             if parent_child.get(v):
    #                 parent_child[v].append(u)
    #             else: 
    #                 parent_child[v] = [u]
    #             parents_boolean[v] = True
    #             to_be_removed.add(tuple_of_nodes)

    #     remaining_nodes=remaining_nodes-to_be_removed
    #     to_be_removed = set()
            

    DF_Traversal(1)           # to count children
    # print(children_counter)
    
    DF_Value_distribution(1, x)
    print(final_ans)

