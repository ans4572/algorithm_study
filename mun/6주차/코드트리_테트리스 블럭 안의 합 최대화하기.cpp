// https://www.codetree.ai/frequent-problems/max-sum-of-block-block/explanation

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

int board[201][201];
int N, M;

int blocks[19][4][4] = { { {1, 1, 1, 1},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 0, 0, 0},
                            {1, 0, 0, 0},
                            {1, 0, 0, 0},
                            {1, 0, 0, 0} },

                          { {1, 1, 0, 0},
                            {1, 1, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 0, 0, 0},
                            {1, 0, 0, 0},
                            {1, 1, 0, 0},
                            {0, 0, 0, 0} },

                          { {0, 1, 0, 0},
                            {0, 1, 0, 0},
                            {1, 1, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 1, 1, 0},
                            {1, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 1, 1, 0},
                            {0, 0, 1, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 1, 0, 0},
                            {0, 1, 0, 0},
                            {0, 1, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 1, 0, 0},
                            {1, 0, 0, 0},
                            {1, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {0, 0, 1, 0},
                            {1, 1, 1, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 0, 0, 0},
                            {1, 1, 1, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 0, 0, 0},
                            {1, 1, 0, 0},
                            {0, 1, 0, 0},
                            {0, 0, 0, 0} },

                          { {0, 1, 1, 0},
                            {1, 1, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 1, 0, 0},
                            {0, 1, 1, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {0, 1, 0, 0},
                            {1, 1, 0, 0},
                            {1, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 0, 0, 0},
                            {1, 1, 0, 0},
                            {1, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 1, 1, 0},
                            {0, 1, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {0, 1, 0, 0},
                            {1, 1, 0, 0},
                            {0, 1, 0, 0},
                            {0, 0, 0, 0} },

                          { {0, 1, 0, 0},
                            {1, 1, 1, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} } };

// 전부 탐색 진행
int GetMaxSum(int x, int y) {
    int max_sum = 0;
    for (int shape = 0; shape < 19; shape++) {
        int sum = 0;
        for (int dx = 0; dx < 4; dx++) {
            for (int dy = 0; dy < 4; dy++) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < N && ny >= 0 && ny < M && blocks[shape][dx][dy])
                    sum += board[nx][ny];
            }
        }

        max_sum = max(max_sum, sum);
    }

    return max_sum;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;

    // 격자의 각 위치에 대하여 탐색하여줍니다.
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            ans = max(ans, GetMaxSum(i, j));

    cout << ans;

    return 0;
}