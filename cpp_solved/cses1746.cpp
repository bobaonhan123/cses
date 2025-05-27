// https://cses.fi/problemset/task/1746
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const ll MOD = 1e9 +7;

int main() {
    fast;
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n);
    vector<vector<ll>>dp(n,vector<ll>(m+2,0));

    for (ll i = 0; i < n; i++) {
        cin>>a[i];
    }
    if(a[0]==0) {
        for (ll i = 1; i < m+1; i++) {
            dp[0][i]=1;
        }
    }
    else {
        dp[0][a[0]]=1;
    }
    for (ll i = 1; i < n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (a[i] == 0 or a[i] == j) {
                dp[i][j] = (
                dp[i - 1][j - 1] +
                dp[i - 1][j] +
                dp[i - 1][j + 1]
            ) % MOD;
            }
        }
    }
    ll res=0;
    for (ll i = 0; i <= m; i++) {
        res+=dp[n-1][i];
        res%=MOD;
    }
    cout<<res;
    return 0;
}