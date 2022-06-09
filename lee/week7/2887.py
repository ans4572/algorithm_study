x = []
y = []
z = []
n = int(input())
par = [i for i in range(n + 1)]


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


for i in range(n):
    X, Y, Z = map(int, input().split())
    x.append((X, i + 1))
    y.append((Y, i + 1))
    z.append((Z, i + 1))


x.sort()
y.sort()
z.sort()
edge = []


for i in range(n - 1):
    edge.append((abs(x[i][0] - x[i + 1][0]), x[i][1], x[i + 1][1]))
    edge.append((abs(y[i][0] - y[i + 1][0]), y[i][1], y[i + 1][1]))
    edge.append((abs(z[i][0] - z[i + 1][0]), z[i][1], z[i + 1][1]))


edge.sort()
ans = 0
cnt = 0

for i in edge:
    if cnt == n - 1:
        break
    if union_find(i[1], i[2]):
        ans += i[0]
        cnt += 1

print(ans)
