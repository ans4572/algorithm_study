#include<iostream>
#include<algorithm>
using namespace std;

long long a, b;
int res = 987654321;

void check(long long num , int cnt) {
	if (num > b) return;
	if (num == b) res = min(res, cnt);

	check(num * 2, cnt + 1);
	check(num * 10 + 1, cnt + 1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> a >> b;

	check(a, 1);

	if (res == 987654321) cout << -1;
	else cout << res;

	return 0;
}
