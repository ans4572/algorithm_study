#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int n;

struct Trie {

	map<string, Trie*> child;

	void Insert(vector<string> &vec, int idx) {
		if (vec.size() == idx) return;              //끝에 오면 종료

		if (child.find(vec[idx]) == child.end()) {	//idx번째의 문자열이 맵에 없는경우 새로 생성
			child.insert({ vec[idx], new Trie() });
		}

		child[vec[idx]]->Insert(vec, idx + 1);		// 다음 인덱스로 이동
	}

	void find(int depth) {							// 깊이 탐색
		for (auto& val : child) {
			for (int i = 0; i < depth; ++i) cout << "--";
			cout << val.first << "\n";
			val.second->find(depth + 1);
		}
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	Trie *root = new Trie();

	for (int i = 0; i < n; i++) {
		int k; cin >> k;		
		vector<string> vec(k);

		for (int j = 0; j < k; j++) cin >> vec[j];
		root->Insert(vec, 0);
	}

	root->find(0);

	return 0;
}
