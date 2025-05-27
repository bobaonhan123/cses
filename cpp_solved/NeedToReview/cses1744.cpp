// https://cses.fi/problemset/task/1744

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MAXINT = 1e9+7;

int main() {
    fast;
    int a,b;
    cin>>a>>b;
    vector<vector<int>>dp(a+1, vector<int>(b+1, MAXINT));
    for (int i = 1; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if(i==j) {
                dp[i][j]=0;
            }
            for(int k=1;k<=i-1;k++) {
                dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
            }
            for(int k=1;k<=j-1;k++) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
            }
        }
    }
    cout<<dp[a][b];
    return 0;
}