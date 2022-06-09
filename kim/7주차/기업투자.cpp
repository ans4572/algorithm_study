#include<iostream>
#include<vector>
using namespace std;

int N, M;
int dp[21][301];
int company[21][301];	//기업별 투자금
int path[21][301];		//path[i][j]에 투자금 k를 저장. path[i-1][j]는 이전 기업의 마지막 투자금액이 담길것
vector<int> res;

int main() {

	cin >> N >> M;

	// dp[i][j] : 투자금 j를 가지고 0~i번째 기업 중 얻을 수 있는 최대이익
	// == 투자금 j-k 가지고 i-1번째 기업까지의 최대이익 + i번째 회사에 k만큼 투자이익
	// dp[i][j] = max(dp[i][j] || dp[i-1][j-k] + company[i][k])

	//company[i][j] : i번째 기업에 j만큼 투자시 얻는이익

	for (int i =  1; i <= N; i++) {
		int invest; cin >> invest;
		for (int j = 1; j <= M; j++) {
			cin >> company[j][invest];
		}
	}

	for (int i = 1; i <= M; i++) {			//기업
		for (int j = 1; j <= N; j++) {		//투자금액
			for (int k = 0; k <= j; k++) {	//기업의 투자금액 한도
				int val = dp[i - 1][j - k] + company[i][k];
				if (val > dp[i][j]) {
					dp[i][j] = val;
					path[i][j] = k;			
				}
			}
		}
	}

	cout << dp[M][N] << endl;

	int cost = N;	//최종 투자금
	for (int i = M; i > 0; i--) {
		int invest = path[i][cost];
		res.push_back(invest);
		cost -= invest;
	}

	for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";

	return 0;
}
