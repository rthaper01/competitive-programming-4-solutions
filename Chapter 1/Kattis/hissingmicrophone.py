line = input()
exists_hiss = False
for i in range(len(line) - 1):
    if line[i] == 's' and line[i + 1] == 's':
        exists_hiss = True
        print("hiss")
        break
if (not exists_hiss):
    print("no hiss")