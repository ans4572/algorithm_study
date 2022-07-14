#include <string>
#include <vector>
#include<iostream>
using namespace std;

struct TRIE {
	TRIE* node[26];
	int cnt;	//빈도수 저장할 값

	TRIE() {
		this->cnt = 0;
		for (int i = 0; i < 26; i++) node[i] = NULL;
	}

	~TRIE() {
		for (int i = 0; i < 26; i++) if (node[i]) delete node[i];
	}

	void insert(const char* ch) {
		this->cnt++;	// 빈도수 증가

		if (!*ch) return;

		int now = *ch - 'a';
		if (!node[now]) node[now] = new TRIE;
		node[now]->insert(ch + 1);
	}

	int find(const char* ch, int idx) {
		if (*ch == NULL || this->cnt == 1) return idx;	//문자끝에 도달하거나, 중복아닌 문자열이 나오면 해당 길이 반환
		
		int now = *ch - 'a';
		return node[now]->find(ch + 1, idx + 1);
	}
};

int solution(vector<string> words) {
    int answer = 0;
    
    TRIE* root = new TRIE;
    for(auto val : words){
        root->insert(val.c_str());
    }
    
    for(auto val : words){
        answer += root->find(val.c_str(),0);
    }
    
    return answer;
}
