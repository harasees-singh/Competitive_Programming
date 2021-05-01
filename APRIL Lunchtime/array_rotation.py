N=int(input())
arr= list(map(int, input().split()))
q= int(input())
queriesarr= list(map(int, input().split()))

sum1= sum(arr)

for i in range(q):


    sum_=2*sum1

    sum1 = sum_
    sum_= sum_%(10**9 + 7)


    print(sum_)