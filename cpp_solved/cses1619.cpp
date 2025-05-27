// https://cses.fi/problemset/task/1619

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n;
    cin>>n;
    vector<pair<int,int>>a;
    for (int i = 0; i < n; i++) {
        pair<int,int> p;
        cin>>p.first;
        p.second=1;
        a.push_back(p);
        cin>>p.first;
        p.second=-1;
        a.push_back(p);
    }
    sort(a.begin(), a.end());
    int res=0;
    int mres=0;
    for (int i = 0; i < a.size(); i++) {
        res+=a[i].second;
        mres=max(res,mres);
    }
    cout<<mres;
    return 0;
}