#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int t, n, m;
int lastRes[505];	// 작년 팀 순위
int teamCnt[505];		// 현재 팀보다 아래 순위인 팀 개수
int cnt[505];
vector<int> team[505];  //현재 팀보다 아래 순위인 팀들 저장

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++) {
		
    //초기화
		memset(lastRes, 0, sizeof(lastRes));
		memset(teamCnt, 0, sizeof(teamCnt));
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j <= n; j++) team[j].clear();

		cin >> n;
		for (int j = 1; j <= n; j++) {	//작년 팀순위 입력
			int num; cin >> num;
			lastRes[j] = num;			// 5 4 3 2 1
		}

		for (int j = 1; j < n; j++) {
			for (int k = j + 1; k <= n; k++) {
				team[lastRes[j]].push_back(lastRes[k]);   // 현재 팀 보다 아래 순위인 팀들 저장. ex) 5번팀 = {4,3,2,1} , 4번팀 = {3,2,1} ...
			}
			teamCnt[lastRes[j]] = team[lastRes[j]].size();  
		}


		cin >> m;
		for (int j = 0; j < m; j++) {	//바뀐 팀 정보 입력
			int a, b; cin >> a >> b;

			bool isFind = false;
			for (auto val : team[a]) {	// ex) a : 2 , b : 4
				if (val == b) {           // 2번팀에 4가 있으면 isFind true
					isFind = true;
					break;
				}
			}

      if (isFind) {	// 2팀 -1, 4팀 +1
				teamCnt[a] -= 1;
				teamCnt[b] += 1;
			}
			else {			// 2팀 +1, 4탐 -1
				teamCnt[a] += 1;
				teamCnt[b] -= 1;
			}

		}


		bool isImpossible = false;		// IMPOSSIBLE 여부
		vector<pair<int, int>> res;


		for (int j = 1; j <= n; j++) {
			cnt[teamCnt[j]]++;			// 팀 순위 빈도수 저장
			res.push_back({ j,teamCnt[j] });
			if (cnt[teamCnt[j]] > 1) isImpossible = true;	// 만약 같은 순위가 여러개라면 IMPOSSIBLE 출력
		}

		if (cnt[0] > 1) {		// 0이 여러개라면  ? 출력하고 종료.
			cout << "?" << "\n";
			continue;
		}

		if (isImpossible) {		// 임파시블 출력.
			cout << "IMPOSSIBLE" << "\n";
			continue;
		}

		sort(res.begin(), res.end(), cmp);  // 횟수 순서대로 정렬

		for (auto val : res) cout << val.first << " ";
		cout << "\n";
		
	}
	
	return 0;
}
