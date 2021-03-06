for _ in range(int(input())):
    string = input()
    count = 0
    encounter = False
    for i in string:
        if i == '1' and encounter == False:
            count += 1
            encounter = True
        elif i=='0':
            encounter = False
    print(count)