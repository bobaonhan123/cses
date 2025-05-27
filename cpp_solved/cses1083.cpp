#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n;
    cin >> n;
    vector<int> a(n - 1);
    ll s = 0;

    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
        s += a[i];
    }

    ll total_sum = (ll)n * (n + 1) / 2;
    cout << total_sum - s << endl;
    return 0;
}