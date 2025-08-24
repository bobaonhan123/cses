// https://cses.fi/problemset/task/1645
/*
when an element of the top of the stack is removed, it cannot be a candidate

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
    vector<int>a(n+1);
    for (int i = 1; i <=n; i++) {
        cin>>a[i];
    }
    stack<pair<int,int>>st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && st.top().first>=a[i])
        {
            st.pop();
        }
        
        if(st.empty()) {
            cout<<0<<" ";
        }
        else {
            cout<<st.top().second<<" ";
        }

        st.push({a[i],i});
    }
    return 0;
}