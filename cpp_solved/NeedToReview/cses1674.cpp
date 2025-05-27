// https://cses.fi/problemset/task/1674

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void dq(vector<int> &res, vector<vector<int>>& tree, int i) {
    if (tree[i].size() == 0) {
        res[i] = 0; 
        return;
    }
    
    int total_subordinates = 0;
    for (int child : tree[i]) {
        dq(res, tree, child);
        total_subordinates += res[child] + 1;
    }
    res[i] = total_subordinates;
}

int main() {
    fast;
    int n;
    cin>>n;
    vector<vector<int>>tree(n+1);
    for (int i = 2; i < n+1; i++) {
        int p;
        cin>>p;
        tree[p].pb(i);
    }
    vector<int>res(n+1,0);
    dq(res,tree,1);
    for (int i = 1; i <= n; i++) {
        cout<<res[i]<<" ";
    }
    return 0;
}