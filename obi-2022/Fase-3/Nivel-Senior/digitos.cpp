#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

string A;
int n;
vector<char> nums;

string prox_string(string& ant){
    int carry = 1;
    for(int i = ant.length() - 1; i >= 0 && carry; i--){
        if(ant[i] + 1 > '9')
            ant[i] = '0';
        else{
            carry = 0;
            ant[i] += 1;
        }
    }

    if(carry)
        return "1" + ant;
    else
        return ant;
}

bool calcA(int d){
    int i = 0;
    bool flag = false;
    string ans = "", prox;
    string maxPow;
    for(int k = 0; k < d; k++)
        maxPow.push_back('9');

    for(; i < n;){
        string num;
        int cont = 0;
        while(cont < d && i < n){
            num.push_back(nums[i++]);
            cont++;
        }
        if((int)num.length() < d) return false;
        if(flag && num != prox) return false;

        ans = num;
        prox = prox_string(num);
        if(prox.length() > ans.length())
            d++;

        if(!flag)
            A = ans;
        flag = true;
    }
    return flag;
}

void solve_task(){
    cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int d = 1;
    while(!calcA(d++) && d <= n);
    cout << A << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    while(tc--) solve_task();
    return 0;
}
