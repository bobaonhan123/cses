// https://cses.fi/problemset/task/1652
/*
integral image
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n, q;
    cin >> n >> q;
    vector<string>matrix(n);
    vector<vector<int>>integral(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '*') {
                integral[i][j] = 1;
            }
            if (i > 0) {
                integral[i][j] += integral[i - 1][j];
            }
            if (j > 0) {
                integral[i][j] += integral[i][j - 1];
            }
            if (i > 0 && j > 0) {
                integral[i][j] -= integral[i - 1][j - 1];
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << integral[i][j];
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;

        int ans = integral[x2][y2];
        if (x1 > 0) ans -= integral[x1 - 1][y2];
        if (y1 > 0) ans -= integral[x2][y1 - 1];
        if (x1 > 0 && y1 > 0) ans += integral[x1 - 1][y1 - 1];
        cout << ans << '\n';
    }
    return 0;
}