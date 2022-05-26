#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {

	// A(1,2,3) B(4,5)가 있다고 한다면(홀수) 중간값은 A의 최대값인 3이 된다.
	// A(1,2)   B(3,4)가 있다고 한다면(짝수) 중간값은 A의 최대값인 2가 된다.
	// A는 B보다 작은 값만 넣어준다.
	// 만약 A에 5를 넣었다면 A(1,2,5) B(3,4)가 될것이다.
	// A의 최대값은 5, B의 최소값은 3이므로 위 규칙이 적용되지 않는다.
	// 이때는 A의 최대값과 B의 최소값을 교환하면 된다. 그러면 A(1,2,3) B(4,5)가 될것이다. 그럼 여기서는 중간값 적용 가능.

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> maxpq;
	priority_queue<int> minpq;


	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		//크기가 작은경우 최소힙 쪽에 집어넣음. 그리고 최대힙과 비교해서 최대힙쪽이 더 작으면 그때 스왑함.
		if (i == 1) minpq.push(a);
		else {

			if (minpq.size() <= maxpq.size()) minpq.push(a);
			else maxpq.push(a);

			if (minpq.top() > maxpq.top()) {
				int a = minpq.top();
				int b = maxpq.top();
				minpq.pop();
				maxpq.pop();
				minpq.push(b);
				maxpq.push(a);
			}
		}

		cout << minpq.top() << "\n";
	}

}
