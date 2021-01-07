max_score = 0
max_person = 0

for i in range(1, 6):
    lst = input().split(" ")
    sum = 0
    for j in range(4):
        sum += int(lst[j])
    if sum > max_score:
        max_score = sum
        max_person = i

result = str(max_person) + " " + str(max_score)
print(result)