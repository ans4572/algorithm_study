#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define debug
#define mymax 987654321

int ans = INT_MAX, N, tmp;
int dp[16][1<<16];
unordered_map<int, int> mp[16];

int travel(int status, int now)
{
    if (status == (1 << N) - 1)
    {
        if (mp[now][0])
            return mp[now][0];
        else
            return mymax;
    }

    if (dp[now][status] != mymax) return dp[now][status];

    for (auto it : mp[now])
    {
        int next = it.first;
        if (status & (1 << next)) continue;
        int cost = it.second;
        dp[now][status] = min(dp[now][status], travel(status | (1 << next), next ) + cost);
    }
    return dp[now][status];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < 1 << N; j++)
            dp[i][j] = mymax;
    for(int i = 0 ; i < N;i++)
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            if (tmp)
                mp[i][j] = tmp;
        }

    cout << travel(1, 0);
}
