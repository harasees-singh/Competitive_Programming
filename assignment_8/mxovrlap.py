# could first make a list
# then loop, take input, get the two time stamps and then append 1 to the list present at an index = time stamp corres to start and -1 for time stamp corres to end
# after the list is ready make another list which contains the prefix additions of the original list 
# find the prefix addition in the following way
# at any idex i the sum would be the already existing sum + count of 1s at that index in the original 2d list and them decrement the sum by the count of -1s and repeat

'''for i in range(int(input())):
	num_of_classes = int(input())
	time_stamps = int(input())
	set_of_time_stamps = dict()
	
	for _ in range(num_of_classes):
		time_interval_tuple = tuple(map(int, input().split()))
		#classes.append(time_interval)
		time_interval = list(q for q in range(time_interval_tuple[0], time_interval_tuple[1]+1))
'''

for i in range(int(input())):
    list_of_time_stamps = {}
    #prefix_sums = [0 for i in range(10**6)]
    prefix_sums = set()
    

    num_of_classes = int(input())
    
    time_stamps = int(input())

    set_of_time_stamps = dict()

    for _ in range(num_of_classes):
        time_interval_tuple = tuple(map(int, input().split()))
        
        start = time_interval_tuple[0]
        end = time_interval_tuple[1]

        list_of_time_stamps[start][0] += 1
        list_of_time_stamps[end][1] -= 1
    # poppping zeroes 
    res = [] 
    [res.append(x) for x in list_of_time_stamps.values() if x != [0, 0]] 
    
    # calculating prefix sums
    sum = 0
    for j in range(len(res)):
        sum = sum+res[j][0]
        prefix_sums.add(sum)

        sum += res[j][1]

    print(max(prefix_sums))