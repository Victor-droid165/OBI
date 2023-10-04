#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve_task(){
    int n;
    cin >> n;
    vector<int> camelos(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> camelos[i];
        sum += camelos[i];
    }

    sum/=n;
    for (int i = 0; i < n; i++) 
        camelos[i] = sum - camelos[i];
    
    for(int camelo : camelos)
        cout << camelo << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    while(tc--) solve_task();
    return 0;
}
