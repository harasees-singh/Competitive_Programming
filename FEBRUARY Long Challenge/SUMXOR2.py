'''

You are given a sequence of positive integers A1,A2,…,AN. You should answer Q queries. In each query:

You are given a positive integer M.
Consider all non-empty subsequences of A with length ≤M. Recall that a subsequence is any sequence that can be created by deleting 
zero or more elements without changing the order of the remaining elements.
For each of these subsequences, compute the bitwise XOR of its elements. Your task is to determine the sum of these values. 
Since this sum can be very large, compute it modulo 998,244,353.


combinations('ABCD', 2)

AB AC AD BC BD CD

Note: i am not sure what will happen if for some i and j Ai = Aj.
will deal with it later

'''
# here is the base idea for every subsequence when i have to compute it's bitwise xor i will refer to a dictionary 
# which will already have bitwise xors of the same subsequence but will the last element missing 
# then i will take that xor value of the subsequence from the dictionary and then do it's bitwise xor with 
# the last element of the subsequence and then add it to the final sum and also add its xor value as a key value pair in the dictionary
import array
import itertools

# arr = [1, 2, 5, 4, 4]
# for i in itertools.combinations(arr, 2):
#    print(i)

def SubsequenceMaker(number_of_elements):
    return tuple(itertools.combinations(elements, number_of_elements))

computed_xors = {}      # will store all the xors here such that the key is a tuple of numbers (a subsequence in regard to the question) and it's value will be the bitwise xor of all the elements in the tuple

n = int(input())
elements = tuple(map(int, input().split()))

q = int(input())

sum = 0

for g in range(len(elements)):
    sum += elements[g]

for p in range(len(elements)):                                                # initializing computed_xors with key values such that each key is a unit length tuple containing an element from elements
    computed_xors[elements[p]] = elements[p]                                  # and the corres value is the number itself

for i in range(q):
    query = int(input())

    for j in range(2, query+1):
        sequence = SubsequenceMaker(j)
        # print(sequence)
        for v in range(len(sequence)):
            if j==2:
                temp = computed_xors[sequence[v][0]]^sequence[v][1]
                sum += temp
                # print(sequence[v])
                computed_xors[sequence[v]] = temp

                # print(computed_xors)
            else:
                temp = computed_xors[sequence[v][:-1]]^sequence[v][-1]
                sum += temp
                computed_xors[sequence[v]] = temp

    print(sum)





