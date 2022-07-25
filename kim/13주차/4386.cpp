#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;
int parent[110];
vector<pair<double, double>> pos;
vector < pair<double, pair<int, int>>> edge;	//i번,j번의 거리

int find_parent(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = find_parent(parent[a]);
}

bool isCycle(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);

	if (a == b) return true;
	else return false;
}

void Union(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	parent[b] = a;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {	// 데이터입력
		double x, y; cin >> x >> y;
		pos.push_back({ x,y });
	}

	for (int i = 0; i < pos.size(); i++) {	// 각 별로 거리 저장
		double x = pos[i].first;
		double y = pos[i].second;

		for (int j = i + 1; j < n; j++) {
			double nx = pos[j].first;
			double ny = pos[j].second;
			double dist = sqrt((x - nx)*(x - nx) + (y - ny)*(y - ny));
			edge.push_back({ dist, { i,j } });
		}

		parent[i] = i;	//부모
	}

	//가중치 기준으로 오름차순
	sort(edge.begin(), edge.end());

	double res = 0;
	//크루스칼 알고리즘
	for (int i = 0; i < edge.size(); i++) {
		double dist = edge[i].first;
		int idx1 = edge[i].second.first;
		int idx2 = edge[i].second.second;

		if (!isCycle(idx1, idx2)) {
			Union(idx1, idx2);
			res += dist;
		}
	}

	cout << fixed;
	cout.precision(2);	//소수점 2자리
	cout << res << "\n";

	return 0;
}
