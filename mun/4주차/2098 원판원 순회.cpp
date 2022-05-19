// https://www.acmicpc.net/problem/2098

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

const int INF = 16000001;

int N;
int city[16][16];
int dp[16][1 << 16];   //��Ʈ����ũ�� Ȱ���ؼ� ���̳��� �迭 ����, dp[i][j] => i: ���� ����, j: �湮�� ���õ� ǥ�� ��Ʈ

int DFS(int nowCity, int visited) {
	//��� �湮�� �� �� ��� => 11...11
	if (visited == (1 << N) - 1) {
		//���� ���ÿ� 0��° ���ð��� �������� ���� ���
		if (city[nowCity][0] == 0)
			return INF;
		else
			return city[nowCity][0];
	}

	if (dp[nowCity][visited] != 0)
		return dp[nowCity][visited];

	dp[nowCity][visited] = INF;

	for (int i = 0; i < N; ++i) {
		//���� �ȵǾ��ִ� ���
		if (city[nowCity][i] == 0)
			continue;
		//�̹� �湮�� ���� ���
		if ((visited & (1 << i)) > 0)
			continue;

		//��ȭ��
		dp[nowCity][visited] = min(dp[nowCity][visited], city[nowCity][i] + DFS(i, visited | (1 << i)));
	}

	return dp[nowCity][visited];
}

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> city[i][j];
		}
	}

	cout << DFS(0, 1) << endl;

	return 0;
}