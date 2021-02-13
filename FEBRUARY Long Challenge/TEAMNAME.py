# could take funny words in pairs and if they are 'different' then add 2 to the count of good names

t = int(input())
for _ in range(t):
    n = int(input())
   
    funny_names = list(map(str, input().split()))
    funny_names.sort()
    # print(funny_names)

    # names_after_removing_the_starting_character = [funny_names[i][1:] for i in range(n)]
    # starting_characters = [funny_names[i][0] for i in range(n)]

    # names_after_removing_the_starting_character = set(names_after_removing_the_starting_character)
    # names_after_removing_the_starting_character = list(names_after_removing_the_starting_character)

    count = 0
    
    for i in range(n):
        for j in range(i+1, n):
            if (funny_names[i][0] != funny_names[j][0]) and (funny_names[i][1:] != funny_names[j][1:]):     # 'different'
                if funny_names[i][0]+funny_names[j][1:] not in funny_names and funny_names[j][0]+funny_names[i][1:] not in funny_names:
                    count+=2
    print(count)