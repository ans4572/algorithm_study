#include<iostream>
#include<vector>
using namespace std;

//2482. 색상환

int dp[1001][1001];		//dp[N]K]  :  N개 색상환중에 K개의 색 선택할때 경우의 수
#define mod 1000000003;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K; cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		dp[i][1] = i;	//총 i가지 중에 1개만 선택하는 경우
		dp[i][0] = 1;	//선택개수가 0인경우 경우의수는 1밖에 없다.
	}

	//예를들어 3번째에 있는 색을 선택하면 2번째의 색은 선택하지 못하고 1번에서 2번 중에 j-1개의 색을 선택하는 것과 같다.dp[i-2][j-1]
	//만약 3번째 색을 선택하지 않으면 1~i-1까지 색 중 j개의 색을 선택하는 것과 같다. dp[i-1][j]
	for (int i = 4; i <= N; i++) {
		for (int j = 2; j <= K; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % mod;	
		}
	}
	cout << dp[N][K] % mod;
}
