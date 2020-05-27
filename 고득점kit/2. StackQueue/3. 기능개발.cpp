#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prog, vector<int> sp) {
    vector<int> v, ret;
    for(int i=0; i<sp.size(); i++) v.push_back((100 - prog[i] + sp[i] - 1) / sp[i]);
    
    map<int, int> mp; int mx = 0;
    for(int i=0; i<v.size(); i++){
        mx = max(mx, v[i]); mp[mx]++;
    }
    for(auto i : mp) ret.push_back(i.second);
    return ret;
}

/*
1. 소요시간 계산
2. 나보다 왼쪽에 있는 원소 중 최댓값 계산
*/