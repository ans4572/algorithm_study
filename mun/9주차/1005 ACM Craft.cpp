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
bool edge[1001][1001];  // edge[x][y]: x -> y ���� ����
int minTime[1001];      // �� �ǹ����� �ɸ��� �ּ� �ð�

void DFS(int node) {

	// ��� Ȯ��
	for (int i = 1; i <= N; ++i) {
		if (edge[node][i]) {
			// �湮 ���Ѱ��̰ų� �ð��� �� �ɸ��� ���
			if (minTime[i] == -1 || minTime[i] < minTime[node] + arr[i]) {
				minTime[i] = minTime[node] + arr[i];
				DFS(i);
			}
		}
	}
}

// �������� �Լ�
void topologicalSort() {
	memset(minTime, -1, sizeof(minTime));

	for (int i = 1; i <= N; ++i) {
		// �湮 ���Ѱ� ����
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
