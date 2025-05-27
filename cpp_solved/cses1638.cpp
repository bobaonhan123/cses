// https://cses.fi/problemset/task/1638

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int MOD = 1e9 + 7;
int main() {
    fast;
    int n;
    cin >> n;
    vector<string> v(n);
    vector<vector<int >>dp(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        dp[i].resize(n, 0);
    }

    if(v[0][0]=='*') {
        cout<<0;
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == '.') {
                if (i > 0) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                }
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
                }
            }
            dp[i][j]%=MOD;
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout<<dp[n-1][n-1];

    return 0;
}