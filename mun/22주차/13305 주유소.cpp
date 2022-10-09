// https://www.acmicpc.net/problem/13305

#include <iostream>
#include <algorithm>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

int p[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, s;
	cin >> N;

	long long sum = 0, minPrice = 1000000000;

	for (int i = 0; i < N - 1; i++)
		cin >> p[i];

	for (int i = 0; i < N - 1; i++) {
		cin >> s;
		minPrice = minPrice > s ? s : minPrice;
		sum += minPrice * p[i];
	}
	cout << sum << endl;

	return 0;
}