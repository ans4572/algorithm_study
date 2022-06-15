import copy
from collections import deque

N, M = map(int, input().split())
olst = [{} for i in range(N + 1)]
inlst = [{} for i in range(N + 1)]

for i in range (M):
    a, b = map(int, input().split())
    olst[a][b] = True
    inlst[b][a] = True

cnt = 0
q = []
q2 = []
ans = [[] for i in range(N + 1)]
ans2 = deque([])

for i in range(1, N+1):
    if len(inlst[i]) == 0:
        q.append(i)
        ans2.append(i)

while len(q):
    for i in q:
        for k in list(olst[i].keys()):
            del inlst[k][i]
            if len(inlst[k]) == 0:
                q2.append(k)
                ans[i].append(k)

    q = copy.deepcopy(q2)
    q2 = []


while len(ans2):
    nxt = ans2[0]
    ans2.popleft()
    print(nxt, end=' ')
    for j in ans[nxt]:
        ans2.append(j)
