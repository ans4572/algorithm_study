#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


int v, e;
int dist[402][402];	//dist[i][j] : i에서 j로 가는데 거리비용. 없으면 무한

#define INF 987654321

int main() {
	ios::sync_with_stdio(false); 	cin.tie(0); cout.tie(0);

	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		dist[a][b] = c;
	}

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (dist[i][j] == 0) dist[i][j] = INF;	 // 거리 무한 초기화.
		}
	}

	int res = INF;
  
  // 플로이드 와샬

	for (int k = 1; k <= v; k++) {	//거쳐가는 노드
		for (int i = 1; i <= v; i++) {	// 출발 노드
			for (int j = 1; j <= v; j++) {	//도착 노드
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					if (i == j) res = min(res, dist[i][j]); 	// i와 j가 같다는 것은 왕복하고 왔다는 뜻. (사이클 형성)
				}
			}
		}
	}
	res = (res == INF) ? -1 : res;
	cout << res;

	return 0;
}
