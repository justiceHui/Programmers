#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mx = 0, sum = 0, k;
vector<int> v;

int chk(int x){
    ll ret = 0;
    for(const auto &i : v){
        if(i <= x) ret += i;
        else ret += x;
    }
    return ret <= k;
}

int solution(vector<int> v, int k) {
    int n = v.size(); ::k = k; ::v = v;
    for(const auto &i : v) mx = max<ll>(mx, i), sum += i;
    if(sum <= k) return (int)mx;
    ll l = 0, r = 1e9+7;
    while(l < r){
        ll m = l + r + 1 >> 1;
        if(chk(m)) l = m;
        else r = m - 1;
    }
    return (int)l;
}