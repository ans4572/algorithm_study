#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 987654321

int n, m, res = MAX;
int table[50][50];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
bool visited[13];

int getDistance(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int idx, int cnt) {	// idx : 0번서 시작 , cnt : 치킨 선택 갯수
	if (cnt == m) {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int dist = MAX;
			for (int j = 0; j < chicken.size(); j++) {
				if (visited[j]) dist = min(dist, getDistance(house[i], chicken[j]));
			}
			sum += dist;
		}
		res = min(res, sum);
		return;
	}

	if (idx == chicken.size()) return;
	visited[idx] = true;
	dfs(idx + 1, cnt + 1);
	visited[idx] = false;
	dfs(idx + 1, cnt);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> table[i][j];

			if (table[i][j] == 1) house.push_back({ i,j }); 
			else if (table[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	dfs(0,0);
	cout << res;

	return 0;
}
