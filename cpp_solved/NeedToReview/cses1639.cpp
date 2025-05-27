// https://cses.fi/problemset/task/1639
//edit distance
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }
    s1 = " " + s1;
    s2 = " " + s2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] = 1 + min({
                    dp[i - 1][j],     // delete
                    dp[i][j - 1],     // add
                    dp[i - 1][j - 1]  // replace
                    });
            }
        }
    }
    cout << dp[n][m];
    return 0;
}