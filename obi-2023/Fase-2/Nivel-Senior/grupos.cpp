#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

size_t E, M, D, ans = 0;
unordered_map<ll, vector<ll>> mpM;
unordered_map<ll, vector<ll>> mpD;

void solve_task(){
    cin >> E >> M >> D;

    for(size_t i = 0; i < E; i++){
        mpM.insert({i+1, {}});
        mpD.insert({i+1, {}});
    }

    for(size_t i = 0; i < M; i++){
        size_t x, y;

        cin >> x >> y;
        mpM[x].push_back(y);
    }

    for(size_t i = 0; i < D; i++){
        size_t x, y;

        cin >> x >> y;
        mpD[x].push_back(y);
    }

    for(size_t i = 1; i <= E; i++){
        sort(mpM[i].begin(), mpM[i].end());
        sort(mpD[i].begin(), mpD[i].end());
    }

    for(size_t i = 0; i < E/3; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        for(int k = 0; k < 3; k++){
            int ab = 0, ac = 0;

            vector<ll>::iterator it = lower_bound(mpM[a].begin(), mpM[a].end(), b);
            
            if(it != mpM[a].end() && *it == b)
                ab = 1;

            it = lower_bound(mpM[a].begin(), mpM[a].end(), c);
            if(it != mpM[a].end() && *it == c)
                ac = 1;

            ans += mpM[a].size() - ab - ac;

            ab = ac = 0;

            it = lower_bound(mpD[a].begin(), mpD[a].end(), b);
            if(it != mpD[a].end() && *it == b)
                ab = 1;

            it = lower_bound(mpD[a].begin(), mpD[a].end(), c);
            if(it != mpD[a].end() && *it == c)
                ac = 1;

            ans += ab + ac;
            if(k == 0) swap(a, b);
            else swap(a, c);
        }
    }
    cout << ans << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve_task();
    return 0;
}