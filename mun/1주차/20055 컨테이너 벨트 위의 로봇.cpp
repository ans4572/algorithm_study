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

		// 1. ��Ʈ�� �� ĭ ���� �ִ� �κ��� �Բ� �� ĭ ȸ��
		arr.push_front(arr.back());
		arr.pop_back();
		robot.push_front(robot.back());
		robot.pop_back();

		// �κ� ������
		if (robot[N - 1])
			robot[N - 1] = false;

		// 2. ���� ���� ��Ʈ�� �ö� �κ�����, ��Ʈ�� ȸ���ϴ� �������� �� ĭ �̵��� �� �ִٸ� �̵��Ѵ�. ���� �̵��� �� ���ٸ� ������ �ִ´�
		for (int i = N - 2; i >= 0; --i) {
			if (robot[i] && !robot[i + 1] && arr[i + 1] >= 1) {
				robot[i] = false;
				arr[i + 1]--;
				if (i == N - 2)
					continue;
				robot[i + 1] = true;
			}
		}

		// 3. �ø��� ��ġ�� �ִ� ĭ�� �������� 0�� �ƴϸ� �ø��� ��ġ�� �κ��� �ø���.
		if (arr[0] >= 1 && !robot[0]) {
			arr[0]--;
			robot[0] = true;
		}

		// 4. �������� 0�� ĭ�� ������ K�� �̻��̶�� ������ �����Ѵ�. �׷��� �ʴٸ� 1������ ���ư���.
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