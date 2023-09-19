#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

void solve_task(){
    int n, cont = 1; cin >> n;
    string s; cin >> s;
    char c = s[0];
    for(int i = 1; i < n; i++){
        while(i < n && s[i] == c){
            cont++;
            i++;
        }
        if(i < n) {
            cout << cont << " " << c << " ";
            c = s[i];
            cont = 1;
        }
    }
    cout << cont << " " << c << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve_task();
    return 0;
}