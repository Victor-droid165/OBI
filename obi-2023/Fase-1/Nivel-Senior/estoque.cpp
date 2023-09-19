#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll M, N, P, val;

int main(void){
    
    ll ans = 0;
    cin >> M >> N;

    ll matriz[M][N];

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> val;
            matriz[i][j] = val;
        }
    }

    cin >> P;

    while(P--){
        ll i, j;
        cin >> i >> j;
        i--;j--;
        if(matriz[i][j]){
            ans += 1;
            matriz[i][j]--;
        }
    }

    cout << ans << endl;
    return 0;
}