#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

void solve(){
    int n, r, p, ans = 0; cin >> n >> r >> p;
    ll sum = n;
    while(sum < p){
        n *= r;
        sum += n;
        ans++;
    }
    cout << ans << endl;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    // cin >> tc;

    while(tc--) solve();
    return 0;
}