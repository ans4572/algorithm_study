#include<iostream>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<functional>
using namespace std;

//1339번. 단어 수학
vector<string> word;
map<char, int> alpha;

bool cmp(pair<char, int> a, pair<char, int> b) {
	return a.second > b.second;
}

int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		string str; cin >> str;
		word.push_back(str);
	}

	for (int i = 0; i < word.size(); i++) {
		int pow = 1;
		for (int j = word[i].size() - 1; j >= 0; j--) {
			alpha[word[i][j]] += pow;					//알파벳별 자릿수 저장
			pow *= 10;
		}
	}
	vector<pair<char, int>> vec(alpha.begin(), alpha.end());	//높은 자릿수 기준으로 정렬
	sort(vec.begin(), vec.end(), cmp);

	int num = 9, res = 0;
	for (int i = 0; i < vec.size(); i++) {
		res += vec[i].second*num;
		num--;
	}
	cout << res << endl;
}
