import sys
sys.setrecursionlimit(int(1e6))
children_counter = dict()
parent_child = dict()
MOD_val= int(1e9 + 7)
parents_boolean=[]
final_ans=0
child_parent=dict()

def DF_Traversal(parent):
    if not parent_child.get(parent):        # if not a parent
        children_counter[parent]= 0
        return 0, 1
    children=0
    leaf = 0
    for i in range(len(parent_child[parent])):
        answer = DF_Traversal(parent_child[parent][i])
        children += 1 + answer[0]
        leaf += answer[1]
        
    children_counter[parent]=leaf+children
    return children, leaf

def DFS(parent, prohibited_child):
    if not parent_child.get(parent):
        leaf_traversal(parent)
    children = parent_child[parent]
    for i in range(len(children)):
        if children[i] == prohibited_child:
            continue
        else:
            DFS(children[i], -1)
        

def recursion(parent, prohibited_child, node_value, sum):
    if parent==1 and len(parent_child[1]==1):
        return sum
    if len(parent_child[parent])==1:
        parent1 = child_parent[parent]
        prohibited_child1 = parent
        sum += node_value
        return recursion(parent1, prohibited_child1, node_value, sum)

    for i in range(len(parent_child[parent])):
        if parent_child[parent][i] != prohibited_child:
            DFS(parent_child[parent][i], -1)


visited=[]
def leaf_traversal(i):
    if not visited[i]:
        visited[i] = True
        node_value = 1
        sum = 1 
        parent = child_parent[i]
        recursion(parent, i, 1, 1)
    return


   


for _ in range(int(input())):
    child_parent={}
    final_ans=0
    children_counter={}
    parent_child={}
    n, x = map(int, input().split())
    remaining_nodes = set()
    visited=[False]*(n+1)
    parents_boolean = [False]*(n+1)
    for i in range(n-1):
        u, v = map(int, input().split())
        
        parents_boolean[1] = True
        if parents_boolean[u]:
            if parent_child.get(u):
                parent_child[u].append(v)
                
            else:
                parent_child[u] = [v]
            child_parent[v] = u 
            parents_boolean[v] = True
        elif parents_boolean[v]:
            if parent_child.get(v):
                parent_child[v].append(u)
            else: 
                parent_child[v] = [u]
            child_parent[u] = v
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
                child_parent[v] = u
                parents_boolean[v] = True
                to_be_removed.add(tuple_of_nodes)

            elif parents_boolean[v]:
                # print("elif", u, v)
                if parent_child.get(v):
                    parent_child[v].append(u)
                else: 
                    parent_child[v] = [u]
                child_parent[u]= v
                parents_boolean[v] = True
                to_be_removed.add(tuple_of_nodes)

        remaining_nodes=remaining_nodes-to_be_removed
        to_be_removed = set()

        for i in range(len(parents_boolean)):
            if not parents_boolean[i] and not visited[i]:    
                leaf_traversal(i)
                break