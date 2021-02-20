# hear my idea 
# base: recursion

# m*n (row*column)
# first make a function which appends the positions of b, c, and r (row, column) in a list

# then pass an arg i into the recursive function which is such that i%m gives you the column number and i//m gives you the row number


lenght_word_dictionary = {}

set_of_elements = {'b', 'c', 'r'}

list_of_positions = []
crossword = []
words = []
n, m = map(int, input().split())

for i in range(n):
    crossword.append(input())
    #crossword.append(list(map(str, input().split())))

answer = crossword[:]       # this is the deep copy of crossword in which i will fill the answers


number_of_words = int(input())

for i in range(number_of_words):
    word = input()
    words.append(word)
    lenght_word_dictionary[len(word)] = word





def position_finder():
    for i in range(n*m):
        row = i//m 
        column = i%m

        # print(row, column)
        if crossword[row][column] in set_of_elements:
            list_of_positions.append((row, column))


position_finder()
list_of_positions = tuple(list_of_positions)


def print_the_answer():
    pass


# remeber a mapping fails due to 4 reasons:
    # 1) there were already some letters sitting in those positions and they didn't match
    # 2) no word was found with the required word length
    # 3) we hit the wall (already encounted for)
    # 4) there is already a word sitting in the same row (will be encounted for in a future update)

def mapped_successfully_right(i):

    elements_mapped_successfully = set()            # will store the positions of the elements that will be mapped

    row, column = list_of_positions[i][0], list_of_positions[i][1]
    count = 1
    i = column+1
    while i<m and crossword[row][i] != 'r' or crossword[row][i] != 'b':
        if crossword[row][i] == '#':
            return False        # if we hit the wall before ever encountering a 'b' or an 'r' then that means the mapping will never succeed 
        count+=1
        i+=1
    count+=1

    length_of_word = count

    if length_of_word in lenght_word_dictionary.values():
        potential_candidate = lenght_word_dictionary[length_of_word]
    else:
        return False


    # now we will do the potential mapping
    

    for j in range(length_of_word):
        if answer[row][column] != '.' and answer[row][column] != potential_candidate[j]:
            return False
        
        else:
            answer[row][column] = potential_candidate[j]
            elements_mapped_successfully.add((row, column))
        
        column+=1
        
    return True, elements_mapped_successfully                          # we return True meaning the the mapping was successful and the positions where we did the mapping
            


def mapped_successfully_left(i):

    elements_mapped_successfully = set()            # will store the positions of the elements that will be mapped

    row, column = list_of_positions[i][0], list_of_positions[i][1]
    count = 1
    i = column+1
    while i>=0 and crossword[row][i] != 'r' or crossword[row][i] != 'b':
        if crossword[row][i] == '#':
            return False        # if we hit the wall before ever encountering a 'b' or an 'r' then that means the mapping will never succeed 
        count+=1
        i-=1                    # decrement i because we are moving in the left direction
    count+=1

    length_of_word = count


    if length_of_word in lenght_word_dictionary.values():
        potential_candidate = lenght_word_dictionary[length_of_word]
    else:
        return False

    for j in range(length_of_word):
        if answer[row][column] != '.' and answer[row][column] != potential_candidate[j]:
            return False
        
        else:
            answer[row][column] = potential_candidate[j]            # here we do the mapping
            elements_mapped_successfully.add((row, column))
        
        column-=1
        

    return True, elements_mapped_successfully                          # we return True meaning the the mapping was successful and the positions where we did the mapping
            
    

def mapped_successfully_up(i):

    elements_mapped_successfully = set()            # will store the positions of the elements that will be mapped

    row, column = list_of_positions[i][0], list_of_positions[i][1]
    count = 1
    i = row-1
    while i>=0 and crossword[i][column] != 'r' or crossword[i][column] != 'b':
        if crossword[i][column] == '#':
            return False        # if we hit the wall before ever encountering a 'b' or an 'r' then that means the mapping will never succeed 
        count+=1
        i-=1                    # decrement i because we are moving in the left direction
    count+=1

    length_of_word = count


    if length_of_word in lenght_word_dictionary.values():
        potential_candidate = lenght_word_dictionary[length_of_word]
    else:
        return False

    for j in range(length_of_word):
        if answer[row][column] != '.' and answer[row][column] != potential_candidate[j]:
            return False
        
        else:
            answer[row][column] = potential_candidate[j]            # here we do the mapping
            elements_mapped_successfully.add((row, column))
        
        row-=1
        

    return True, elements_mapped_successfully                          # we return True meaning the the mapping was successful and the positions where we did the mapping
            

