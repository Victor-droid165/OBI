#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;

/*
Não faz sentido isso não estar certo!

void solve_impar(int n){
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++)
            cout << i*n + j << " ";
        cout << i*n + n << "\n";
    }
}

void solve_par(int n){
    if(n == 2) cout << "-1\n";
    else{
        ll m = n - 4;
        ll skip = 2LL + m/2LL;
        ll i;
        for(i = 0; (int)i < n - 1; i++){
            for(ll j = 1; (int)j < n; j++)
                cout << (i*n + i*skip) + j << " ";
            cout << (i*n + (i+1)*skip) + n << "\n";
        }
        ll ant = (i - (m/2LL + 1LL))*n + (i - (m/2LL + 1LL))*skip;
        ll j;
        for(j = 1; (int)j < n; j++)
            cout << (i*n + i*skip) + j + ant << " ";
        cout << (i*n + (i+1)*skip) + n + ant << "\n";
    }
}

void check(){
    for(int n = 1; n < 110; n++){
        if(n == 2) continue;
        if(n % 2)
            solve_impar(n);
        else
            solve_par(n);
        vector<ll> sumLinhas(n), sumColunas(n);
        unordered_set<ll> s;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sumLinhas[i] += v[i][j];
                sumColunas[i] += v[j][i];
                s.insert(v[i][j]);
            }
        }
        assert(s.size() == n*n); // Checa se não há números repetidos no quadrado;
        for(int i = 0; i < n; i++){
            assert(sumLinhas[i] % n == 0); // A média dos nums da linha i é um número inteiro
            assert(sumColunas[i] % n == 0); // A média dos nums da coluna i é um número inteiro
            vector<ll>::iterator it = lower_bound(v[i].begin(), v[i].begin() + n, sumLinhas[i]/n);
            assert(*it == sumLinhas[i]/n);  // A média dos nums da linha i está presente na linha i;
            
            ll media = sumColunas[i]/n;
            bool found = false;
            for(int j = 0; j < n && !found; j++){
                if(v[j][i] == media) found = true;
            }
            assert(found);  // A média dos nums da coluna i está presente na coluna i;
        }
    }
}*/

void solve_task(){
    int n; cin >> n;
    if(n == 2){
        cout << "-1\n";
        return;
    }

    vector<int> sumLinhas(n), sumColunas(n);
    int value = 1, firstColValue = 0, lastColValue = 0;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if(j == 0)
                firstColValue = value;
            sumLinhas[i] += value;
            sumColunas[j] += value;
            cout << value++ << " ";
        }
        value = lastColValue = (value - 1)*n - sumLinhas[i];
        sumColunas[n - 1] += value;
        cout << value++ << "\n";
    }
    value = firstColValue*n - sumColunas[0]; 
    for(int j = 0; j < n - 1; j++)
        cout << value++ << " ";
    cout << (lastColValue)*n - sumColunas[n - 1] << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    while(tc--) solve_task();
    return 0;
}
