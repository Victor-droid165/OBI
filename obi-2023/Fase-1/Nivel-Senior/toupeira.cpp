#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll S, T, X, Y, N, P, val, cont=0;
ll adj[1001][1001];


int main(void){
    
    bool ans;
    cin >> S >> T;

    for(int i = 0; i < T; i++){
        cin >> X >> Y;
        adj[X][Y] = 1;
        adj[Y][X] = 1;
    }

    cin >> P;

    while(P--){
        cin >> N;
        cin >> val;
        if(N == 1 && val <= S)
            cont++;
        else{
            ll novo_val;
            ans = true;
            for(int i = 1; i < N; i++){
                cin >> novo_val;
                if(!adj[val][novo_val])
                    ans = false;
                val = novo_val;
            }
            if(ans)
                cont++;
        }
        
    }

    cout << cont << endl;
    return 0;
}