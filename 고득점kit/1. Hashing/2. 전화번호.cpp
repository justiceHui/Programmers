#include <bits/stdc++.h>
using namespace std;

int ans = 0;

struct Node{
    bool valid;
    Node *child[10];
    Node(){ for(int i=0; i<10; i++) child[i] = NULL; valid = 0; }
    void insert(const char *s){
        if(*s == 0){ valid = 1; return; }
        int now = *s - '0';
        if(valid) ans = 1;
        if(child[now] == 0) child[now] = new Node();
        child[now]->insert(s+1);
    }
};

Node *trie;

bool solution(vector<string> v) {
    sort(v.begin(), v.end(), [&](const string &a, const string &b){
        return a.size() < b.size();
    });
    trie = new Node();
    for(const string &i : v){
        trie->insert(i.c_str());
    }
    return !ans;
}

/*
길이 순서대로 정렬하고 차례대로 trie에 넣어주면 prefix가 존재하는지 쉽게 확인해줄 수 있습니다.
*/