'''
First line of the input contains an integer T denoting the number of test cases. T test cases follow.

The only line of each test case contains four space separated integers n, m, d, D.


For each test case, output -1 if there is no bipartite graph satisfying this property. 
Otherwise output m lines, each of the lines should contain two integers u, 
v denoting that there is an edge between vertex u on the left part and vertex v on the right part. 
If there can be multiple possible answers, you can print any. Note that the bipartite graph should not have multi-edges.

'''

# d and D are the linits for the degree of a point
import itertools
T = int(input())

for _ in range(T):
    n, m, d, D = map(int, input().split())
    
    if m >= n*d and m <= n*D and m<=n*n and n!=1 and m>=2*n-1:
        count = 0
        
        for i in range(n):
            for j in range(n):
                if m>0:
                    print(j+1, (i+j)%(n)+1)
                    m-=1
                    count+=1
                else:
                    break
        print(count)
        
        
    elif n==1 and m >= n*d and m <= n*D and m<=n*n and m>=2*n-1:
        print(1, 1)
    
    else:
        print(-1)
'''per = []
        per = list(itertools.permutations(range(1, n+1), 2))
        for j in range(m-n):
            print(per[j][0], per[j][1])
        '''