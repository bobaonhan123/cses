// https://cses.fi/problemset/task/1621

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    fast
    int n;
    set<int>s;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int p;
        cin>>p;
        s.insert(p);
    }
    cout<<s.size();
    return 0;
}