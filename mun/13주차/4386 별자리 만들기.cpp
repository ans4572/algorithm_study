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
ũ�罺Į �˰��� Ȱ��
1. ���Ͽ�-���ε� ����
2. ��ǥ���� ���Ϳ� ��Ƽ� ���� ����
3. ũ�罺Į �˰��� ����
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

	// �Ҽ��� 2�ڸ����� ����� ���� �߰�
	cout << fixed;
	cout.precision(2);

	int n;
	cin >> n;

	vector<pair<double, double>> vec;
	vector<tuple<double, int, int>> dis;  // �Ÿ� ���� Ʃ��
	double x, y;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		vec.push_back({ x,y });

		parent[i] = i;
	}

	// �Ÿ��� ��� ����
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			x = abs(vec[i].first - vec[j].first);
			y = abs(vec[i].second - vec[j].second);
			dis.push_back({ sqrt(x * x + y * y),i,j });
		}
	}

	sort(dis.begin(), dis.end());

	double ans = 0;
	// ũ�罺Į �˰���
	for (int i = 0; i < dis.size(); ++i) {
		int a = get<1>(dis[i]);
		int b = get<2>(dis[i]);
		double d = get<0>(dis[i]);

		// ����Ŭ�� �߻����� �ʴ� ��� ����
		if (Find(a) != Find(b)) {
			Union(a, b);
			ans += d;
		}
	}

	cout << ans << endl;

	return 0;
}
