#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

void solve(){
    int p, d, b; cin >> p >> d >> b;

    int score = p + 2*d + 3*b;
    char ans;

    if(score >= 150) ans = 'B';
    else if(score >= 120) ans = 'D';
    else if(score >= 100) ans = 'P';
    else ans = 'N';

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