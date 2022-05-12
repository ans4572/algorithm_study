// https://www.acmicpc.net/problem/4991

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<climits>

using namespace std;

int H, W;
char board[21][21];
int dist[21][21];
bool visit[21][21];
int dirtydist[12][12];
int dh[4] = { 0,1,0,-1 };
int dw[4] = { 1,0,-1,0 };
pair<int, int> start;
vector<pair<int, int> > dirty;

// start to end
int BFS(int sh, int sw, int eh, int ew) {

	memset(dist, 0, sizeof(dist));
	memset(visit, false, sizeof(visit));

	queue<pair<int, int> > q;

	q.push(make_pair(sh, sw));
	visit[sh][sw] = true;

	while (!q.empty()) {
		int h = q.front().first;
		int w = q.front().second;
		q.pop();

		for (int d = 0; d < 4; ++d) {
			int nh = h + dh[d];
			int nw = w + dw[d];
			if (nh >= 0 && nh < H && nw >= 0 && nw < W && !visit[nh][nw]) {
				if (board[nh][nw] != 'x') {
					visit[nh][nw] = true;
					dist[nh][nw] = dist[h][w] + 1;
					q.push(make_pair(nh, nw));
				}
			}
		}
	}

	return dist[eh][ew];
}

int main() {

	while (true) {
		cin >> W >> H;

		if (W == 0 && H == 0)
			break;

		dirty.clear();

		for (int h = 0; h < H; ++h) {
			for (int w = 0; w < W; ++w) {
				cin >> board[h][w];
				if (board[h][w] == 'o') {
					start.first = h;
					start.second = w;
				}
				if (board[h][w] == '*')
					dirty.push_back(make_pair(h, w));
			}
		}

		// dirtydist 배열 만들기
		bool possible = true;
		for (int i = 0; i < dirty.size(); ++i) {

			// 1. 청소기와 더러운 곳간의 거리 계산
			int dis = BFS(start.first, start.second, dirty[i].first, dirty[i].second);

			// 못가는 경우
			if (dis == 0) {
				possible = false;
				break;
			}
			else
				dirtydist[11][i] = dis;

			// 2. 해당 더러운 곳과 나머지 더러운 곳들 거리 계산
			for (int j = i + 1; j < dirty.size(); ++j) {

				if (i != j) {
					dis = BFS(dirty[i].first, dirty[i].second, dirty[j].first, dirty[j].second);

					dirtydist[i][j] = dis;
					dirtydist[j][i] = dis;
				}
			}
		}

		vector<int> order;

		for (int i = 0; i < dirty.size(); ++i)
			order.push_back(i);

		int minCount = -1;
		
		if (possible) {
			// 순열을 활용하여 모든 방법 탐색 진행
			do {
				int count = dirtydist[11][order[0]];

				for (int i = 0; i < dirty.size() - 1; ++i) {
					count += dirtydist[order[i]][order[i + 1]];
				}

				if (minCount == -1 || minCount > count)
					minCount = count;
			} while (next_permutation(order.begin(), order.end()));
		}

		if (!possible || minCount == 0)
			cout << -1 << endl;
		else
			cout << minCount << endl;
	}

	return 0;
}