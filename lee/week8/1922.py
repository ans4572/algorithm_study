N = int(input())
M = int(input())
par = [i for i in range(N + 1)]

def find(a):
    if a == par[a]:
        return a
    else:
        a = find(par[a])
        return a


def union_find(a, b):
    apar = find(a)
    bpar = find(b)
    if apar == bpar:
        return False
    if apar > bpar:
        par[apar] = bpar
        find(a)
    else:
        par[bpar] = apar
        find(b)
    return True


edge = [{} for i in range(N + 1)]
for i in range(M):
    A, B, C = map(int, input().split())
    if A == B:
        continue
    if not edge[A].get(B) or edge[A][B] > C:
        edge[A][B] = C
        edge[B][A] = C

edge2 = []
for i in range(1, N + 1):
    for k, v in edge[i].items():
        edge2.append([v, i, k])
edge2.sort()

cnt = 0
ans = 0
for i in edge2:
    if cnt == N - 1:
        break
    if union_find(i[1], i[2]):
        ans += i[0]
        cnt += 1
print(ans)
