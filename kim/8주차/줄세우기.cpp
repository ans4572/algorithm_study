#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
vector<int> vec[32001];
int degree[32001];

void start() {
	queue<int> q;
	
	for (int i = 1; i <= n; i++) {
		if (!degree[i]) q.push(i);	//나보다 큰 사람이 없거나, 정보가 없는 경우 먼저 출력되게
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";

		for (auto val : vec[cur]) {
			degree[val]--;
			if (!degree[val]) {	// 나보다 작은 사람 중, 두번째로 큰 사람
				q.push(val);
			}
		}
	}
}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		degree[b]++;
		vec[a].push_back(b);
	}

	start();


	return 0;
}
