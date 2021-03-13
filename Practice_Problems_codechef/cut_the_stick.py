n = int(input())
li = list(map(int, input().split()))
li.sort()
order_frequency = dict()
order = 0
i = 0
while i < len(li) - 1:
    count = 1
    while i < len(li) - 1 and li[i] == li[i+1]:
        count += 1 
        i += 1
    if count > 0:
        order_frequency[order] = count 
        order += 1 
    i += 1

current_length = len(li)
print(current_length)
for itera in range(len(order_frequency.keys())):
    ans = current_length - order_frequency[itera]
    if ans != 0:
        print(ans)
    current_length -= order_frequency[itera]
    