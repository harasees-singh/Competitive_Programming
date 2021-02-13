'''
the given time can be converted to a format feasible for comparison so 
new plan: convert time into 24 hour format
'''

def time_format(time):
    time_24 = 0
    if time[-2:] == 'AM':
        if int(time[0]) == 1 and int(time[1]) == 2:
            time_24 += int(time[3])*10 + int(time[4])
        else:
            time_24 += int(time[0])*1000 + int(time[1])*100 + int(time[3])*10 + int(time[4])
    elif time[-2:] == 'PM':
        if int(time[0]) == 1 and int(time[1]) == 2:
            time_24 += int(time[0])*1000 + int(time[1])*100 + int(time[3])*10 + int(time[4])
        else:
            time_24 += 1200 + int(time[0])*1000 + int(time[1])*100 + int(time[3])*10 + int(time[4])
    return time_24

# print(time_format("01:45 PM"))
t = int(input())

for i in range(t):
    time = input()
    no_of_friends = int(input())
    
    new_time = time_format(time)
    for p in range(no_of_friends):
        t1, format1, t2, format2 = input().split()
        t1 = time_format(t1+" "+format1)
        t2 = time_format(t2+" "+format2)
        if t1<=new_time and t2>=new_time:
            print(1, end="")
        else:
            print(0, end="")
    
    print()
        