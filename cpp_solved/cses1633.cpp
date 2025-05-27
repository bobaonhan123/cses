// https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int MOD = 1e9 + 7;

int main() {
    fast
        int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}