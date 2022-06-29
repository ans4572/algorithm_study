// https://www.acmicpc.net/problem/1956

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

// ��� ��� �� �ִ� ��ΰ� �ʿ��ϹǷ� �÷��̵�-���� �˰��� ���
// O(n^3)�̹Ƿ� ��� ������ ���� ���� ��� ����

using namespace std;

const int INF = 10000000;

int adj[401][401] = { 0 };   // �Է°��� ���� ��� ���� �迭
int dist[401][401] = { 0 };  // �ִ� �Ÿ� ���� �迭

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int V, E;
	int a, b, c;
	cin >> V >> E;
	
	for (int i = 0; i < E; ++i) {
		cin >> a >> b >> c;
		adj[a][b] = c;
	}

	// �ִ� �Ÿ� �迭 �ʱ�ȭ ����
	for (int i = 1; i <= V; ++i) {
		for (int j = 1; j <= V; ++j) {
			if (i == j) dist[i][j] = 0;
			else if (adj[i][j]) dist[i][j] = adj[i][j];
			else dist[i][j] = INF;
		}
	}

	// �÷��̵�-���� �˰���
	for (int k = 1; k <= V; ++k) {
		for (int i = 1; i <= V; ++i) {
			for (int j = 1; j <= V; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	// �� ������ ����Ŭ ���� ���� Ȯ�� �� �� �����ϸ� ����
	int ans = INF;
	for (int i = 1; i <= V; ++i) {
		for (int j = 1; j <= V; ++j) {
			if (i == j) continue;

			// ���� ���� ���� �ִٸ� ����Ŭ�� ����
			if (dist[i][j] != INF && dist[j][i] != INF)
				ans = min(ans, dist[i][j] + dist[j][i]);
		}
	}

	if (ans == INF) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}
