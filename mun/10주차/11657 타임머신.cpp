// https://www.acmicpc.net/problem/11657

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

// ��帶�� �ּ� ��� ����: ��� ������ ����� ����� ���� ���ͽ�Ʈ��, ���� ������ ���ԵǾ� ������ ����-���带 ����ϸ� �ȴ�.
// int�� ���ж��� long long���� �����ϰ� ���

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

	vector<long long> minTable(N + 1, INF);  // �ּ� �Ÿ� ���� ���̺�
	vector<edge> edges;

	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		edges.push_back(edge(a, b, c));
	}

	// ��� ������ ���µ� ��� �ּҺ���� �˱� ���ؼ��� N-1�� Ž���� ����.
	minTable[1] = 0;
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < edges.size(); ++j) {
			if (minTable[edges[j].a] == INF) continue;
			if (minTable[edges[j].b] > minTable[edges[j].a] + edges[j].c)
				minTable[edges[j].b] = minTable[edges[j].a] + edges[j].c;
		}
	}

	// ���� ����Ŭ �Ǻ�
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
