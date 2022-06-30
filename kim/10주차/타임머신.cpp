#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

#define INF 987654321

int n,m;
long long dist[501];							//거리 테이블
vector<pair<int, int>> edge[501];				// edge[A] = {B,C}

bool bellman(int start) {				//벨만포드 : 음수 포함된 가중치는 다익스트라 사용할 수 없다.

	dist[start] = 0;

  //매 단계마다 모든 간선 확인하면서 모든 노드간의 최단거리 구함.
  
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (auto val : edge[j]) {
				int next = val.first;
				int cost = val.second;

				if (dist[j] != INF && dist[next] > dist[j] + cost) {
					dist[next] = dist[j] + cost;

					if (i == n) return false;	//n단계에서도 최단거리가 업데이트되면 음수 간선 순환이다.
				}

			}
		}
	}


	return true;
}

int main() {
	ios::sync_with_stdio(false); 	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) dist[i] = INF;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
	}

	if (!bellman(1)) cout << -1 << "\n";  // 음수 간선 순환인 경우
	else {
		for (int i = 2; i <= n; i++) cout << (dist[i] == INF ? -1 : dist[i] ) << "\n"; 
	}

	return 0;
}
