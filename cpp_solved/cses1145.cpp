// https://cses.fi/problemset/task/1145

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int binsec(vector<int>& dp, int val) {
    int l = 0, r = dp.size() - 1;
    int ans = dp.size();
    while (l <= r) {
        int m = (l + r) / 2;
        if (dp[m] >= val) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;

}

int main() {
    fast;
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int>dp;
    for (int i = 0; i < n; i++) {
        int pos = binsec(dp, a[i]);
        if(pos==dp.size())
            dp.pb(a[i]);
        else
            dp[pos]=a[i];
    }
    cout<<dp.size();
    return 0;
}