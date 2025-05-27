// https://cses.fi/problemset/task/1072


/*

Công thức tổ hợp chập 2 n*(n-1)/2
Trường hợp 2 con mã tấn công nhau:  4(k−1)(k−2)
Vì 2 con mã sẽ đánh nhau nếu nằm trên chữ L, mà các cụm ô tồn tại chữ L thì sẽ là 2x3 hoặc 3x2
Số ô 2x3 là (k−1)(k−2), tương tự với 3x2
Mỗi ô sẽ có 2 trường hợp mã đấm nhau, là 2(k−1)(k−2), mà có ô 2x3 lẫn 3x2 nên là 2*2(k−1)(k−2)
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++) {
        ll po = i*i;
        cout<<(ll) (po*(po-1)/2) - 2*2*(i-1)*(i-2)<<endl;
    }
    return 0;
}