def mapped_successfully_down(i):
    
    elements_mapped_successfully = set()            # will store the positions of the elements that will be mapped

    row, column = list_of_positions[i][0], list_of_positions[i][1]
    count = 1
    i = row+1
    while i<n and crossword[i][column] != 'r' or crossword[i][column] != 'b':
        if crossword[i][column] == '#':
            return False        # if we hit the wall before ever encountering a 'b' or an 'r' then that means the mapping will never succeed 
        count+=1
        i+=1
    count+=1

    length_of_word = count

    if length_of_word in lenght_word_dictionary.values():
        potential_candidate = lenght_word_dictionary[length_of_word]
    else:
        return False


    # now we will do the potential mapping
    

    for j in range(length_of_word):
        if answer[row][column] != '.' and answer[row][column] != potential_candidate[j]:
            return False
        
        else:
            answer[row][column] = potential_candidate[j]
            elements_mapped_successfully.add((row, column))
        
        row+=1
        
    return True, elements_mapped_successfully                          # we return True meaning the the mapping was successful and the positions where we did the mapping
            

def remove_the_mapping(i, elements_mapped_successfully):
    for point in elements_mapped_successfully:
        row = point[0]
        column = point[1]
        answer[row][column] = '.'
    


def crossword_ripper(i):        # i corressponds to the index of the tuple where row, column of one of b, c, r is stored
    if i == len(list_of_positions):
        print(answer)
        exit(0)
    
    if list_of_positions[i] == 'r':

        were_mapped_successfully_right, elements_mapped_successfully_right = mapped_successfully_right(i)
        were_mapped_successfully_left, elements_mapped_successfully_left = mapped_successfully_left(i)

        if were_mapped_successfully_right:
            crossword_ripper(i+1)

            remove_the_mapping(i, elements_mapped_successfully_right)
        
        if were_mapped_successfully_left:
            crossword_ripper(i+1)

            remove_the_mapping(i, elements_mapped_successfully_left)
        return                          # if mapping fails go back to the previous step 

    if list_of_positions[i] == 'c':

        were_mapped_successfully_up, elements_mapped_successfully_up = mapped_successfully_up(i)
        were_mapped_successfully_down, elements_mapped_successfully_down = mapped_successfully_down(i)

        if were_mapped_successfully_down:
            crossword_ripper(i+1)

            remove_the_mapping(i, elements_mapped_successfully_down)
        
        if were_mapped_successfully_up:
            crossword_ripper(i+1)

            remove_the_mapping(i, elements_mapped_successfully_up)

        return

    if list_of_positions[i] == 'b':

        were_mapped_successfully_up, elements_mapped_successfully_up = mapped_successfully_up(i)

        if were_mapped_successfully_up:

            were_mapped_successfully_right, elements_mapped_successfully_right = mapped_successfully_right(i)
            were_mapped_successfully_left, elements_mapped_successfully_left = mapped_successfully_left(i)

            if were_mapped_successfully_right:
                crossword_ripper(i+1)

                remove_the_mapping(i, elements_mapped_successfully_right)
        
            if were_mapped_successfully_left:
                crossword_ripper(i+1)

                remove_the_mapping(i, elements_mapped_successfully_left)
            return                          # if mapping fails go back to the previous step 

    
        
        were_mapped_successfully_down, elements_mapped_successfully_down = mapped_successfully_down(i)

        if were_mapped_successfully_down:

            were_mapped_successfully_right, elements_mapped_successfully_right = mapped_successfully_right(i)
            were_mapped_successfully_left, elements_mapped_successfully_left = mapped_successfully_left(i)
            
            if were_mapped_successfully_right:
                crossword_ripper(i+1)

                remove_the_mapping(i, elements_mapped_successfully_right)
        
            if were_mapped_successfully_left:
                crossword_ripper(i+1)

                remove_the_mapping(i, elements_mapped_successfully_left)
            return                          # if mapping fails go back to the previous step 

        return


print(list_of_positions)
crossword_ripper(0)    

# print(answer)
# print(crossword)
# 


# print(crossword[0][1])
# position_finder()
# print(list_of_positions)

