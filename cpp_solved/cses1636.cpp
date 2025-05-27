// https://cses.fi/problemset/task/1636

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    int modd = 1e9+7;
    fast;
    ll n,k;
    cin>>n>>k;
    vector<ll> dp(k+1,0);
    vector<ll> coins(n);
    dp[0]=1;
    for (ll i = 0; i < n; i++) {
        cin>>coins[i];
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = coins[i]; j <= k; j++) {
            if(j - coins[i]>=0)
            dp[j] += dp[j - coins[i]];
            dp[j]%=modd;
        }
    }
    cout<<dp[k]%modd;
    return 0;
}