#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll>> pq;

int solution(vector<int> scoville, int k){
    int ans = 0;
    for(const int &i : scoville) pq.push(i);
    while(pq.size() >= 2 && pq.top() < k){
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        pq.push(a + b + b);
        ans++;
    }
    if(pq.top() >= k) return ans;
    else return -1;
}

/*
단순 구현 문제입니다.
*/