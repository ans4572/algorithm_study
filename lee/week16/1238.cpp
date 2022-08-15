#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug

ll mp[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, X;
    cin >> N >> M >> X;
    for(int i = 1 ; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            if (i == j)mp[i][j] = 0;
            else mp[i][j] = 1e12;
        }
    for (int i = 0; i < M; i++) {
        int src, dst, t;
        cin >> src >> dst >> t;
        mp[src][dst] = t;
    }
    for(int m =1 ; m <= N; m++)
        for(int s = 1; s<=N;s++)
            for(int d = 1; d<=N;d++)
                if (mp[s][d] > mp[s][m] + mp[m][d])
                    mp[s][d] = mp[s][m] + mp[m][d];
    ll mx = 0;
    for (int i = 1; i <= N; i++)
        mx = max(mx, mp[i][X] + mp[X][i]);
    cout << mx;
}
