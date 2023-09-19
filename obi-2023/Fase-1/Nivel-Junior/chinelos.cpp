#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

void solve(){
    int n, p; cin >> n;
    int array[n + 1], ans = 0;
    fill_n(array, n + 1, 0);

    for(int i = 1; i <= n; i++) cin >> array[i];

    cin >> p;

    while(p--){
        int i; cin >> i;
        if(array[i]){
            array[i]--;
            ans++;
        }
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