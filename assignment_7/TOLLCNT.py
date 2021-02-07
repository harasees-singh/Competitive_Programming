''' 
The first line contains an integer n, the total number of events.

This is followed by the description of n events, each event contains three lines.

The first line contains a string, which is either "entry" or "exit"

The second line contains a string which denotes the license plate of the vehicle

The third line represents an integer t, which denotes the time of the day (given as seconds from 12:00 AM) that the event occurs.

The events are provided in ascending order of the time at which they occurred.


    

'''
import math


n = int(input())
data = {}
collection = 0
for _ in range(n):
    action = input()
    if action == 'entry':
        license_number = input()
        data[license_number] = int(input())
    elif action == 'exit':
        license_number = input()
        time = int(input())
        elapsed = time - data[license_number]
        # print('e', elapsed)
        payable = elapsed/60
        
        payable = math.ceil(elapsed/60) - 1 # first hour is mandatory
        # print('p', payable)
        if payable >= 0:
            collection += (60 + 30*payable) 
    
print(collection)
# print(data)