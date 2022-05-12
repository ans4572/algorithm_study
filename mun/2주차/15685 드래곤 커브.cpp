// https://www.acmicpc.net/problem/15685

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int dx[4] = { +1, 0, -1, 0 };
int dy[4] = { 0, -1,0,+1 };
bool board[101][101];

class point {
public:
	int x1 = 0, y1 = 0;  // 시작점
	int x2 = 0, y2 = 0;  // 도착점
	int d = 0;           // 방향

	point() {}
	point(int x, int y, int d) {
		this->x1 = x;
		this->y1 = y;
		this->d = d;
		x2 = x1 + dx[d];
		y2 = y1 + dy[d];
	}
};

// 만든 드래곤 커브를 맵에 반영
void push_map(vector<point> vec) {
	for ( const point p : vec) {
		board[p.x1][p.y1] = true;
		board[p.x2][p.y2] = true;
	}

	return;
}

// 드래곤 커브 만드는 함수
void make_curve(int x, int y, int d, int g) {
	int count = 0;

	vector<point> vec;
	vec.push_back(point(x, y, d));

	// 세대만큼 vector 확장하면서 진행
	while (count < g) {
		count++;

		int size = vec.size();
		int nd;
		int lastX = vec.back().x2, lastY = vec.back().y2;
		for (int i = size - 1; i >= 0; --i) {
			nd = (vec[i].d + 1) % 4;  // 방향 1번 이동
			vec.push_back(point(lastX, lastY, nd));
			lastX = vec.back().x2;
			lastY = vec.back().y2;
		}
	}

	push_map(vec);

	return;
}

int main() {
	int N;
	cin >> N;

	int x, y, d, g;
	for (int i = 0; i < N; ++i) {
		cin >> x >> y >> d >> g;
		make_curve(x, y, d, g);
	}

	int ans = 0;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
				ans++;
		}
	}

	cout << ans << endl;

	return 0;
}