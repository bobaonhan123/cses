// https://cses.fi/problemset/task/1193
/*
Bài này là bfs ma trận
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n, m;
    cin >> n >> m;
    vector<string>matrix(n);
    vector<string>mask(n, string(m, '?'));
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }
    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 'A') {
                start = { i, j };
                break;
            }
        }
    }
    bool found = false;
    queue<pair<int, int>>q;
    q.push(start);
    mask[start.first][start.second] = 'S';
    unordered_map<char, pair<int, int>> directions = {
        {'L', {0, -1}},
        {'R', {0, 1}},
        {'U', {-1, 0}},
        {'D', {1, 0}}
    };
    vector<char> lrud = { 'L', 'R', 'U', 'D' };
    unordered_map<char, char> counter = {
        {'L', 'R'},
        {'R', 'L'},
        {'U', 'D'},
        {'D', 'U'}
    };
    pair<int, int>relo;
    while (!q.empty() && !found) {
        auto [x, y] = q.front();
        q.pop();
        for (char dir : lrud) {
            int nx = x + directions[dir].first;
            int ny = y + directions[dir].second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] != '#' && mask[nx][ny] == '?') {
                mask[nx][ny] = dir;
                q.push({ nx, ny });
                if (matrix[nx][ny] == 'B') {
                    relo = { nx,ny };
                    found = true;
                    break;
                }
            }

        }
        if (found) break;
    }
    if (!found) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    stack<char>tv;
    // char tmp = 'B';
    // while (tmp!='?')
    // {
    //     tv.push(mask[relo.first][relo.second]);
    //     int d1 = directions[mask[relo.first][relo.second]].first;
    //     int d2 = directions[mask[relo.first][relo.second]].second;
    //     relo.first -= d1;
    //     relo.second -= d2;
    //     tmp = mask[relo.first][relo.second];
    // }
    // cout<<tv.size()<<endl;
    // while (!tv.empty())
    // {
    //     cout<<tv.top();
    //     tv.pop();
    // }
    while (mask[relo.first][relo.second] != 'S') {
        char d = mask[relo.first][relo.second];
        tv.push(d);
        relo.first -= directions[d].first;
        relo.second -= directions[d].second;
    }
    cout<< tv.size() << "\n";
    while (!tv.empty()) {
        cout << tv.top();
        tv.pop();
    }
    return 0;
}