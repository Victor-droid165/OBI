#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 3e5 + 1;
const int INF = 1e8;
vector<vector<int>> adj(N);
int qtd, n, k;

pii dfs(int s, int r, int p = 0){
    int dist = INF;
    int des = 0;
    for(auto u : adj[s]){
        if(u != p){
            pii ans = dfs(u, r, s);
            dist = min(dist, ans.first + 1);
            des = max(des, ans.second + 1);
        }
    }
    if(des + dist <= r) des = -1;
    if(des == r){
        qtd++;
        dist = 0;
        des = -1;
    }

    return {dist, des};
}

bool ok(int r){
    qtd = 0;
    pii ans = dfs(1, r);
    if(ans.second >= 0) qtd++;
    return qtd <= k;
}

void solve_task(){
    cin >> n >> k;

    adj.resize(n + 1);

    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int l = 0, r = n/2;

    while(r - l > 1){
        int mid = (l + r) >> 1;

        if(ok(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    // cin >> tc;

    while(tc--) solve_task();

    return 0;
}