#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<ll, ll> pll;

const int N = 1e4 + 1;
const ll INF = LLONG_MAX;
vector<vector<array<ll, 3>>> adj(N);
vector<array<ll, 201>> dist(N);

void dijkstra(int source, int budget){
    for(int i = 0; i < N; i++)
        dist[i].fill(INF);

    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;

    dist[source][budget] = 0LL; // Consigo chegar no source com budget e com tempo 0
    pq.push({0, source, budget});

    while(!pq.empty()){
        auto [d, u, k] = pq.top();
        pq.pop();

        if(dist[u][k] < d) continue;  // Se o tempo de ter chegado aqui for menor que d, pode continuar pois o resto é d + w

        for(auto [v, w1, w2] : adj[u]){
            if(k - w2 >= 0 && dist[v][k - w2] > d + w1){ // Se tá no orçamento, e consigo chegar em v com menos tempo
                dist[v][k - w2] = d + w1;
                pq.push({dist[v][k - w2], v, k - w2});
            }
        }
    }
}

void solve_task(){
    int v, n, m;
    cin >> v >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v, w1, w2;
        cin >> u >> v >> w1 >> w2;

        adj[u].push_back({v, w1, w2});
        adj[v].push_back({u, w1, w2});
    }

    int x, y;
    cin >> x >> y;

    dijkstra(x, v);

    ll ans =*min_element(all(dist[y]));
    if(ans == INF) 
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    // cin >> tc;

    while(tc--) solve_task();
    return 0;
}