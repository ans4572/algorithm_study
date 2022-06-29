// https://www.acmicpc.net/problem/11657

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

// 노드마다 최소 비용 문제: 모든 간선의 비용이 양수일 때는 다익스트라를, 음수 간선이 포함되어 있으면 벨만-포드를 사용하면 된다.
// int로 실패떠서 long long으로 변경하고 통과

using namespace std;

const int INF = 10000000;

class edge {
public:
	int a = 0, b = 0, c = 0;

	edge() {}
	edge(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	int a, b, c;
	cin >> N >> M;

	vector<long long> minTable(N + 1, INF);  // 최소 거리 저장 테이블
	vector<edge> edges;

	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		edges.push_back(edge(a, b, c));
	}

	// 모든 정점을 가는데 드는 최소비용을 알기 위해서는 N-1번 탐색을 진행.
	minTable[1] = 0;
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < edges.size(); ++j) {
			if (minTable[edges[j].a] == INF) continue;
			if (minTable[edges[j].b] > minTable[edges[j].a] + edges[j].c)
				minTable[edges[j].b] = minTable[edges[j].a] + edges[j].c;
		}
	}

	// 음의 사이클 판별
	for (int j = 0; j < edges.size(); ++j) {
		if (minTable[edges[j].a] == INF) continue;
		if (minTable[edges[j].b] > minTable[edges[j].a] + edges[j].c) {
			cout << -1 << endl;
			return 0;
		}
	}

	for (int i = 2; i <= N; ++i) {
		if (minTable[i] != INF)
			cout << minTable[i] << "\n";
		else
			cout << -1 << "\n";
	}

	return 0;
}
