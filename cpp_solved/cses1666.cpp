// https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int find(int x, vector<int>& dsu) {
    if (dsu[x] == x) return x;
    return dsu[x] = find(dsu[x], dsu);
};

int main() {
    fast;
    int n, k;
    cin >> n >> k;
    vector<int> dsu(n + 1, 0);
    for (int i = 1; i < n + 1; i++) {
        dsu[i] = i;
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        int ra = find(a, dsu);
        int rb = find(b, dsu);
        if (ra != rb)
            dsu[rb] = ra;
    }
    int r1 = find(1, dsu);
    vector<pair<int, int>>res;
    for (int i = 2; i <= n; i++) {
        int ri = find(i, dsu);
        if(ri!=r1) {
            res.push_back({ri,r1});
            dsu[ri]=r1;
        }
    }
    cout<<res.size()<<endl;
    for (int i = 0; i < res.size(); i++) {
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
    return 0;
}