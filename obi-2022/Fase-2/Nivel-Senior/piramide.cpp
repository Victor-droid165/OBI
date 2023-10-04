#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve_task(){
    int n; cin >> n;
    int matrix[n][n] = {{0}};

    int i = 0, j = 0, num = 1;

    while(matrix[i][j] == 0){
        for(; j <= n - num; j++)
            matrix[i][j] = num;
        j--;
        for(; i <= n - num; i++)
            matrix[i][j] = num;
        i--;
        for(; j >= num - 1; j--)
            matrix[i][j] = num;
        j++;
        for(; i >= num; i--)
            matrix[i][j] = num;
        i++;
        num++;
        if(j < n - 1) j++;
        if(i >= n) i = n - 1;
    }

    for(i = 0; i < n; i++){
        cout << matrix[i][0];
        for(j = 1; j < n; j++)
            cout << " " << matrix[i][j];
        cout << endl;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    // cin >> tc;

    while(tc--) solve_task();

    return 0;
}