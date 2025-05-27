// https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void dfs(vector<string>& grid, vector<vector<bool>>& visited, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '#' || visited[i][j]) {
        return;
    }
    visited[i][j] = true;
    dfs(grid, visited, i + 1, j);
    dfs(grid, visited, i - 1, j);
    dfs(grid, visited, i, j + 1);
    dfs(grid, visited, i, j - 1);
}


int main() {
    fast;
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<bool>>visited(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        visited[i].resize(m, 0);
    }
    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                if (!visited[i][j]) {
                    rooms++;
                    dfs(grid, visited, i, j);
                }
            }
        }
    }

    cout << rooms << endl;
    return 0;
}