#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<string, string> p;

vector<p> edge;
int chk[1010101];
vector<string> ans, now;

int dfs(string v, int idx){
    now.push_back(v);
    if(idx == edge.size()){ ans = now; return 1; }
    for(int i=0; i<edge.size(); i++){
        if(edge[i].x != v || chk[i]) continue;
        chk[i] = 1;
        if(dfs(edge[i].y, idx+1)) return 1;
        chk[i] = 0;
    }
    now.pop_back();
    return 0;
}

vector<string> solution(vector<vector<string>> tickets) {
    for(const auto &i : tickets) edge.push_back({i[0], i[1]});
    sort(edge.begin(), edge.end());
    dfs("ICN", 0);
    return ans;
}