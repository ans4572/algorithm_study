#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

const int INF = 1000000000;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;

    vector<vector<int>> edge(n + 1);
    for (int i = 0; i < m; ++i) {
        edge[edge_list[i][0]].push_back(edge_list[i][1]);
        edge[edge_list[i][1]].push_back(edge_list[i][0]);
    }
    
    // dp 활용
    vector<vector<int>> dp(k, vector<int>(n + 1, INF));
    dp[0][gps_log[0]] = 0;  // 시작점
    for (int t = 1; t < k; ++t) {
        for (int i = 1; i <= n; ++i) {
            int minValue = dp[t - 1][i];

            for (int j = 0; j < edge[i].size(); ++j) {
                minValue = min(dp[t - 1][edge[i][j]], minValue);
            }

            // 수정이 필요한 경우
            if (gps_log[t] != i)
                dp[t][i] = minValue + 1;
            else
                dp[t][i] = minValue;
        }
    }

    answer = dp[k - 1][gps_log[k - 1]];
    if (answer > INF) return -1;

    return answer;
}

int main() {

    int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log;
    n = 7;
    m = 10;
    edge_list = { {1,2},{1,3},{2,3},{2,4},{3,4},{3,5},{4,6},{5,6},{5,7},{6,7} };
    k = 6;
    gps_log = { 1,2,3,3,6,7 };

    cout << solution(n, m, edge_list, k, gps_log) << endl;

    return 0;
}