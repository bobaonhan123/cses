// https://cses.fi/problemset/task/1634
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int IMAX = 1e9 + 7;

int main() {
    fast;
    int n, x;

    cin >> n >> x;
    vector<int>a(n);
    vector<int>dp(x + 1, IMAX);
    dp[0] = 0;
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= x; i++) {
        int ma = IMAX;
        for (int j = 0;j < n;j++) {
            if (i - a[j] >= 0) {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }
    if (dp[x] == IMAX) cout << -1;
    else
        cout << dp[x];
    return 0;
}