#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool ok(string s){
    for(int i = 0, j = s.size() - 1; i <= j; i++, j--)
        if(s[i] != s[j]) return false;
    
    return true;
}

void solve_task(){
    int n; cin >> n;
    string s; cin >> s;
    set<string> subcadeias;
    int ans = 0;

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n - k; i++){
            string sub;
            for(int j = i; j <= i + k; j++){
                sub += s[j];
            }
            subcadeias.insert(sub);
        }
    }

    for(string sub : subcadeias)
        if(ok(sub)) ans = max(ans, sz(sub));


    cout << ans << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    // cin >> tc;

    while(tc--) solve_task();

    return 0;
}