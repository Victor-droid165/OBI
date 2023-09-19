#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void){
    ll V, conta, qtd = 0;
    priority_queue<ll> contas;
    cin >> V;

    for(int i = 0; i < 3; i++){
        cin >> conta;
        contas.push(-conta);
    }
    while(!contas.empty() && V >= -contas.top()){
        V -= -contas.top();
        contas.pop();
        qtd += 1;
    }

    cout << qtd << endl;
    return 0;
}