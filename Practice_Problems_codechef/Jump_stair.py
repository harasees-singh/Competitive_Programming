count = 0
def jump_stairs(n, x):
    global count
    global initial_stair
    if x == 0:
        if n == 0:
            count += 1 
        else:
            return
    else:
        if n>0:
            jump_stairs(n-1, x-1)
        if n>1:
            jump_stairs(n-2, x-1)
        if n>2:
            jump_stairs(n-3, x-1)
        if n<initial_stair:
            jump_stairs(n+1, x-1)
        if n<initial_stair-1:
            jump_stairs(n+2, x-1)
        if n<initial_stair-2:
            jump_stairs(n+3, x-1)
        jump_stairs(n, x-1)

for _ in range(int(input())):
    count = 0
    n, x = map(int, input().split())
    initial_stair = n
    jump_stairs(n, x)
    print(count)
