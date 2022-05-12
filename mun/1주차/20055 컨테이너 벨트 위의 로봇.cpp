// https://www.acmicpc.net/problem/20055

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
deque<int> arr;
deque<bool> robot;

int simulation() {
	int ans = 0;

	while ( true ) {
		ans++;

		// 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전
		arr.push_front(arr.back());
		arr.pop_back();
		robot.push_front(robot.back());
		robot.pop_back();

		// 로봇 내리기
		if (robot[N - 1])
			robot[N - 1] = false;

		// 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다
		for (int i = N - 2; i >= 0; --i) {
			if (robot[i] && !robot[i + 1] && arr[i + 1] >= 1) {
				robot[i] = false;
				arr[i + 1]--;
				if (i == N - 2)
					continue;
				robot[i + 1] = true;
			}
		}

		// 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
		if (arr[0] >= 1 && !robot[0]) {
			arr[0]--;
			robot[0] = true;
		}

		// 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
		int k = 0;
		for (int i = 0; i < arr.size(); ++i) {
			if (arr[i] == 0)
				k++;
		}

		if (k >= K)
			return ans;
	}
}

int main() {
	cin >> N >> K;

	int input;
	for (int i = 0; i < N * 2; ++i) {
		cin >> input;
		arr.push_back(input);
		robot.push_back(false);
	}

	cout << simulation() << endl;

	return 0;
}