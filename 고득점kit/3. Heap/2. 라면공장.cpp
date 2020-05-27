#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

int solution(int now, vector<int> dates, vector<int> supplies, int n) {
    int ret = 0, idx = 0;
    for(int i=0; i<n; i++){
        if(idx < dates.size() && dates[idx] == i) pq.push(supplies[idx++]);
        if(!now) ret++, now += pq.top(), pq.pop();
        now--;
    }
    return ret;
}

/*
간단한 전략을 사용하는 그리디 문제입니다.
*/