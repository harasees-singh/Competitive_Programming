def flip(bit):
    if bit=='1':
        return '0'
    return '1'

for _ in range(int(input())):
    s = input()
    if len(s)>=2:
        second_bit = s[1]
        
        dp = [0 for _ in range(2000000)]
        dp[0] = '0'
        if second_bit == '1':
            dp[1] = '0'
        else:
            dp[1] = '11'
        length = len(s)
        current_bit  = second_bit
        for i in range(2, length):
            if s[i] == current_bit:
                dp[i] = dp[i-1]
            else:
                dp[i] = dp[i-2] + flip(s[i])
            current_bit = s[i]
        print(dp[length-1])
    else:
        if s=='1':
            print(0)
        else:
            print(1)

    