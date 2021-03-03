import sys

frac_value_tuple = {}

# Correct this function so that the correct output is given
def get_distinct_fractions(arr):
    for i in arr:

        if i[1] != 0:
            value = i[0]/i[1]
            if value > 0:                                              # given p will never be zero       
                if value in frac_value_tuple.keys():
                    if frac_value_tuple[value][0] > 0 and i[0] > 0:     # cases like -1 -1 will be dealt further down the road
                        if frac_value_tuple[value][0] > i[0]:       # if something like 4/2 is present we want to replace it with 2/1
                            frac_value_tuple[value] = i             # place the new tuple there
                    if frac_value_tuple[value][0] < 0:                  # so if the already present value is of the form -2 -2
                        if i[0] > 0:                                    # we have something like 2 2 just replace without thinking
                            frac_value_tuple[value] = i                 
                        else:                                           
                            if i[0] > frac_value_tuple[value][0]:       # -1 -1 will be preferred over -2 -2
                                frac_value_tuple[value] = i
                else:
                    frac_value_tuple[value] = i    
            else:
                if value in frac_value_tuple.keys():
                    if frac_value_tuple[value][0] > 0:          # if 'bad' negative fraction is present
                        if i[0] < 0:
                            frac_value_tuple[value] = i
                                                                                    # and we have a good negative fraction
                        else:
                            if i[0] < frac_value_tuple[value][0]:                   # it's a bad negative fraction as well but it is in a better form (1/-2 is preferred over 2/-4) 
                                frac_value_tuple[value] = i
                    else:                                                           # a good negative fraction is already present
                        if i[0] < 0:                                                # we have a contender
                            if i[0] > frac_value_tuple[value][0]:
                                frac_value_tuple[value] = i
                else:
                    frac_value_tuple[value] = i
        else:                                                   # we have zero in the denominator
            if i[0] > 0:
                Infinity = 999999999999999
                if Infinity in frac_value_tuple.keys():          # infinity is present in the dict already
                    if i[0] < frac_value_tuple[Infinity][0]:
                        frac_value_tuple[Infinity] = i
                else:
                    frac_value_tuple[Infinity] = i
            else:
                negative_Infinity = -999999999999999                       # now we have negative infinity at hand
                if negative_Infinity in frac_value_tuple.keys():
                    if i[0] > frac_value_tuple[negative_Infinity][0]:
                        frac_value_tuple[negative_Infinity] = i
                else:
                    frac_value_tuple[negative_Infinity] = i
    
    # now we need to sort the array based on the info present in the dict
    tuples = list(frac_value_tuple.keys())
    tuples.sort()
    arr = []
    for i in range(len(tuples)):
        arr.append(frac_value_tuple[tuples[i]])
    
    return arr
 
# ----------------------Do not change anything below this line --------------------------

n = int(input())
arr_strip = list(map(int, input().split()))
arr = []
for i in range(0, 2*n, 2):
    arr.append((arr_strip[i], arr_strip[i+1]))
 
result = get_distinct_fractions(arr)
print(len(result))
for x in result:
    print(x[0], x[1], end = ' ')