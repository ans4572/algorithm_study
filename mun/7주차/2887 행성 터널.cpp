// https://www.acmicpc.net/problem/2887

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <tuple>

/*
ũ�罺Į �˰��� Ȱ��
1. ���Ͽ�-���ε� ����
2. x,y,z ��ǥ���� ���� ���Ϳ� ��Ƽ� ���� ����
3. �� ��ǥ���� �ּڰ��� �������� ũ�罺Į �˰��� ����
*/

using namespace std;

int parent[100001];

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

class Edge {
public:
	int a, b;
	int distance;
	Edge(int a, int b, int d) {
		this->a = a;
		this->b = b;
		this->distance = d;
	}
	bool operator < (Edge& edge) {
		return this->distance < edge.distance;
	}
};


int main() {
	int N;
	cin >> N;

	// �� x, y, z �� ����
	vector<pair<int, int>> X;
	vector<pair<int, int>> Y;
	vector<pair<int, int>> Z;

	int x, y, z;
	for (int i = 0; i < N; ++i) {
		cin >> x >> y >> z;
		X.push_back({ x, i });
		Y.push_back({ y, i });
		Z.push_back({ z, i });
	}

	// ���� ����
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	vector<tuple<int, int, int>> vec;  // ���� ������ ���� �迭
	
	for (int i = 0; i < N - 1; ++i) {
		vec.push_back(make_tuple(X[i + 1].first - X[i].first, X[i].second, X[i + 1].second));
		vec.push_back(make_tuple(Y[i + 1].first - Y[i].first, Y[i].second, Y[i + 1].second));
		vec.push_back(make_tuple(Z[i + 1].first - Z[i].first, Z[i].second, Z[i + 1].second));
	}

	sort(vec.begin(), vec.end());

	int ans = 0;
	for (int i = 0; i < N; ++i)
		parent[i] = i;

	// ũ�罺Į �˰���
	for (int i = 0; i < vec.size(); ++i) {
		int a = get<1>(vec[i]);
		int b = get<2>(vec[i]);
		int edge = get<0>(vec[i]);

		// ����Ŭ�� �߻����� �ʴ� ��� ����
		if (Find(a) != Find(b)) {
			Union(a, b);
			ans += edge;
		}
	}

	cout << ans << endl;

	return 0;
}