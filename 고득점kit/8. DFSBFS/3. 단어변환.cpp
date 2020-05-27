#include <bits/stdc++.h>
using namespace std;

map<string, int> dst;
string s, t;
set<string> st;

int solution(string S, string T, vector<string> words) {
    s = S, t = T;
    for(const auto &i : words) st.insert(i);
    
    queue<string> q; dst[S] = 0; q.push(S);
    while(q.size()){
        string now = q.front(); q.pop();
        string nxt = now;
        for(int i=0; i<now.size(); i++){
            for(int j=0; j<26; j++){
                nxt[i] = j + 'a';
                if(!st.count(nxt)) continue;
                if(dst.count(nxt)) continue;
                dst[nxt] = dst[now] + 1;
                q.push(nxt);
            }
            nxt[i] = now[i];
        }
    }
    return dst[T];
}