// https://cses.fi/problemset/task/1091

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    fast;
    int n, m;
    cin >> n >> m;

    multiset<int> tickets;
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        tickets.insert(h);
    }

    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;

        auto it = tickets.upper_bound(t);
        if (it == tickets.begin()) {
            cout << -1 << "\n";
        }
        else {
            --it;
            cout << *it << "\n";
            tickets.erase(it);
        }
    }

    return 0;
}
