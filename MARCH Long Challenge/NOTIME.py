n, h, x = map(int, input().split())
available_times = list(map(int, input().split()))
available_times.sort()
if available_times[-1] + x >= h:
    print('YES')
else:
    print('NO')