// https://cses.fi/problemset/task/3403

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1,0);
    vector<int>b(m+1,0);
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin>>b[i];
    }
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <= m; j++) {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<endl;
    stack<int>res;
    while (n > 0 && m > 0)
    {
        if (dp[n][m] == dp[n - 1][m]) {
            n--;
        } else if (dp[n][m] == dp[n][m - 1]) {
            m--;
        } else {
            res.push(a[n]);
            n--;
            m--;
        }
    }
    // res.pop();
    while (!res.empty())
    {
        cout<<res.top()<<" ";
        res.pop();
    }
    

    return 0;
}