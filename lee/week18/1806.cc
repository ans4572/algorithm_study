#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug

int V[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, S;
    cin >> N >> S;
    for(int i = 0 ; i < N; i++)
        cin >> V[i];
    ll sum = 0;
    int l = 0, r = 0;
    int mn = INT_MAX;
    while(r <= N){
        if(sum < S){
            sum += V[r];
            r++;
        }
        else {
            mn = min(mn, r - l);
            sum -= V[l];
            l++;
        }
    }
    if(mn == INT_MAX) mn = 0;
    cout << mn << "\n";
}
