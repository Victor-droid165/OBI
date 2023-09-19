#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll A, B, val, tam;
vector<ll> a, b;

char solve(){
    ll i = 0, j = 0;
    while(i < B){
        while(j < A && a[j] != b[i]){
            if(++j == A)
                return 'N';
        }
        i++;
    }
    return 'S';
}

int main(void){
    
    char ans;
    cin >> A >> B;

    for(int i = 0; i < A; i++){
        cin >> val;
        a.push_back(val);
    }

    for(int i = 0; i < B; i++){
        cin >> val;
        b.push_back(val);
    }

    ans = solve();

    cout << ans << endl;
    return 0;
}