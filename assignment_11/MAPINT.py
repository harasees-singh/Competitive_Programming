streets_horizontal = {}
streets_vertical = {}
n = int(input())
for i in range(n):
    start,  end, street_name, direction = input().split()
    start = int(start)
    end = int(end)
    if direction == 'E' or direction == 'W':
        if street_name in streets_horizontal.keys():
            streets_horizontal[street_name].add(start)
            streets_horizontal[street_name].add(end)
        else:
            streets_horizontal[street_name] = {start, end}
    else:
        if street_name in streets_vertical.keys():
            streets_vertical[street_name].add(start)
            streets_vertical[street_name].add(end)
        else:
            streets_vertical[street_name] = {start, end}

print(streets_horizontal)
print(streets_vertical)     


horizontal_points = set()
vertical_points = set()

for i in streets_horizontal.values():
    p, q = min(i), max(i)
    i.remove(p)
    i.remove(q)
    horizontal_points = horizontal_points | i

for i in streets_vertical.values():
    p, q = min(i), max(i)
    i.remove(p)
    i.remove(q)
    vertical_points = vertical_points | i

all_points = list(horizontal_points) + list(vertical_points)
points_set = set(all_points)
print(len(all_points) - len(points_set))
#print(horizontal_points)
