#include <bits/stdc++.h>
using namespace std;

int n, k, d;
vector<int> v;

int chk(int x){
    int cnt = 0, ed = 0;
    for(int i=0; i<n; i++){
        if(v[i] - ed >= x) cnt++, ed = v[i];
    }
    return n - cnt <= k;
}

int solution(int distance, vector<int> V, int K) {
    k = K; d = distance;
    for(auto i : V) v.push_back(i); v.push_back(d);
    sort(v.begin(), v.end());
    n = v.size();
    int l = 0, r = 1e9+7;
    while(l < r){
        int m = l + r + 1 >> 1;
        if(chk(m)) l = m;
        else r = m - 1;
    }
    return l;
}