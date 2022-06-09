N, M = map(int, input().split())
cost = [[0] * (N + 1) for i in range(M + 1)]
benefit = [[0] * (N + 1) for i in range(M + 1)]
path = [[0] * (N + 1) for i in range(M + 1)]

for i in range(N):
    lst = list(map(int, input().split()))
    for j in range(M):
        cost[j + 1][i + 1] = lst[j + 1]

for i in range(1, M + 1):
    for j in range(1, N + 1):
        for k in range(j + 1):
            if benefit[i][j] < benefit[i - 1][j - k] + cost[i][k]:
                benefit[i][j] = benefit[i - 1][j - k] + cost[i][k]
                path[i][j] = k

ans = [0] * M
ans2 = N
i = 0

while ans2 > 0:
    ans[M - 1 - i] = path[M - i][ans2]
    ans2 -= path[M - i][ans2]
    i += 1

print(benefit[M][N])
for i in ans:
    print(i, end=' ')
