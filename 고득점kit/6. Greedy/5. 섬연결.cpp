#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int s, e, x;
    bool operator < (const Edge &t) const {
        return x < t.x;
    }
};

int par[111];
int find(int v){ return v == par[v] ? v : par[v] = find(par[v]); }
bool merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return 0;
    par[u] = v; return 1;
}

int solution(int n, vector<vector<int>> costs) {
    vector<Edge> edge;
    for(int i=0; i<costs.size(); i++){
        edge.push_back({costs[i][0], costs[i][1], costs[i][2]});
    }
    sort(edge.begin(), edge.end());
    int ret = 0;
    iota(par, par+111, 0);
    for(const auto &i : edge){
        if(merge(i.s, i.e)) ret += i.x;
    }
    return ret;
}