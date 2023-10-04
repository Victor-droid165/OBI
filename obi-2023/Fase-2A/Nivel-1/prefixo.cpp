#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

deque<ll> vals;
size_t nP1, nP2;
string P1, P2;

void solve_task(){
    cin >> nP1 >> P1 >> nP2 >> P2;
    size_t n = min(nP1, nP2);
    size_t ans = 0;

    for(size_t i = 0; i < n; i++){
        if(P1[i] == P2[i])
            ans++;
        else
            break;
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve_task();
    return 0;
}