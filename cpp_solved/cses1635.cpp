//https://cses.fi/problemset/task/1635

#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int IMAX = 1e9 + 7;

int main() {
    fast;
    int n, x;

    cin >> n >> x;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int>dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= a[j]) {
                dp[i] += dp[i - a[j]];
                if (dp[i] >= IMAX) dp[i] -= IMAX;
            }
        }
    }
    cout << dp[x];
    return 0;
}