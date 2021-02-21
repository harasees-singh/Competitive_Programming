# put all the time stamps in a set
# Sample Input
# 1
# 3
# 3
# 1 2
# 2 3
# 1 3
# The first line contains a single integer T, the number of testcases, this is followed by the description of the testcases

# The first line of each testcase contains a single integer n, the number of classes scheduled
# 
# The second line of each testcase contains an integer m, the number of distinct times given.
# 
# The next n lines each contain a pair of space separated integers l,r denoting that the class that starts at time tl and ends at tr.
# 
# Output
# Print in a single line, the number of classrooms needed, i.e. the maximum number of classes that happen at the same time.

for i in range(int(input())):
	num_of_classes = int(input())
	time_stamps = int(input())
	set_of_time_stamps = dict()
	
	for _ in range(num_of_classes):
		time_interval_tuple = tuple(map(int, input().split()))
		#classes.append(time_interval)
		time_interval = list(q for q in range(time_interval_tuple[0], time_interval_tuple[1]+1))

		
		for p in range(len(time_interval)):
			if time_interval[p] in set_of_time_stamps:
				set_of_time_stamps[time_interval[p]]+=1
			else:
				set_of_time_stamps[time_interval[p]]=1
		'''if time_interval[1] in set_of_time_stamps:
									set_of_time_stamps[time_interval[1]]+=1
								else:
									set_of_time_stamps[time_interval[1]]=1'''

	print(max(set_of_time_stamps.values()))
	print(set_of_time_stamps.keys())
		

	'''min_classes_required = 1
				for time_stamp in set_of_time_stamps:
					count = 0
					for p in range(num_of_classes):
						if time_stamp <= classes[p][1] and time_stamp >= classes[p][0]:
							count+=1
					if count>min_classes_required:
						min_classes_required = count
				print(min_classes_required)'''