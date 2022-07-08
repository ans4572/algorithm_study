//9655

#include<iostream>
using namespace std;

int n;
int dp[1000];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	dp[1] = n;	//dp 1회차에 남은 돌개수 n개

	bool isSK = true;	//상근이 선
	for (int i = 2; i <= n; i++) {
		dp[i] = min(dp[i - 1] - 1, dp[i - 1] - 3);	// 이전회차에 남은 돌개수에서 1개, 3개 뺀값 중 최소값
		isSK = !isSK;
		if (dp[i] == 1) break;
	}

	if (!isSK) cout << "CY";
	else cout << "SK";
	
	return 0;
}
