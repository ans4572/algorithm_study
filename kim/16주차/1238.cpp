#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 987654321

int n, m, x;
vector<pair<int, int>> path[1001];	// path[from] = {to , cost}
int dist[1001];

void dij(int start) {
	priority_queue<pair<int, int>> pq;

	dist[start] = 0;
	pq.push({ start,0 });	//방문노드, 가치

	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();

		if (cost > dist[cur]) continue;
        
		for (auto p : path[cur]) {
			int next = p.first;
			int nCost = cost + p.second;

			if (nCost < dist[next]) {
				pq.push({ next,-nCost });
				dist[next] = nCost;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int s, e, t; cin >> s >> e >> t;
		path[s].push_back({ e,t });
	}

	vector<int> time(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		fill(dist, dist + n + 1, MAX);
		dij(i);
		time[i] += dist[x];
	}

	fill(dist, dist + n + 1, MAX);
	dij(x);

	for (int i = 1; i <= n; i++) time[i] += dist[i];
	

	int res = 0;
	for (auto val : time) {
		if (val > res)res = val;
	}

	cout << res;

	return 0;
}
