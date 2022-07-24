// https://www.acmicpc.net/problem/4386

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <tuple>

using namespace std;

/*
크루스칼 알고리즘 활용
1. 유니온-파인드 구현
2. 좌표들을 벡터에 담아서 정렬 진행
3. 크루스칼 알고리즘 진행
*/

int parent[101];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 소수점 2자리까지 출력을 위해 추가
	cout << fixed;
	cout.precision(2);

	int n;
	cin >> n;

	vector<pair<double, double>> vec;
	vector<tuple<double, int, int>> dis;  // 거리 저장 튜플
	double x, y;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		vec.push_back({ x,y });

		parent[i] = i;
	}

	// 거리를 모두 저장
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			x = abs(vec[i].first - vec[j].first);
			y = abs(vec[i].second - vec[j].second);
			dis.push_back({ sqrt(x * x + y * y),i,j });
		}
	}

	sort(dis.begin(), dis.end());

	double ans = 0;
	// 크루스칼 알고리즘
	for (int i = 0; i < dis.size(); ++i) {
		int a = get<1>(dis[i]);
		int b = get<2>(dis[i]);
		double d = get<0>(dis[i]);

		// 사이클이 발생하지 않는 경우 진행
		if (Find(a) != Find(b)) {
			Union(a, b);
			ans += d;
		}
	}

	cout << ans << endl;

	return 0;
}
