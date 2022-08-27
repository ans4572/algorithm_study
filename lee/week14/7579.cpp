#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug

int N, M;

int c[100];
int m[100];
int dp[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> m[i];
    for (int i = 0; i < N; i++)
        cin >> c[i];
    for(int i = 0 ; i < N; i++)
        for (int j = 10000; j >= c[i]; j--) {
            dp[j] = max(dp[j], dp[j - c[i]] + m[i]);
        }
    int ans;
    for (int j = 10000; j >= 0; j--)
        if (dp[j] >= M)
            ans = j;
    cout << ans << "\n";
}
