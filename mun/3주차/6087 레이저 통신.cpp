// https://www.acmicpc.net/problem/6087

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<climits>

using namespace std;

int W, H;
char board[101][101];
int minimum[101][101];

// 0: 오른쪽, 1: 아래, 2: 왼쪽, 3: 위
int dh[4] = { 0,1,0,-1 };
int dw[4] = { 1,0,-1,0 };
vector<pair<int, int>> cc;

class info {
public:
	int h = -1, w = -1;
	int dic = -1;     // 방향 저장
	int count = -1;

	info() {}
	info(int h, int w, int d, int c) {
		this->h = h;
		this->w = w;
		dic = d;
		count = c;
	}
};

int main() {

	cin >> W >> H;

	// input
	string s;
	for (int h = 0; h < H; ++h) {
		cin >> s;
		for (int w = 0; w < W; ++w) {
			board[h][w] = s[w];
			if (board[h][w] == 'C')
				cc.push_back(make_pair(h, w));
			minimum[h][w] = 100000000;
		}
	}

	queue<info> q;
	minimum[cc[0].first][cc[0].second] = 0;

	for (int d = 0; d < 4; ++d) {
		q.push(info(cc[0].first, cc[0].second, d, 0));
	}

	while (!q.empty()) {
		info now = q.front();
		q.pop();

		for (int d = 0; d < 4; ++d) {
			int nh = now.h + dh[d], nw = now.w + dw[d], nCount = now.count;
			if (nh >= 0 && nh < H && nw >= 0 && nw < W && board[nh][nw] != '*') {
				// 방향이 다른 경우는 거울 개수 추가
				if (d != now.dic)
					nCount += 1;

				if (minimum[nh][nw] >= nCount) {
					minimum[nh][nw] = nCount;
					q.push(info(nh, nw, d, nCount));
				}
			}
		}
	}

	cout << minimum[cc[1].first][cc[1].second] << endl;

	return 0;
}