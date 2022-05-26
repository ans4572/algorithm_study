#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

//2098. 외판원 순환.

// 도시개수가 주어질때 임의의 도시에서 시작해 모든 도시를 거쳐 다시 출발점으로 돌아오는 최소비용.
// 완전탐색의 경우 최악의 경우 도시개수가 16인경우 16! 시간복잡도 가짐. 
// 때문에 보통 외판원 문제 해결법으로 비트마스크와 dp 메모제이션을 사용한다.
// 비트마스크를 통해 도시방문여부를 확인할 수 있다. 예를들어 5개 도시 방문여부를 확인한다고 했을때
// 0번째 도시는 5비트 중 0번째 위치에 1을 놓으면 방문했다는 의미이다. 00001
// 1번째 도시는 5비트 중 1번째 위치에 1을 놓으면 방문했다는 의미이다. 00010
// 0번째 도시와 1번째 도시를 방문했다면 다음과 같이 표현될 것이다. 00011
// 이런식으로 비트마스크를 통해 단 5비트만으로 5개의 도시 방문여부를 확인할 수 있는것이다 >> 비트연산이기 때문에 bool같이
// 다른 자료형보다 속도가 빠르고 코드도 간결해진다. 
// 비트마스킹을 사용한다면 O(2^n) 시간복잡도를 가질 수 있다. 하지만 dp 메모제이션을 사용하면 더 속도가 빨라질 수 있다.

int N;
int W[16][16];
int dp[16][1 << 16];	//dp[i][j] >> i : 현재 도시 위치, j : 현재위치에서 다른 도시들 방문여부, 값 : 가중치

int TSP(int start, int visited) {
	int ret = dp[start][visited];
	
	if (ret) return ret;		//dp 메모제이션 : 이미 있는값은 패스
	
	if (visited == (1 << N) - 1) {	//모든 다 도시를 방문하고 도시 0으로 돌아온 경우 최소값 반환
		if (W[start][0] != 0) {		//도시 0 아닌경우
			return W[start][0];
		}
		return 9987654321;
	}

	ret = 9987654321;

	for (int i = 0; i < N; i++) {
		if (visited & (1 << i) || W[start][i] == 0) continue;	//방문했거나 길 없는경우
		ret = min(ret, W[start][i] + TSP(i, visited | 1 << i));	//start에서 i로 간다음 i에서 나머지 도시 순회한 것 혹은 ret 중 비교
	}
	dp[start][visited] = ret;
	return ret;
}

int main() {
	cin >> N; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	cout << TSP(0, 1) << endl;
}
