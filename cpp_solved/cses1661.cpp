// https://cses.fi/problemset/task/1661
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n;
    ll x;
    cin >> n >> x;
    ll prefix_sum = 0;
    ll res = 0;
    map<ll, int> cnt;
    cnt[0] = 1;

    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        prefix_sum += a;
        res += cnt[prefix_sum - x];
        cnt[prefix_sum]++;
    }

    cout << res << endl;

    return 0;
}