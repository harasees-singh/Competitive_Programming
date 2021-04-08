def NotASubstring(a, s):
    i, j = 0, 0
    while i<len(a) and j<len(s):
        # if j hits len(s) first then a is not a substring
        if a[i] == s[j]:
            i+=1
            j+=1
        else:
            j+=1
    if j == len(s):
        return True
    return False
    
    
from queue import Queue
for _ in range(int(input())):
    s = input()
    flag = True
    for i in range(len(s)):
        if s[i] == "0":
            flag = False
    if flag:
        print(0)
        break
    string_len = len(s)
    n = 2**string_len
    BinaryQueue = Queue()
    BinaryQueue.put("1")
    n = n//2 +1
    while(n):
        n-=1
        string = BinaryQueue.get()
        if NotASubstring(string, s):
            print(string)
            break
        BinaryQueue.put(string+"0")
        BinaryQueue.put(string+"1")
        
        # first n binary numbers have been generated