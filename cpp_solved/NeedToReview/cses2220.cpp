#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()

ll calc(vector<vector<vector<vector<ll>>>> &memory, vector<vector<vector<vector<ll>>>> &visited, ll pos,ll parent, bool tight, string &s, bool started = false) {
    if(visited[pos][parent][tight][started]) return memory[pos][parent][tight][started];
    visited[pos][parent][tight][started] = 1;
    if(pos == s.size()) return memory[pos][parent][tight][started] = 1;
    
    ll limit;
    if(tight) {
        limit = s[pos]-'0';
    }
    else {
        limit = 9;
    }
    ll res = 0;
    for(ll i=0;i<=limit;i++) {
        ll newTight = tight && (i==limit);
        if(started && i==parent) continue;
        bool new_started = started || (i>0);
        if (!new_started) {
            res += calc(memory,visited,pos+1,parent,newTight,s,new_started);
        }
        else
            res += calc(memory,visited,pos+1,i,newTight,s,new_started);
    }
    return memory[pos][parent][tight][started] = res;

}

void solve() {
    ll a,b;
    cin>>a>>b;
    a--;
    string s1 = to_string(a);
    string s2 = to_string(b);
    vector<vector<vector<vector<ll>>>> visited1(20,vector<vector<vector<ll>>>(20,vector<vector<ll>>(2,vector<ll>(2,0))));  //pos, parent tight;
    vector<vector<vector<vector<ll>>>> memory1(20,vector<vector<vector<ll>>>(20,vector<vector<ll>>(2,vector<ll>(2,0))));  //pos, parent tight;
    vector<vector<vector<vector<ll>>>> visited2(20,vector<vector<vector<ll>>>(20,vector<vector<ll>>(2,vector<ll>(2,0))));  //pos, parent tight;
    vector<vector<vector<vector<ll>>>> memory2(20,vector<vector<vector<ll>>>(20,vector<vector<ll>>(2,vector<ll>(2,0))));  //pos, parent tight;

    cout<<calc(memory2,visited2,0,10,true,s2, false) - calc(memory1,visited1,0,10,true,s1, false)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}