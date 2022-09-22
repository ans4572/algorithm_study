#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug

/*
1. 경로에 돌 있는지 체크할 때 좌표문제
2. visit 배열을 분리하면 안됐음(4차원에서 2차원으로 분리할거면 서로가 서로의 좌표들을 벡터로 보관했어야)
3. blue 먼저 빠지는 경우 간과
*/


int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
int N, M;
vector<string> mp;
int vst[10][10][10][10];
pair<int, int> r;
pair<int, int> b;
pair<int, int> goal;

bool isValidPos(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < M;
}

struct Status {
	int cost = 0;
	pair<int, int> r;
	pair<int, int> b;
	int beforeDirect;

	Status(pair<int, int> r, pair<int, int> b, int cost, int beforeDirect) {
		this->cost = cost;
		this->beforeDirect = beforeDirect;
		this->r = r;
		this->b = b;
	}

	pair<int, int> getNextPos(pair<int, int>curr, int dir) {
		bool existOther = false;
		int nr = curr.first + dr[dir];
		int nc = curr.second + dc[dir];
		while (isValidPos(nr, nc) && mp[nr][nc] != '#') {
			if (this->r == make_pair(nr, nc) || this->b == make_pair(nr, nc)) existOther = true;
			if (mp[nr][nc] == 'O') return { nr, nc };
			nr += dr[dir];
			nc += dc[dir];
		}
		nr -= dr[dir];
		nc -= dc[dir];
		if (existOther) {
			nr -= dr[dir];
			nc -= dc[dir];
		}
		return { nr, nc };
	}

	vector<Status> getNextStatus() {
		vector<Status> ret;
		for (int i = 0; i < 4; i++) {
			auto nr = getNextPos(this->r, i);
			auto nb = getNextPos(this->b, i);
			if (nr == nb || nb == goal) continue;
			ret.push_back(Status(nr, nb, this->cost + 1, i));
		}
		return ret;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	mp.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> mp[i];
		for (int j = 0; j < M; j++)
			if (mp[i][j] == 'R') {
				r = { i, j };
			}
			else if (mp[i][j] == 'B') {
				b = { i, j };
			}
			else if (mp[i][j] == 'O') {
				goal = { i, j };
			}
	}
	queue<Status> q;
	vst[r.first][r.second][b.first][b.second] = 1;
	q.push(Status(r, b, 1, -1));
	while (!q.empty()) {
		auto& status = q.front();
		if (status.cost == 12) {
			cout << -1 << "\n";
			return 0;
		}
		if (status.r == goal) {
			cout << status.cost - 1 << "\n";
			return 0;
		}
		auto V = status.getNextStatus();
		for (auto& it : V) {
			if (vst[it.r.first][it.r.second][it.b.first][it.b.second]) continue;
			vst[it.r.first][it.r.second][it.b.first][it.b.second] = 1;
			q.push(it);
		}
		q.pop();
	}
	cout << "-1\n";
}
