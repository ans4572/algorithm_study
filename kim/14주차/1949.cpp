#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int dp[10001][2];		// dp[cur][0] : cur 마을의 0번 상태(no 우수)일때 주민 최대값, dp[cur][1] : cur마을 우수상태일때 주민 최대값
int civilCount[10001];
bool visited[10001];
vector<int> tree[10001];

void dfs(int cur) {
	visited[cur] = true;

	dp[cur][0] = 0;		// 우수마을이 아니면 굳이 주민수를 더할필요 없다.
	dp[cur][1] = civilCount[cur];	//우수마을이면 현재 주민수 더해줌.

	for (int i = 0; i < tree[cur].size(); i++) {
		int next = tree[cur][i];
		if (visited[next]) continue;
		dfs(next);	//다음 마을로 이동.
		
		dp[cur][0] += max(dp[next][0], dp[next][1]);	//현재마을이 노우수라면 다음 마을은 우수,노우수 모두 가능하므로 최대값을 가져옴
		dp[cur][1] += dp[next][0];	//현재마을이 우수라면 다음 마을은 반드시 일반이어야함. 
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> civilCount[i];
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1);
	cout << max(dp[1][0], dp[1][1]);

	return 0;
}
