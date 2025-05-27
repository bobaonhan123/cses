#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    string s;
    cin>>s;
    vector<int> dp(s.size(), 1);
    int res=1;
    for (int i = 1; i < s.size(); i++) {
        if(s[i]==s[i-1]) {
            dp[i]=dp[i-1]+1;
        }
        res=max(res,dp[i]);
    }
    cout<<res;
    return 0;
}