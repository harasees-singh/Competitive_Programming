t = int(input())
for _ in range(t):
    string = input()
    # print(string)
    count = 0
    encounter = False
    i = 0
    for i in range(len(string)):
        if string[i] == '1' and encounter == False:
            enounter = True
            count += 1
            
        elif string[i] == '0':
            enounter = False
        
    print(count)
    