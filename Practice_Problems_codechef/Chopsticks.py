'''
5 2
1
3
3
9
4
'''
chopsticks = []

n, d = map(int, input().split())

for i in range(n):
    chopsticks.append(int(input()))

chopsticks.sort()

fav_pair_count = 0

paired  = False
for i in range(len(chopsticks)-1):
    if not paired and chopsticks[i+1] - chopsticks[i] <= d:
        fav_pair_count += 1
        paired = True
        continue
    paired = False

print(fav_pair_count)