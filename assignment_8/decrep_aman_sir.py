W = int(input())
words = set([input() for _ in range(W)])
enc_words = input().split()

key = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
val = set(['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'])

map = {}# key->val

def mapping(i):
    if i == len(key):
        dec_words = []
        for enc_word in enc_words:
            dec_word = ""
            for ch in enc_word:
                dec_word += map[ch]
            if not dec_word in words:
                return 0
            dec_words.append(dec_word)
        print(*dec_words)
        return 1
   
    tmp = val.copy()
    for v in tmp:
        if v == key[i]:
            continue
        map[key[i]] = v
        val.remove(v)
        if mapping(i+1):
            return 1
        val.add(v)
    return 0

mapping(0)