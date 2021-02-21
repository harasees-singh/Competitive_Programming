import copy


elements_to_be_mapped = {"a", 'b', 'c', 'd', 'e', 'f', 'g', 'h'}
answer = list()
encryptions = list()
actual_words = list()
mapping = dict()

n = int(input())
for i in range(n):
	actual_words.append(input())


encryptions = list(map(str, input().split()))


copy_ = dict()

def encryption_decipher(i):
	

    if i == len(encryptions):
        #print("printing the correct mapping now ")
        #print(mapping)
        answer.append(copy.deepcopy(mapping))
        
        return     
	
    else:
        #print("the value of i or the depth of recursion is", i)
        for j in range(len(actual_words)):
            mapping_was_successful = False
            elements_that_were_mapped = set()
            
            if len(encryptions[i])==len(actual_words[j]):
                #print(encryptions[i])
                #print(actual_words[j])
                mapping_was_successful, elements_that_were_mapped = do_the_mapping(encryptions[i], actual_words[j]) # do_the_mapping() will return True if the mapping was successful else false and also return all the elements that were mapped 
                #print(mapping)

            if mapping_was_successful:
                encryption_decipher(i+1)
                

            remove_the_mapping(encryptions[i], elements_that_were_mapped) # this will remove the current mapping
			
            # if the for loop does not work that implies no mapping takes place and this means we were on the wrong track 
            # so now we need to return
            # when we hit back to line 39 the interpreter will encounter the line 41 and remove the mapping and the j loop will continue
            
        return



def do_the_mapping(string1, string2):
    elements_that_were_mapped = set()
    for j in range(len(string1)):
        if string1[j] in mapping.keys() and string1[j] in elements_to_be_mapped:
            if mapping[string1[j]] != string2[j]:
                return False, elements_that_were_mapped
        else:
            if string1[j] in elements_to_be_mapped:
                if string1[j] not in mapping.keys() and string2[j] not in mapping.values():
                    mapping[string1[j]] = string2[j]
                    elements_that_were_mapped.add(string1[j])
                else:
                    return False, elements_that_were_mapped
    
    


    return True, elements_that_were_mapped




def remove_the_mapping(string, elements_that_were_mapped):
    for j in range(len(string)):
        if string[j] in mapping and string[j] in elements_that_were_mapped:
            del mapping[string[j]]



encryption_decipher(0)


def encryption_solver(string):
    if string == 'i':
        return 'i'
    return answer[0][string]


for iter in range(len(encryptions)):
    for temporary in range(len(encryptions[iter])):
        print(encryption_solver(encryptions[iter][temporary]), end='')

    print(" ", end='')