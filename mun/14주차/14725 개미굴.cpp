// https://www.acmicpc.net/problem/14725

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <map>

using namespace std;

// ���ڿ� ���� & Ž�� ����
// Ʈ���� Ȱ��
class Trie {

public:

	map<string, Trie*> m;

	// Ʈ���̿� ���ڿ� �߰� �Լ�
	void insert(vector<string> &arr, int idx) {
		// ������ ���� ������
		if (arr.size() == idx)
			return;

		auto f = m.find(arr[idx]);
		
		// �������� �ʴ� ���ڿ��̶�� �߰� ����
		if (f == m.end()) {
			m.insert({ arr[idx], new Trie() });
		}
		m[arr[idx]]->insert(arr, idx + 1);
	}
	
	// ��� ���
	void find(int d) {
		for (auto iter = m.begin(); iter != m.end(); ++iter) {

			for (int i = 0; i < d; ++i)
				cout << "--";
			cout << (*iter).first << "\n";

			(*iter).second->find(d + 1);
		}
	}
};

int main() {

	int N;
	cin >> N;

	Trie* root = new Trie();

	for (int i = 0; i < N; ++i) {
		int K;
		cin >> K;
		vector<string> arr(K);
		
		for (int i = 0; i < K; ++i)
			cin >> arr[i];

		root->insert(arr, 0);
	}
	root->find(0);

	return 0;
}