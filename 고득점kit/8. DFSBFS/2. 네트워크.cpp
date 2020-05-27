#include <bits/stdc++.h>
using namespace std;

int par[222];
int find(int v){ return v == par[v] ? v : par[v] = find(par[v]); }
void merge(int u, int v){ u = find(u), v = find(v); if(u ^ v) par[u] = v; }

int solution(int n, vector<vector<int>> computers) {
    iota(par, par+222, 0);
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(computers[i-1][j-1]) merge(i, j);
    int ret = 0;
    for(int i=1; i<=n; i++) ret += i == find(i);
    return ret;
}