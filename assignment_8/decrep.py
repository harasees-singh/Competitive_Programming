import copy

encryptions = list()
actual_words = list()
mapping = dict()

n = int(input())
for i in range(n):
	actual_words.append(input())


encryptions = list(map(str, input().split()))



def encryption_decipher(i):
	

    if i == len(encryptions)-1:
        global copy_
        copy_ = copy.deepcopy(mapping)
        return     
	
    else:
        for j in range(len(actual_words)):
            mapping_was_successful = False
            elements_that_were_mapped = set()
            
            if len(encryptions[i])==len(actual_words[j]):
                print(encryptions[i])
                print(actual_words[j])
                mapping_was_successful, elements_that_were_mapped = do_the_mapping(encryptions[i], actual_words[j]) # do_the_mapping() will return True if the mapping was successful else false
                print(mapping)

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
        if string1[j] in mapping:
            if mapping[string1[j]] != string2[j]:
                return False
        else:
            mapping[string1[j]] = string2[j]
            elements_that_were_mapped.add(string1[j])
    
    if len(elements_that_were_mapped) == 0:
        elements_that_were_mapped.add(1)


    return True, elements_that_were_mapped




def remove_the_mapping(string, elements_that_were_mapped):
    for j in range(len(string)):
        if string[j] in mapping and string[j] in elements_that_were_mapped:
            del mapping[string[j]]



encryption_decipher(0)
print(copy_)
