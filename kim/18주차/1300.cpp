#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

long long n, k;

long long getCnt(long long mid) {
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {			//i행은 i배수의 집합. 예를들어 i가 3이면 3,6,9,12,15가 저장된다. 그 중에서 mid에서 i를 나누면 mid가 몇 번째에 위치하는지 알 수 있다.
		cnt += min(n, (long long)mid / i);
		if (i > mid) break;	//값이 mid보다 커지면 계산할 필요 없으므로 종료.
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	long long s = 1;
	long long e = n * n;

	int res = 0;	

	while (s <= e) {
		long long mid = (s + e) / 2;

		if (getCnt(mid) < k) s = mid + 1;//k보다 cnt(mid보다 작은 값의 개수)가 작으면 mid를 높여야 한다.
		else {
			res = mid;
			e = mid - 1;
		}
	}

	cout << res;

	return 0;
}
