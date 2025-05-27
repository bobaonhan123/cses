#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int m = 0;
vector<pair<int, int>> res;

void dq(int n, int fr, int g, int to) {
    if (n == 1) {
        res.push_back({fr, to});
        m++;
        return;
    }
    dq(n - 1, fr, to, g);
    res.push_back({fr, to});
    m++;
    dq(n - 1, g, fr, to);
}

int main() {
    fast;
    int n;
    cin >> n;

    dq(n, 1, 2, 3);

    cout << m << "\n";
    for (auto &p : res) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
