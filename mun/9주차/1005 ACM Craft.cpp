// https://www.acmicpc.net/problem/1005

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

int N, K, W;
int arr[1001];
bool edge[1001][1001];  // edge[x][y]: x -> y 존재 여부
int minTime[1001];      // 각 건물마다 걸리는 최소 시간

void DFS(int node) {

	// 경로 확인
	for (int i = 1; i <= N; ++i) {
		if (edge[node][i]) {
			// 방문 안한곳이거나 시간이 더 걸리는 경우
			if (minTime[i] == -1 || minTime[i] < minTime[node] + arr[i]) {
				minTime[i] = minTime[node] + arr[i];
				DFS(i);
			}
		}
	}
}

// 위상정렬 함수
void topologicalSort() {
	memset(minTime, -1, sizeof(minTime));

	for (int i = 1; i <= N; ++i) {
		// 방문 안한곳 진행
		if (minTime[i] == -1) {
			minTime[i] = arr[i];
			DFS(i);
		}
	}

	cout << minTime[W] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int test = 0; test < T; ++test) {
		cin >> N >> K;

		memset(edge, false, sizeof(edge));

		for (int i = 1; i <= N; ++i)
			cin >> arr[i];

		int X, Y;
		for (int i = 0; i < K; ++i) {
			cin >> X >> Y;
			edge[X][Y] = 1;
		}

		cin >> W;

		topologicalSort();
	}

	return 0;
}
