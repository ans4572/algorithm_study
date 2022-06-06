// https://www.acmicpc.net/problem/1167

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

// 1. 트리에서 임의의 정점 x를 잡는다.
// 2. 정점 x에서 가장 먼 정점 y를 찾는다.
// 3. 정점 y에서 가장 먼 정점 z를 찾는다.
// 트리의 지름은 정점 y와 정점 z를 연결하는 경로다.

vector<pair<int, int> > edge[100001];       // first: 정점, second: 거리
bool visit[100001];
int max_node = -1, max_sum = 0;

// a 정점에서 시작해서 다른 노드들까지 DFS로 탐색
void DFS(int a, int sum) {
	visit[a] = true;

	for (auto p : edge[a]) {
		if (!visit[p.first]) {
			if (max_sum < sum + p.second) {
				max_sum = sum + p.second;
				max_node = p.first;
			}

			DFS(p.first, sum + p.second);
		}
	}

	return;
}

int main() {
	int V;
	cin >> V;
	
	for (int i = 1; i <= V; ++i) {
		int v, a, w;
		cin >> v;
		cin >> a;

		while (a != -1) {
			cin >> w;
			edge[v].push_back({ a, w });
			cin >> a;
		}
	}

	// 첫번째 DFS
	DFS(1, 0);

	// 두번째 DFS를 위해 초기화 작업 진행
	max_sum = 0;
	memset(visit, false, sizeof(visit));

	// 두번째 DFS
	DFS(max_node, 0);
	
	cout << max_sum << endl;

	return 0;
}