#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, sum;
int memory[101];
int cost[101];
int dp[10001];	

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> memory[i];
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
		sum += cost[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = sum; j >= cost[i]; j--) {
			dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
		}
	}

	for (int i = 0; i < 10001; i++) {
		if (dp[i] >= m) {
			cout << i;
			break;
		}
	}

	return 0;
}
