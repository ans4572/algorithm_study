// https://www.acmicpc.net/problem/16953

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

// int로 하면 실패 => long long으로 변경..

long long A, B;
long long ans = 1000000001;

void cal(long long num, long long count) {
	if (num > B)
		return;
	else if (num == B) {
		ans = min(ans, count);
	}
	else {
		cal(num * 2, count + 1);
		cal(num * 10 + 1, count + 1);
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B;

	cal(A, 1);

	if (ans == 1000000001)
		cout << -1 << endl;
	else
		cout << ans << endl;

	return 0;
}
