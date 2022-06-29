// https://www.acmicpc.net/problem/1956

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

// 모든 노드 간 최단 경로가 필요하므로 플로이드-워셜 알고리즘 사용
// O(n^3)이므로 노드 개수가 작을 때만 사용 가능

using namespace std;

const int INF = 10000000;

int adj[401][401] = { 0 };   // 입력값인 인접 행렬 저장 배열
int dist[401][401] = { 0 };  // 최단 거리 저장 배열

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

	// 최단 거리 배열 초기화 진행
	for (int i = 1; i <= V; ++i) {
		for (int j = 1; j <= V; ++j) {
			if (i == j) dist[i][j] = 0;
			else if (adj[i][j]) dist[i][j] = adj[i][j];
			else dist[i][j] = INF;
		}
	}

	// 플로이드-워셜 알고리즘
	for (int k = 1; k <= V; ++k) {
		for (int i = 1; i <= V; ++i) {
			for (int j = 1; j <= V; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	// 두 마을간 사이클 존재 여부 확인 후 값 갱신하며 진행
	int ans = INF;
	for (int i = 1; i <= V; ++i) {
		for (int j = 1; j <= V; ++j) {
			if (i == j) continue;

			// 서로 가는 길이 있다면 사이클이 존재
			if (dist[i][j] != INF && dist[j][i] != INF)
				ans = min(ans, dist[i][j] + dist[j][i]);
		}
	}

	if (ans == INF) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}
