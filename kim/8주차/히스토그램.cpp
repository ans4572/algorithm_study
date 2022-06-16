#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

stack<int> s;
int n, maxVal=0;
int arr[100002];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	s.push(0);
	for (int i = 1; i <= n+1; i++) {
		//push하려는 막대 높이가 스택의 top보다 크거나 같으면 계속 푸쉬. 근데, 작으면 top의 높이가 push하려는 막대의 높이보다 작아질때까지 pop
		while (!s.empty() && arr[s.top()] > arr[i]) {
			int num = s.top();
			s.pop();
			maxVal = max(maxVal, arr[num] * (i - s.top() - 1));
		}
		s.push(i);
	}

	cout << maxVal;

	return 0;
}
