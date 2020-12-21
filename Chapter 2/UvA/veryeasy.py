while True:
    try:
        N, A = map(int, input().split())
    except:
        break
    sum = 0
    for i in range(1, N + 1):
        sum += (i * A**i)
    print(sum)