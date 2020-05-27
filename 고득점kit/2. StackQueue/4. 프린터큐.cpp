#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

int solution(vector<int> pri, int idx){
    int n = pri.size(), m = idx, ans = 0;
    queue<p> q;
    for(int i=0; i<n; i++) q.push({pri[i], i});
    sort(pri.begin(), pri.end());
    while(q.size()){
        int pr = q.front().first, idx = q.front().second;
        q.pop();
        if(pri.back() == pr){
            ans++; pri.pop_back();
            if(idx == m) break;
        }
        else q.push({pr, idx});
    }
    return ans;
}

/*
단순 구현 문제입니다.
*/