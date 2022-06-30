#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
using namespace std;

#define INF 987654321

int n; 
char map[51][51];
int visited[51][51][4];   // visited[i][j][k] : x,y,방향
int d[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };	//우 , 좌 , 아래 , 위
vector<pair<int, int>> door;                  //출구,입구 좌표 정보

struct Info {
	int x;
	int y;
	int dir;
};

void bfs(int x, int y) {                      // bfs 응용문제. 거울 설치하는 경우와 설치 안하는 경우가 포인트
	queue<Info> q;

	for (int i = 0; i < 4; i++) {
		q.push({ x,y,i });		//시작점에서 상하좌우 이동하도록 네방향 추가
		visited[x][y][i] = 0;	//방향 값 초기화
	}

	while (!q.empty()) {
		x = q.front().x;
		y = q.front().y;
		int dir = q.front().dir;
		q.pop();

		int nx = x + d[dir][0];
		int ny = y + d[dir][1];
		int nd1 = 0, nd2 = 0;     // nd1 : next dir1 , nd2 : nextt dir2  (거울 설치할 경우 이동가능한 방향이 두가지므로 변수 2개 생성)
    
		//다음 이동할 방향 구하기
		if (dir == 0 || dir == 1) {	// 좌우인 경우 nd는 위아래.	
			nd1 = 2;
			nd2 = 3;
		}
		else {						//위아래인 경우 nd는 좌우.
			nd1 = 0;
			nd2 = 1;
		}

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; //범위 체크
		if (map[nx][ny] == '*')continue;                      //벽 체크

		if (map[nx][ny] == '!') {
			if (visited[nx][ny][dir] > visited[x][y][dir]) {	//거울 설치 안하는 경우. 방향 바꿀필요 x.
				q.push({ nx,ny,dir });
				visited[nx][ny][dir] = visited[x][y][dir];
			}

			if (visited[nx][ny][nd1] > visited[x][y][dir] + 1) {  //거울 설치하는 경우. 방향은 nd1으로 
				q.push({ nx,ny,nd1 });
				visited[nx][ny][nd1] = visited[x][y][dir] + 1;
			}
      
			if (visited[nx][ny][nd2] > visited[x][y][dir] + 1) {  //거울 설치하는 경우. 방향은 nd2로
				q.push({ nx,ny,nd2 });
				visited[nx][ny][nd2] = visited[x][y][dir] + 1;
			}

		}
		else if (map[nx][ny] == '.') {		//.은 그냥 이동.
			if (visited[nx][ny][dir] > visited[x][y][dir]) {
				q.push({ nx,ny,dir });
				visited[nx][ny][dir] = visited[x][y][dir];
			}
		}
		else if (map[nx][ny] == '#') {		// #은 어차피 도착위치므로 큐를 넣지 않음.
			if (visited[nx][ny][dir] > visited[x][y][dir]) visited[nx][ny][dir] = visited[x][y][dir];
		}
		
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') door.push_back({ i,j });

			for (int k = 0; k < 4; k++) visited[i][j][k] = INF;
		}
	}

	bfs(door[0].first, door[0].second);

	int res = INF;
	for (int i = 0; i < 4; i++) {   //도착지의 네 방향중 최소값이 
		if (res > visited[door[1].first][door[1].second][i]) res = visited[door[1].first][door[1].second][i];
	}
	cout << res << "\n";

	return 0;
}
