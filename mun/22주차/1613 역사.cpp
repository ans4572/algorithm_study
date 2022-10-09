// https://www.acmicpc.net/problem/1613

#include <iostream>
#include <algorithm>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

int N, K, S;
int history[401][401];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	
	int a, b;
	for (int i = 0; i < K; ++i) {
		cin >> a >> b;
		history[a][b] = 1;
		history[b][a] = -1;
	}

	// 플로이드 워샬
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (history[i][j] == 0) {
					// i > k && k > j => i > j
					if (history[i][k] == 1 && history[k][j] == 1)
						history[i][j] = 1;
					// i < k && k < j => i < j
					else if(history[i][k] == -1 && history[k][j] == -1)
						history[i][j] = -1;
				}
			}
		}
	}

	cin >> S;
	for (int i = 0; i < S; ++i) {
		cin >> a >> b;
		cout << -1 * history[a][b] << "\n";  // endl으로 하면 시간초과...
	}

	return 0;
}