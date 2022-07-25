#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int lcs[1001][1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string a, b;
	cin >> a >> b;

	for (int i = 1; i <= b.size(); i++) {
		for (int j = 1; j <= a.size(); j++) {
			if (a[j - 1] != b[i - 1]) lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);	//문자열 다르면 위쪽, 왼쪽 중 큰 값 가져옴
			else lcs[i][j] = lcs[i - 1][j - 1] + 1;								//문자열 같으면 왼쪽위의 값에서 1을 더함
		}
	}

	// 왼쪽으로 이동하는데, lcs값이 달라지면 문자열출력하고, 위로 이동.

	int len = a.size();
	string res="";

	for (int i = b.size(); i >= 0; i--) {
		if (lcs[i][len] == 0)break;
		for (int j = len; j >= 0; j--) {
			if (lcs[i][j] == lcs[i - 1][j]) break;
			if (lcs[i][j] != lcs[i][j - 1]) {	//값이 달라지면 위로이동
				res += a[j - 1];
				len = j - 1;
				break;
			}
		}
	}

	cout << lcs[b.size()][a.size()] << "\n";
	if (lcs[b.size()][a.size()] == 0) return 0;	//길이가 0이면 문자출력 안함	
	for (int i = res.size() - 1; i >= 0; i--)cout << res[i];


	return 0;
}
