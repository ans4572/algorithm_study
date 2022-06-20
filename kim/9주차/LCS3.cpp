#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<functional>
using namespace std;

int table[101][101][101];

int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	s1 = ' ' + s1;
	s2 = ' ' + s2;
	s3 = ' ' + s3;

	for (int i = 1; i < s1.size(); i++) {
		for (int j = 1; j < s2.size(); j++) {
			for (int k = 1; k < s3.size(); k++) {
				if (s1[i] == s2[j] && s2[j] == s3[k]) table[i][j][k] = table[i - 1][j - 1][k - 1] + 1;
				else {
					int m = max(table[i - 1][j][k], table[i][j - 1][k]);
					m = max(m, table[i][j][k - 1]);
					table[i][j][k] = m;
				}
			}
		}
	}

	cout << table[s1.size() - 1][s2.size() - 1][s3.size() - 1];
}
