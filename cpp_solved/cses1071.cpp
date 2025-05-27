// https://cses.fi/problemset/task/1071

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void solve() {
    ll x, y;
    cin >> x >> y;
    swap(x,y);
    ll n = max(x, y);
    if (n % 2 == 0) {

        if (y == n) {
            cout << n * n - x + 1 << '\n';
        }
        else {
            cout << (n - 1) * (n - 1) + y << '\n';
        }
    }
    else {
        if (x == n) {
            cout << n * n - y + 1 << '\n';
        }
        else {
            cout << (n - 1) * (n - 1) + x << '\n';
        }
    }
}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}