// https://cses.fi/problemset/task/1623

/*
Bitmask
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)


int main() {
    fast;

    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll res = 1e10+7;
    for (int m = 0; m < (1 << n); m++) {
        ll sum1 = 0, sum2 = 0;

        for (int i = 0; i < n; i++) {
            if (m & (1 << i)) sum1 += a[i];
            else sum2 += a[i];
        }

        res = min(res, abs(sum1 - sum2));
    }

    cout << res;

    return 0;
}