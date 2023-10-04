#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Edge{
    int u, v, w;

    bool operator<(const Edge& other){
        return w < other.w;
    }
};


const int N = 1e5 + 1;
const int INF = 1e9;
const int lg = 32 - __builtin_clz(N);
vector<Edge> edges;
vector<vector<pii>> mst_adj(N);
vector<vector<int>> anc(N, vector<int>(lg)), mini(N, vector<int>(lg));
vector<int> dep(N);

struct DSU{
    vector<int> p, r;

    DSU(int V){
        p.resize(V); 
        r.resize(V);
        for(int i = 1; i < V; i++){
            p[i] = i;
            r[i] = 0;
        }
    }

    int find(int v){
        if(p[v] == v)
            return v;

        return p[v] = find(p[v]);
    }

    void union_find(int u, int v){
        int set_u = find(u);
        int set_v = find(v);

        if(set_u != set_v){
            if(r[set_u] < r[set_v])
                swap(set_u, set_v);
            p[set_v] = set_u;
            if(r[set_u] == r[set_v])
                r[set_u]++;
        }
    }

};

void dfs(int source, int p = 0, int d = 1, int W = INF){
    dep[source] = d;
    anc[source][0] = p;
    mini[source][0] = W;

    for(int i = 1; i < lg; i++){
        anc[source][i] = anc[anc[source][i - 1]][i - 1];
        mini[source][i] = min(mini[source][i - 1], mini[anc[source][i - 1]][i - 1]);
    }

    for(auto [u, w] : mst_adj[source]){
        if(u != p)
            dfs(u, source, d + 1, w);
    }

}

int max_path(int source, int dest){
    if(dep[source] < dep[dest]) swap(source, dest);
    int result = INF;

    for(int i = lg - 1; i >= 0; i--){
        if(dep[source] - dep[dest] >= (1 << i)) {
            result = min(result, mini[source][i]);
            source = anc[source][i];
        }
    }

    if(source == dest) return result;

    for(int i = lg - 1; i >= 0; i--){
        if(anc[source][i] != anc[dest][i]) {
            result = min({result, mini[source][i], mini[dest][i]});
            source = anc[source][i];
            dest = anc[dest][i];
        }
    }

    return min({result, mini[source][0], mini[dest][0]});
}

void solve_task(){
    int n, b; cin >> n >> b;

    mst_adj.resize(n + 1);
    dep.resize(n + 1);
    anc.resize(n + 1);

    for(int i = 1; i <= b; i++){
        Edge e; cin >> e.u >> e.v >> e.w;
        e.w = -e.w;
        edges.push_back(e);
        swap(e.u, e.v);
        edges.push_back(e);
    }

    DSU dsu(n + 1);
    sort(all(edges));

    for(Edge e : edges){
        if(dsu.find(e.u) != dsu.find(e.v)){
            dsu.union_find(e.u, e.v);
            mst_adj[e.u].push_back({e.v, -e.w});
            mst_adj[e.v].push_back({e.u, -e.w});
        }
    }

    int c; cin >> c;

    dfs(1);

    while(c--){
        int x, y; cin >> x >> y;
        cout << max_path(x, y) << endl;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    // cin >> tc;

    while(tc--) solve_task();

    return 0;
}