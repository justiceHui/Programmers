#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll n, m; vector<ll> v;

int chk(ll x){
    ll sum = 0;
	for(auto i : v){
        sum += x / i;
        if(sum >= m) return 1;
    }
	return sum >= m;
}

long long solution(int M, vector<int> V) {
    m = M; n = V.size(); for(auto i : V) v.push_back(i);
    sort(v.begin(), v.end());
    ll l = 0, r = 1e18;
    while(l < r){
        ll m = l + r >> 1;
        if(chk(m)) r = m;
        else l = m + 1;
    }
    return r;
}