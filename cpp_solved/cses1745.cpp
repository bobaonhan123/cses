// https://cses.fi/problemset/task/1745

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n;
    cin>>n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    set<int>res;
    res.insert(0); 
    for (int i = 0; i < n; i++) {
        set<int>tmpset;
        for (auto it = res.begin(); it != res.end(); it++) {
            tmpset.insert(*it+a[i]);
        }
        res.insert(tmpset.begin(), tmpset.end());
    }
    res.erase(0);
    cout<<res.size()<<endl;
    for (auto it = res.begin(); it != res.end(); it++) {
        cout<<*it<<" ";
    }
    return 0;
}