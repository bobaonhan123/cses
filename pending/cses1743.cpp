#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    string s;
    cin>>s;
    map<char,int> mp;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }
    string res=""
    for (int i = 0; i < s.size(); i++) {
        auto it = mp.begin();
        cout << it->first;
        it->second--;
        if (it->second == 0) {
            mp.erase(it);
        }
    }
    return 0;
}