map = []
for i in range(9):
    map.append([])
    map[i][:0] = input()

for i in range(9):
    for j in range(9):
        map[i][j] = int(map[i][j])

cand = [] # [(좌표, 후보[])]



print(map)
