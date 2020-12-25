n = int(input())
lineup = [1] * n
if n > 1:
    seps = input().split(" ")
    i = 0
    for sep in seps:
        sep = int(seps[i])
        lineup[sep + 1] = i + 2
        i += 1

for person in lineup:
    print(person, end = ' ')