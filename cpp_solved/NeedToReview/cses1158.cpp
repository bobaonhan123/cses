// https://cses.fi/problemset/task/1158

/*
Bài này là cái túi
if(a[i].first>x) {
    dp[i][j] = dp[i-1][j]
}
Vì không lấy món i thì kết quả sẽ giống với kết quả trước là i-1
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>>a(n);
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= dp[0].size(); j++) {
            if (a[i - 1].first > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1].first] + a[i - 1].second);
            }
        }
    }
    cout << dp[n][x];
    return 0;
}