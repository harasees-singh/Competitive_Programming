words = set()
alphabets = ["a","b","c","d","e","f","g","h"]

#yield all derangements of the values (D8 = 14833 worst case)
#then replace in the string all at once!

from itertools import permutations
def derangement(x):
    p = permutations(x)
    return (i for i in p if not any(i[k] == x[k] for k in range(len(x))))
for w in range(int(input())) :   
    words.add(input())    
string = input()
for d in derangement(alphabets) :
    temp = string
    mapped = dict(zip(alphabets,d))
    table = temp.maketrans(mapped)
    temp = temp.translate(table)
    decrypted = temp.split()
    if len(set(decrypted) - words) == 0:
        for word in decrypted:
            print( word , end=" ")
        break