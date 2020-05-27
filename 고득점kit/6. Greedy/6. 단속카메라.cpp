#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
vector<p> v;

int solution(vector<vector<int>> routes) {
    int n = routes.size();
    for(const auto &i : routes) v.push_back({i[0], i[1]});
    sort(v.begin(), v.end());
    int ret = 0, mn = v[0].second;
    for(int i=1; i<n; i++){
        if(mn < v[i].first) ret++, mn = v[i].second;
        mn = min(mn, v[i].second);
    }
    return ret + 1;
}