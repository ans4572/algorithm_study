#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;

int n, res = 0;
char table[51][51];

void check() {
	char c;

	// 행 검사
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		c = table[i][0];
		for (int j = 1; j < n; j++) {
			if (table[i][j] == c) cnt++;
			else cnt = 1;
			c = table[i][j];
			if (res < cnt)res = cnt;
		}
	}

	// 열 검사
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		c = table[0][i];
		for (int j = 1; j < n; j++) {
			if (table[j][i] == c) cnt++;
			else cnt = 1;
			c = table[j][i];
			if (res < cnt)res = cnt;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> table[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == n - 1 && j == n-1) continue;
			else if (i == n - 1) {	// 오른쪽만 탐색
				swap(table[i][j], table[i][j + 1]);
				check();
				swap(table[i][j], table[i][j + 1]);
			}
			else if (j == n - 1) {	// 아래만 탐색
				swap(table[i][j], table[i + 1][j]);
				check();
				swap(table[i][j], table[i + 1][j]);
			}
			else {	//아래, 오른쪽 모두 탐색
				swap(table[i][j], table[i][j + 1]);
				check();
				swap(table[i][j], table[i][j + 1]);

				swap(table[i][j], table[i + 1][j]);
				check();
				swap(table[i][j], table[i + 1][j]);
			}
		}
	}

	cout << res;

	return 0;
}
