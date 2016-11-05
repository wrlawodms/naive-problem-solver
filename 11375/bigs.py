from queue import Queue

fgraph = dict()

N, M = map(int, input().split())
fgraph[0] = dict()
fgraph[N+M+1] = dict()
for n in range(1, N+1):
    fgraph[0][n] = 0
    fgraph[n] = dict()
    fgraph[n][0] = 0
for m in range(1, M+1):
    fgraph[N+M+1][N+m] = 0
    fgraph[N+m] = dict()
    fgraph[N+m][N+M+1] = 0

for i in range(1, N+1):
    tos = map(int, input().split()[1:])
    for to in tos:
        fgraph[i][N+to] = 0
        fgraph[N+to][i] = 0


def find_bfs_path(src, dest, dist):
    q = Queue()
    q.put((src,[src]))  # (src, path)
    q.put(-1)
    cdist = 0
    while not q.empty():
        next = q.get()
        if next == -1:
            cdist += 1
            if cdist >= dist:
                return None # not found
            q.put(-1)
            continue
        c, path = next
        children = [i for i in fgraph[c].keys() if fgraph[c][i] < 1 and i not in path]
        # print(cdist, path)
        for child in children:
            if child == dest:
                # print("founded : ", cdist+1, path+[child])
                return path+[child]
            else:
                q.put((child, path+[child]))
        # print("queue is empty")

for i in range(3, N+M+2):
    if sum(fgraph[0][i] for i in range(1, N+1)) == N:
        break
    if sum(fgraph[i][N+M+1] for i in range(N+1, N+M+1)) == M:
        break
    while True:
        path = find_bfs_path(0, N + M + 1, i)
        if not path:
            break
        for j in range(len(path)-1):
            fgraph[path[j]][path[j+1]] += 1
            fgraph[path[j+1]][path[j]] -= 1

print(sum(fgraph[0][i] for i in range(1,N+1)))

