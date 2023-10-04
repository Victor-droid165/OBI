#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve_task(){
    int c, d, t; cin >> c >> d >> t;

    cout << fixed << setprecision(1) << max((double)d/c - t, (double)0) << endl;  

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    // cin >> tc;

    while(tc--) solve_task();

    return 0;
}