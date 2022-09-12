#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug

int b[3], k1, k2;
int dp[501][501][2];
//0 A, 1 B

int dfs(int l, int r, int order) {
	int& ret = dp[l][r][order];
	if (ret != -1) return ret;
	if (l == 0 && r == 0) {
		ret = (int)!order;
		return ret;
	}
	//벡터를 만들어서 가능한 가지 수를 다 넣음, 하나라도 자기 order 나오면
	//자기 order 넣고 리턴하면되고 다 상대거나 벡터가 비었으면 상대 order 넣고 리턴
	map<int, int> mp;
	for (int i = 0; i < 3; i++) {
		if (l - b[i] >= 0) mp[dfs(l - b[i], r, (int)!order)]++;
		if (r - b[i] >= 0) mp[dfs(l, r - b[i], (int)!order)]++;
	}
	if (mp[order]) ret = order;
	else ret = (int)!order;
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> b[0] >> b[1] >> b[2];
	for (int i = 0; i < 5; i++) {
		cin >> k1 >> k2;
		memset(dp, -1, sizeof(dp));
		dfs(k1, k2, 0);
		auto ans = dp[k1][k2][0] == 0 ? 'A' : 'B';
		cout << ans << "\n";
	}
}
//바텀업으로 하면 더 빨랐네