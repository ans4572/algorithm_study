#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug

//에라토스 + 구간합 + 투포인터 방식도있음
bool chk[4000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int n = sqrt(N);
	for (int i = 2; i <= n + 1; i++) {
		for (int j = i + i; j <= N; j += i)
			chk[j] = true;
	}
	vector<int> V;
	for (int i = 2; i <= N; i++) {
		if (!chk[i]) V.push_back(i);
	}
	int l = 0;
	int r = 0;
	int siz = (int)V.size();
	int cnt = 0;
	int sum = 0;
	while (l < siz && r < siz) {
		while (sum < N && r < siz) {
			sum += V[r];
			r++;
		}
		while (sum >= N) {
			if (sum == N) cnt++;
			sum -= V[l];
			l++;
		}
	}
	cout << cnt << "\n";
}
