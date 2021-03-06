for _ in range(int(input())):
    x_initial, y_initial, x_final, y_final = map(int, input().split())
    ans = ''
    North = y_final - y_initial
    #print(North)
    if North >= 0:
        ans += 'N'*North
    else:
        ans += 'S'*(-1*North)
    East = x_final - x_initial
    if East>=0:
        ans += 'E'*East
    else:
        ans += 'W'*(-1*East)
    print(len(ans))
    print(ans)