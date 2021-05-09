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
    for i in range(n-1):
        u, v = map(int, input().split())
        minimum = min(u, v)
        maximum = max(u, v)
        if parent_child.get(minimum):
            parent_child[minimum].append(maximum)
        else:
            parent_child[minimum] = [maximum]
    DF_Traversal(1)           # to count children
    # for parent in parent_child.keys():
        # print(parent, parent_child[parent])
    # print('-----------------')
    # for c in children_counter.keys():
    #     print(c, children_counter[c])
    #     print()
    DF_Value_distribution(1, x)
    print(final_ans)

