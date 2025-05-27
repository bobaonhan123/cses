// https://cses.fi/problemset/task/1084

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int>a(n);
    vector<int>b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0, res = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= k) {
            res++;
            i++;
            j++;
        }
        else if (a[i] < b[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    cout << res << endl;
    return 0;
}