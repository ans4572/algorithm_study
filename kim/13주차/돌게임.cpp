#include<iostream>
using namespace std;

int n;
int dp[1000];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	dp[1] = n;

	bool isSK = true;
	for (int i = 2; i <= n; i++) {
		dp[i] = min(dp[i - 1] - 1, dp[i - 1] - 3);
		isSK = !isSK;
		if (dp[i] == 1) break;
	}

	if (!isSK) cout << "CY";
	else cout << "SK";
	
	return 0;
}
