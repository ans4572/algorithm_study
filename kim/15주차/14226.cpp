#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int s;
bool visited[1001][1001];

struct Info {
	int clip;	// 클립보드 임티개수
	int screen;	// 화면 임티개수
	int depth;	// 몇초인지 (bfs == 깊이)
};

void bfs(){
	queue<Info> q;
	q.push({ 0,1,0 });
	visited[0][1] = true;

	while (!q.empty()) {
		int clip = q.front().clip;
		int screen = q.front().screen;
		int depth = q.front().depth;
		q.pop();

		if (screen == s) {
			cout << depth;
			return;
		}
		
		if (screen > 0 && screen < 1001) {
			if (!visited[screen][screen]) {
				visited[screen][screen] = true;
				q.push({ screen, screen, depth + 1 });	// 임티 클립보드에 저장 : 클립보드 개수 = 화면 임티 개수 
			}
			if (!visited[clip][screen - 1]) {
				visited[clip][screen - 1] = true;
				q.push({ clip , screen - 1 , depth + 1 });		//화면에 임티 1개 제거
			}
		}
		if (clip > 0 && screen + clip < 1001) {
			if (!visited[clip][screen + clip]) {
				visited[clip][screen + clip] = true;
				q.push({ clip, screen + clip , depth + 1 });	//화면에 복사 : 화면 개수 = 클립 + 화면
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> s;	
	bfs();

	return 0;
}
