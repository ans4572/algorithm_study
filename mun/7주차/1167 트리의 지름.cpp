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

// 1. Ʈ������ ������ ���� x�� ��´�.
// 2. ���� x���� ���� �� ���� y�� ã�´�.
// 3. ���� y���� ���� �� ���� z�� ã�´�.
// Ʈ���� ������ ���� y�� ���� z�� �����ϴ� ��δ�.

vector<pair<int, int> > edge[100001];       // first: ����, second: �Ÿ�
bool visit[100001];
int max_node = -1, max_sum = 0;

// a �������� �����ؼ� �ٸ� ������� DFS�� Ž��
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

	// ù��° DFS
	DFS(1, 0);

	// �ι�° DFS�� ���� �ʱ�ȭ �۾� ����
	max_sum = 0;
	memset(visit, false, sizeof(visit));

	// �ι�° DFS
	DFS(max_node, 0);
	
	cout << max_sum << endl;

	return 0;
}