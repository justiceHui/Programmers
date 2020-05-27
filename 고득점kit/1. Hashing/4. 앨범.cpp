#include <bits/stdc++.h>
using namespace std;

struct Node{
    string g; int p, id; //genre, play, id
};

map<string, int> g_cnt; //genre count
vector<Node> v;

bool cmp(const Node &a, const Node &b){
    if(a.g != b.g) return g_cnt[a.g] > g_cnt[b.g];
    if(a.p != b.p) return a.p > b.p;
    return a.id < b.id;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    int n = genres.size();
    for(int i=0; i<n; i++) v.push_back({genres[i], plays[i], i}), g_cnt[genres[i]] += plays[i];
    sort(v.begin(), v.end(), cmp);
    vector<int> ret; g_cnt.clear();
    for(const Node &i : v) if(++g_cnt[i.g] <= 2) ret.push_back(i.id);
    return ret;
}

/*
정렬 기준을 잘 세워서 정렬하면 됩니다.
*/