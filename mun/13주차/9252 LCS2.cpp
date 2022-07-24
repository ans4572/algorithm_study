// https://www.acmicpc.net/problem/9252

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

int dy[1001][1001];
string lcs[1001][1001];

int main() {
	string a, b;
	cin >> a;
	cin >> b;

	int ans = 0;
	int idx = -1;
	for (int i = 1; i <= a.length(); ++i) {
		for (int j = 1; j <= b.length(); ++j) {
			if (a[i - 1] == b[j - 1]) {
				dy[i][j] = dy[i - 1][j - 1] + 1;
				lcs[i][j] = lcs[i][j] + lcs[i - 1][j - 1] + a[i - 1];
			}
			else {
				dy[i][j] = max(dy[i - 1][j], dy[i][j - 1]);
				if (lcs[i - 1][j].length() > lcs[i][j - 1].length())
					lcs[i][j] = lcs[i - 1][j];
				else
					lcs[i][j] = lcs[i][j - 1];
			}
		}
	}

	cout << dy[a.length()][b.length()] << endl;
	cout << lcs[a.length()][b.length()] << endl;

	return 0;
}
