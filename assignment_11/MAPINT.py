streets_horizontal = {}
streets_vertical = {}
n = int(input())
for i in range(n):
    start,  end, street_name, direction = input().split()
    start = int(start)
    end = int(end)
    if direction == 'E':
        if street_name in streets_horizontal.keys():
            if streets_horizontal[street_name][-1] == start:
                
                streets_horizontal[street_name].append(end)
            else:
                streets_horizontal[street_name].insert(0, start)
                
        else:
            streets_horizontal[street_name] = [start, end]
    if direction == 'W':
        start, end = end, start
        if street_name in streets_horizontal.keys():
            if streets_horizontal[street_name][-1] == start:
                
                streets_horizontal[street_name].append(end)
            else:
                streets_horizontal[street_name].insert(0, start)
                
        else:
            streets_horizontal[street_name] = [start, end]
    if direction == 'N':
        if street_name in streets_vertical.keys():
            if streets_vertical[street_name][-1] == start:
                
                streets_vertical[street_name].append(end)
            else:
                streets_vertical[street_name].insert(0, start)
                
        else:
            streets_vertical[street_name] = [start, end]
    if direction == 'S':
        start, end = end, start
        if street_name in streets_vertical.keys():
            if streets_vertical[street_name][-1] == start:
                
                streets_vertical[street_name].append(end)
            else:
                streets_vertical[street_name].insert(0, start)
                
        else:
            streets_vertical[street_name] = [start, end]
        
    

horizontal_points = []
vertical_points = []

for i in streets_horizontal.values():
    i.pop()
    i.pop(0)
    horizontal_points = horizontal_points + i

for i in streets_vertical.values():
    i.pop()
    i.pop(0)
    vertical_points = vertical_points + i


all_points = horizontal_points + vertical_points
points_set = set(all_points)
print(len(all_points) - len(points_set))

