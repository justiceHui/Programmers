#include <bits/stdc++.h>
using namespace std;

vector<int> g[20202];
int dst[20202];

int solution(int n, vector<vector<int>> edge) {
    for(const auto &i : edge){
        g[i[0]].push_back(i[1]);
        g[i[1]].push_back(i[0]);
    }
    memset(dst, -1, sizeof dst);
    queue<int> q; q.push(1); dst[1] = 0;
    while(q.size()){
        int now = q.front(); q.pop();
        for(auto nxt : g[now]) if(dst[nxt] == -1){
            dst[nxt] = dst[now] + 1;
            q.push(nxt);
        }
    }
    int mx = *max_element(dst+1, dst+n+1);
    int ret = 0;
    for(int i=1; i<=n; i++) if(dst[i] == mx) ret++;
    return ret;
}