// https://cses.fi/problemset/task/1625

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

pair<int, int> di[256];

const char lrdu[4] = { 'L', 'R', 'D', 'U' };

string input;
string s;
int res = 0;
int x = 0, y = 0;
bool vi[7][7] = { false };
bool isValid(int x, int y) {
    return x >= 0 && x <= 6 && y >= 0 && y <= 6 && !vi[x][y];
}

bool isTrapped(int x, int y) {
    bool up = (x > 0 && !vi[x - 1][y]);
    bool down = (x < 6 && !vi[x + 1][y]);
    bool left = (y > 0 && !vi[x][y - 1]);
    bool right = (y < 6 && !vi[x][y + 1]);
    if ((up && down && !left && !right) || (!up && !down && left && right)) {
        return true;
    }
    return false;
}

void dq(int step) {
    if (step == 48) {
        if (x == 6 && y == 0) res++;
        return;
    }
    if (step >= 48) return;
    if (isTrapped(x, y)) return;
    if (!isValid(x, y)) {
        return;
    }
    if (x == 6 && y == 0 && step != 48) return;
    vi[x][y] = true;


    if (input[step] == '?') {
        int cnt = 0, idx = -1;
        for (int i = 0; i < 4; i++) {
            int dx = di[lrdu[i]].first;
            int dy = di[lrdu[i]].second;
            int nx = x + dx, ny = y + dy;
            if (isValid(nx, ny) && !isTrapped(nx, ny)) {
                cnt++;
                idx = i; 
            }
        }
        // if there is only one available way, force to go
        if (cnt == 1) {
            vi[x][y] = true;
            int dx = di[lrdu[idx]].first;
            int dy = di[lrdu[idx]].second;
            x += dx; y += dy;
            dq(step + 1);
            x -= dx; y -= dy;
            vi[x][y] = false;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int dx = di[lrdu[i]].first;
            int dy = di[lrdu[i]].second;
            int nx = x + dx, ny = y + dy;

            if (isValid(nx, ny)) {
                int px = x, py = y;
                x = nx; y = ny;
                dq(step + 1);
                x = px; y = py;
            }
        }
    }
    else {
        int dx = di[input[step]].first;
        int dy = di[input[step]].second;
        int nx = x + dx, ny = y + dy;

        if (isValid(nx, ny)) {
            int px = x, py = y;
            x = nx; y = ny;
            dq(step + 1);
            x = px; y = py;
        }
    }
    vi[x][y] = false;

}

int main() {

    di['L'] = { 0, -1 };
    di['R'] = { 0, 1 };
    di['D'] = { 1, 0 };
    di['U'] = { -1, 0 };
    fast;
    cin >> input;
    dq(0);
    cout << res;
    return 0;
}