#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
	int k,n; cin >> k >> n;
  
	vector<int> vec(k);
  
	for (int i = 0; i < k; i++) cin >> vec[i];
	sort(vec.begin(), vec.end());

	long long start = 1;
	long long end = vec.back();

	while (start<=end) {
		int cnt = 0; //랜선 수
		long long mid = (start + end) / 2;

		for (int i = 0; i < k; i++) cnt += vec[i] / mid;

		if (cnt < n) end = mid - 1;
		else start = mid + 1;
	}
	cout <<end;
}
