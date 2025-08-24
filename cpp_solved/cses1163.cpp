// https://cses.fi/problemset/task/1163

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n, x;
    cin >> x >> n;
    set<int>se;
    map<int, int>ma;
    se.insert(0);
    se.insert(x);
    ma[x] = 1;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        auto it = se.upper_bound(p);
        int r = *it;
        int l = *prev(it);
        ma[r - l]--;
        if (ma[r - l] == 0) ma.erase(r - l);
        se.insert(p);
        ma[p - l]++;
        ma[r - p]++;
        cout << ma.rbegin()->first << " ";
    }
    return 0;
}