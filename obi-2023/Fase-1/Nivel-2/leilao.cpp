#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

void solve(){
    int n; cin >> n;
    pair<string, int> ans = {"", -1};
    do{
        string nome; int v;
        cin >> nome >> v;
        
        if(v > ans.second){
            ans.first = nome;
            ans.second = v;
        }
    }while(--n);
    cout << ans.first << endl << ans.second << endl;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    // cin >> tc;

    while(tc--) solve();
    return 0;
}