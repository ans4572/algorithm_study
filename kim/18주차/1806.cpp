#include<iostream>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, s; cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	int start = 0, goal = 0;
	int res = 0;
	int sum = arr[0];

	while (start <= goal) {
		int len = goal - start + 1;

		if (sum >= s) {	//s보다 크면 start를 늘려보면서 len을 줄이는 작업 실행
			if (res == 0 || res > len) res = len;
			
			sum -= arr[start];
			start++;
		}
		else {			//s보다 작으면 goal을 늘려서 len을 키움
			goal++;
			if (goal == n) break;	//끝에 도달하면 종료
			sum += arr[goal];
		}

	}

	cout << res;

	return 0;
}
