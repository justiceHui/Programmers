#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int query(int l, int r, int x){
    vector<int> t(v.begin()+l, v.begin()+r+1);
    sort(t.begin(), t.end());
    return t[x-1];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    v = array;
    vector<int> ret;
    for(const auto &i : commands){
        ret.push_back(query(i[0]-1, i[1]-1, i[2]));
    }
    return ret;
}

/*
문제에서 하라는대로 하면 O(QN log N)에 풀 수 있습니다.
Merge Sort Tree, Persistent Segment Tree를 사용하면 각각 O(Q log^3 N), O(Q log^2 N)에 해결할 수 있습니다.
*/