//https://cses.fi/problemset/task/1622
// Creating Strings

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

string input;
set<string> output;
void dq(int i) {
    if (i == input.size()) {
        output.insert(input);
        return;
    }
    for (int j = i; j < input.size(); j++) {
        swap(input[i], input[j]);
        dq(i + 1);
        swap(input[i], input[j]);
    }
}
int main() {
    fast;
    cin>>input;
    dq(0);
    cout<<output.size()<<endl;
    for (auto it = output.begin(); it != output.end(); it++) {
        cout<<*it<<endl;
    }
    return 0;
}