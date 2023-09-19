#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

deque<ll> vals;
ll N, I = -1;
size_t ans = 0;

void solve_task(){
    cin >> N;
    while(N-- > 0){
        set<ll> nums(vals.begin(), vals.end());
        size_t len = nums.size();

        cin >> I;
        nums.insert(I);
        vals.push_back(I);

        while(nums.size() > len && N-- > 0){
            len++;
            cin >> I;
            nums.insert(I);
            vals.push_back(I);
        }

        if(nums.size() > len)
            ans = max(ans, vals.size());
        else
            ans = max(ans, vals.size()-1);

        while(vals.front() != I){
            vals.pop_front();
        }
        vals.pop_front();
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve_task();
    return 0;
}