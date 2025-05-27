// https://cses.fi/problemset/task/2136
/*
This is trie problem
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int hammingDistance(int a,int b) {
    return __builtin_popcount(a ^ b);
}

int main() {
    fast;
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin>>s;
        a[i] = stoi(s, nullptr, 2);
    }
    sort(a.begin(),a.end());
    int res = hammingDistance(a[0],a[1]);
    for (int i = 0; i < n-1; i++) {
        res = min(res,hammingDistance(a[i],a[i+1]));
    }

    cout<<res;

    return 0;
}