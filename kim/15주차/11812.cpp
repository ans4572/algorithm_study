#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

long long int n;
int k, q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k >> q;

	long long int x, y , cnt = 0;
	for (int i = 0; i < q; i++) {
		cin >> x >> y;
		cnt = 0;
		if (k == 1) cnt = abs(x - y);
		else {
			while (x != y) {
				if (x > y) x = (x - 2) / k + 1;
				else y = (y - 2) / k + 1;
				++cnt;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}
