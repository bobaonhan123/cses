// https://cses.fi/problemset/task/1073

/*
Binary search
When in a[i], find the smallest cube of tower that greater than a[i]
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n;
    cin>>n;
    multiset<int>s;
    int res=0;
    for (int i = 0; i < n; i++) {
        int p;
        cin>>p;
        auto it = s.upper_bound(p);
        if (it != s.end()) {
            s.erase(it);
        }
        s.insert(p);
    }
    cout<<s.size();
    return 0;
}