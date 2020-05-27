#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p>> pq;
vector<p> v;

int solution(vector<vector<int>> jobs) {
    for(const auto &i : jobs) v.push_back({i[0], i[1]});
    sort(v.begin(), v.end());
    int idx = 0, t = 0, sum = 0;
    
    while(idx < v.size()){
        int st = idx;
        for(int i=st; i<v.size(); i++){
            if(v[st].first == v[i].first) pq.push({v[i].second, i}), idx = i+1;
            else break;
        }
        t = v[idx-1].first;
        while(pq.size()){
            int val = pq.top().first;
            int i = pq.top().second;
            pq.pop();
            t += val; sum += t - v[i].first;
            int st = idx;
            for(int j=st; j<v.size(); j++){
                if(v[j].first <= t) pq.push({v[j].second, j}), idx = j+1;
                else break;
            }
        }
    }
    return sum / jobs.size();
    
}

/*
문제에 나와있는대로 구현을 하면 되는데, 귀찮은 반례가 몇 개 있습니다.
아무 작업도 안 하는 경우, 입력 데이터가 시간 순으로 정렬되어 있지 않는 경우 등등...
*/