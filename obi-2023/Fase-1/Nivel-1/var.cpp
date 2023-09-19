#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

void solve(){
    int x, y; cin >> x >> y;

    if(abs(x) <= 8 && y >= 0 && y <= 8)
        cout << 'S' << endl;
    else
        cout << 'N' << endl;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    // cin >> tc;

    while(tc--) solve();
    return 0;
}