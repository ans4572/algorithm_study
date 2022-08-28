#include<iostream>
using namespace std;

int n, m;
int arr[2001];
bool dp[2001][2001] = { false };	//dp[s][e] = res (0 or 1)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i][i] = true;	//(1,1) (2,2) 같이 한자릿수는 무조건 true

		if (arr[i] == arr[i - 1]) dp[i - 1][i] = true;	// 두자릿수 비교
	}

	for (int i = 2; i < n; i++) {
		for (int s = 1; s <= n - i; s++) {
			int e = i + s;
			if (arr[s] == arr[e] && dp[s + 1][e - 1]) dp[s][e] = true;
		}
	}
	
	cin >> m; 

	for (int i = 0; i < m; i++) {
		int s, e; cin >> s >> e;
		cout << dp[s][e] << "\n";
	}
	
	return 0;
}
