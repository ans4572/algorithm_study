#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug

int mp[51][51];
vector<pair<int, int>> home;
vector<pair<int, int>> chk;
int N, M;

int evalChkDistance(pair<int, int> house, vector<pair<int, int>>& candidate) {
	int ret = INT_MAX;
	for (auto it : candidate)
		ret = min(ret, abs(house.first - it.first) + abs(house.second - it.second));
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 1)
				home.push_back({ i, j });
			else if (mp[i][j] == 2)
				chk.push_back({ i, j });
		}

	const int chkCount = chk.size();
	vector<int> seed(chkCount);
	for (int i = chkCount - M; i < chkCount; i++)
		seed[i] = 1;
	int ans = INT_MAX;

	do {
		vector<pair<int, int>> tmp;
		for (int i = 0; i < chkCount; i++) {
			if (seed[i] == 1) {
				tmp.push_back(chk[i]);
			}
		}
		int tmpDistance = 0;
		for (auto it : home) {
			tmpDistance += evalChkDistance(it, tmp);
		}
		ans = min(ans, tmpDistance);
	} while (next_permutation(seed.begin(), seed.end()));

	cout << ans << "\n";
}
