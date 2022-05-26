// 실패버전 
// 정확성: 25.0
// 효율성: 30.0
// 합계: 55.0 / 100.0

// words를 길이를 기준으로 vec의 인덱스별로 저장함. ex) frodo -> 길이 5이므로 vec[5]에 frodo 푸쉬
// vec의 인덱스에 쿼리 길이 집어넣은 뒤, 선형탐색. >> 시간초과 원인으로 파악.  

#include <string>
#include <vector>

using namespace std;

vector<string> vec[100002];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> result;
    
	for (auto w : words) {
		int len = w.length();
		vec[len].push_back(w);
	}

	for (auto q : queries) {
		int len = q.length();

		if (vec[len].size() == 0) result.push_back(0);
		else {
			int cnt = vec[len].size();

			for (int i = 0; i < vec[len].size(); i++) {
				for (int j = 0; j < vec[len][i].length(); j++) {
					
					if (q[j] != '?' && vec[len][i][j] != q[j]){
						cnt--;
						break;
					}
				}
			}
			result.push_back(cnt);
		}
	}

    return result;
}
