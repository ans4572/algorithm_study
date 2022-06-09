#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug
vector<int> lan(10001);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int K, N;
    cin >> K >> N;
    
    for(int i = 1 ; i<=K;i++)
        cin >> lan[i];
    long long r = *max_element(lan.begin(), lan.end());
    long long l = 1;

    long long res = 0;
    while(r >= l)
    {
        long long mid = (r + l) / 2;
        long long cnt = 0;
        for(auto it : lan)
            cnt += it / mid;
        if(cnt >= N)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << res << "\n";
}