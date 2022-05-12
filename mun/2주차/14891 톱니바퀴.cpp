// https://www.acmicpc.net/problem/14891

#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <deque>

using namespace std;

// 톱니바퀴 4개 정보
// 0 : N극, 1 : S극
deque<int> dq[5];
bool visited[5]; // 톱니바퀴 회전 여부
vector<pair<int, int>> vec_r; // k개의 회전 방법 (톱니바퀴 번호, 방향)
int k;

void RotateDq(int num, int direction)
{
    // 시계방향
    if (direction == 1)
    {
        int tmp = dq[num].back();
        dq[num].pop_back();
        dq[num].push_front(tmp);
    }
    // 반시계방향
    else if (direction == -1)
    {
        int tmp = dq[num].front();
        dq[num].pop_front();
        dq[num].push_back(tmp);
    }
}

// 재귀 활용
void Solution(int num, int direction)
{
    visited[num] = true;

    int prev_num = num - 1, next_num = num + 1;

    // 이전 톱니바퀴
    if (prev_num > 0 && !visited[prev_num])
    {
        // 서로 다른 극이면
        if (dq[prev_num][2] != dq[num][6])
        {
            Solution(prev_num, direction * -1);
        }
    }

    // 다음 톱니바퀴
    if (next_num < 5 && !visited[next_num])
    {
        // 서로 다른 극이면
        if (dq[next_num][6] != dq[num][2])
        {
            Solution(next_num, direction * -1);
        }
    }

    // 현재 톱니바퀴 회전
    RotateDq(num, direction);
}

int main()
{
    // input
    for (int i = 0; i < 4; i++)
    {
        string s;
        cin >> s;
        // 방향은 12시부터 시계방향 순서
        for (int j = 0; j < 8; j++)
        {
            int tmp = s[j] - '0';
            dq[i + 1].push_back(tmp);
        }
    }

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        // 시계방향 : 1, 반시계방향 : -1
        int dq_num, direction;
        cin >> dq_num >> direction;
        vec_r.push_back(make_pair(dq_num, direction));
    }

    for (int i = 0; i < vec_r.size(); i++)
    {
        Solution(vec_r[i].first, vec_r[i].second);
        memset(visited, false, sizeof(visited));
    }

    // 점수 계산
    int ans = 0;
    for (int i = 1; i < 5; i++)
    {
        if (dq[i][0] == 1)
            ans += pow(2, i - 1);
    }

    cout << ans << endl;

    return 0;
}