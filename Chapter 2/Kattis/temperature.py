coefficients = input().split(" ")
x = int(coefficients[0])
y = int(coefficients[1])

if (y == 1 and x != 0):
    print("IMPOSSIBLE")
elif (y == 1 and x == 0):
    print("ALL GOOD")
else:
    point = x / (1 - y)
    print(point)