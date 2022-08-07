#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[1001][1001];

int start(int left, int right, bool isYou, vector<int>& card) {
	if (left > right) return 0;
	if (dp[left][right]) return dp[left][right];

	if (isYou) {	//근우 : 근우 점수 구해야 하기 때문에 현재 카드 점수와 다음 선택할 카드 점수를 더한다.
		int a = card[left] + start(left + 1, right, !isYou, card);
		int b = card[right] + start(left, right - 1, !isYou, card);

		return dp[left][right] = max(a, b);	//근우는 최대값 선택
	}
	else {			//명우
		int a = start(left + 1, right, !isYou, card);
		int b = start(left, right - 1, !isYou, card);
		
		return dp[left][right] = min(a, b);	//명우는 최소값 선택
	}
	
	return dp[left][right];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;

		vector<int> card(n);
		for (int j = 0; j < n; j++) cin >> card[j];

		cout << start(0, n - 1, true, card) << "\n";
		memset(dp, 0, sizeof(dp));
	}

	return 0;
}
