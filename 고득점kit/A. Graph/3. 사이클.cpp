#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> g[5050], inp[5050];
int dep[5050], full[5050], sub[5050], ab[5050];
/*
full[v] : v를 루트로 하는 서브트리에 완전히 포함된 back edge 개수
sub[v] : v를 루트로 하는 서브트리에 조금이라도 포함된 back edge 개수
absolute[v] : v의 부모와 연결된 back edge 개수
*/

void dfs(int v, int p){
	for(auto i : inp[v]){
		if(i == p) continue;
		if(!dep[i]){ //tree edge
			g[v].push_back(i);
			dep[i] = dep[v] + 1;
			int t = full[v]; dfs(i, v); ab[i] = full[v] - t;
			full[v] += full[i]; sub[v] += sub[i];
		}else if(dep[i] < dep[v]){ //back edge
			full[i]++; sub[v]++;
		}
	}
}

int solution(int n, vector<vector<int>> edges) {
    ::n = n; m = edges.size();
    for(const auto &i : edges){
        inp[i[0]].push_back(i[1]);
        inp[i[1]].push_back(i[0]);
    }
    dep[1] = 1; dfs(1, -1);
    
    int ret = 0;
    for(int i=1; i<=n; i++){
        int t = 1;
        //full[ch] != 0이면 서브트리 내우에 사이클 존재
        //i의 부모보다 위로 올라가는 간선이 2개 이상인 경우, 정점을 제거하면 tree edge, back edge 모두 생성
        for(auto ch : g[i]) if(sub[ch] - ab[ch] > 1 || full[ch]) t = 0;
        if(m-n+1-sub[i]) t = 0; //i가 관여 안 하는 곳에 back edge 존재
        if(t) ret += i;
    }
    return ret;
}