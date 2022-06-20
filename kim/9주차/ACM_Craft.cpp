#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int t, n, k, w;	// t : 테스트케이스 , n : 건물개수 , k : 건설순서 규칙 갯수
int D[1010];	// 건물 타임
int resultCost[1010];
vector<int> building[1010];
int degree[1010];

void start() {
	queue<int> q; 

	for (int i = 1; i <= n; i++) {
		if (degree[i]==0) {
			q.push(i);
			resultCost[i] = D[i];
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < building[cur].size(); i++) {
			int n = building[cur][i];
			degree[n]--;
			resultCost[n] = max(resultCost[n], resultCost[cur] + D[n]);
			if (degree[n]==0) q.push(n);
		}
	}

	cout << resultCost[w] << endl;
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		
		for (int j = 0; j <= 1010; j++) {
			D[j] = 0;
			degree[j] = 0;
			resultCost[j] = 0;
			building[j].clear();
		}

		cin >> n >> k;

		for (int j = 1; j <= n; j++) cin >> D[j];	//건물 별 건설시간
		for (int j = 0; j < k; j++) {
			int a, b; cin >> a >> b;
			degree[b]++;
			building[a].push_back(b);
		}
		
		cin >> w;

		start();


	}
}
