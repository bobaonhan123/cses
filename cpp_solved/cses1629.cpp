// https://cses.fi/problemset/task/1629

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n;
    cin >> n;
    vector<pair<int, int>>a;
    for (int i = 0; i < n; i++) {
        pair<int, int> p;
        cin >> p.first;
        cin >> p.second;
        a.push_back(p);
    }
    sort(a.begin(), a.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
        return x.second < y.second;
        });

    int cnt = 0;
    int l = 0;
    for (auto& p : a) {
        if (p.first >= l) {
            cnt++;
            l = p.second;
        }
    }
    cout << cnt << "\n";
    return 0;
}