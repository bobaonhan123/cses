// https://cses.fi/problemset/task/1141
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i = 0, j = 0;
    int res = 0;
    map<int, int>mp;
    while (j < n) {
        int sz = mp.size();
        mp[a[j]]++;
        while (mp[a[j]] > 1) {
            mp[a[i]]--;
            if (mp[a[i]] == 0) {
                mp.erase(a[i]);
            }
            i++;
        }
        res = max(res, j - i + 1);
        j++;
    }
    cout << res;

    return 0;
}