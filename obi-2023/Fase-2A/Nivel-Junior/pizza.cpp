#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

void solve_task(){
    int n, g, m; cin >> n >> g >> m;
    ll ans = n - (g*8 + m*6);

    if(ans <= 0)
        cout << abs(ans) << endl;
    else
        cout << 0 << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve_task();
    return 0;
}