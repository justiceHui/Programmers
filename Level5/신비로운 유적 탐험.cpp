#include <bits/stdc++.h>
using namespace std;

struct MCMF{
    int d[222][222];
    int c[222][222];
    vector<int> g[222];

    void init(){
        memset(d, 0, sizeof d);
        memset(c, 0, sizeof c);
        for(int i=0; i<222; i++) g[i].clear();
    }
    void addEdge(int s, int e, int x){
        g[s].push_back(e); d[s][e] = -x; c[s][e] = 1;
        g[e].push_back(s); d[e][s] = x;
    }

    int run(int s, int t){
        queue<int> q;
        int par[222], dst[222], inq[222];
        int ret = 0;
        while(1){
            memset(inq, 0, sizeof inq);
            memset(par, -1, sizeof par);
            memset(dst, 0x3f, sizeof dst);
            q.push(s); inq[s] = 1; dst[s] = 0;
            while(q.size()){
                int now = q.front(); q.pop(); inq[now] = 0;
                for(auto nxt : g[now]){
                    if(c[now][nxt] && dst[now] + d[now][nxt] < dst[nxt]){
                        dst[nxt] = dst[now] + d[now][nxt];
                        par[nxt] = now;
                        if(!inq[nxt]) q.push(nxt), inq[nxt] = 1;
                    }
                }
            }
            if(par[t] == -1) break;
            for(int i=t; i!=s; i=par[i]){
                c[par[i]][i]--; c[i][par[i]]++;
            }
            ret -= dst[t];
        }
        return ret;
    }
};

int dp[111][111];
vector<int> g1[111], g2[111];

int f(int i, int j, int p1, int p2){
    int &res = dp[i][j];
    if(res != -1) return res;
    int s = 220;
    int t = 221;
    MCMF mcmf;
    mcmf.init();
    for(auto u : g1[i]) mcmf.addEdge(s, u, 0);
    for(auto u : g2[j]) mcmf.addEdge(100 + u, t, 0);
    for(auto u : g1[i]) if(u ^ p1){
        for(auto v : g2[j]) if(v ^ p2){
            int now = f(u, v, i, j);
            mcmf.addEdge(u, 100 + v, now);
        }
    }
    return res = mcmf.run(s, t) + 1;
}

int solution(int n1, vector<vector<int>> g1, int n2, vector<vector<int>> g2) {
    memset(dp, -1, sizeof dp);
    for(int i=0; i<111; i++) ::g1[i].clear(), ::g2[i].clear();
    for(auto &i : g1){
        ::g1[i[0]].push_back(i[1]);
        ::g1[i[1]].push_back(i[0]);
    }
    for(auto &i : g2){
        ::g2[i[0]].push_back(i[1]);
        ::g2[i[1]].push_back(i[0]);
    }
    return f(1, 1, -1, -1);
}