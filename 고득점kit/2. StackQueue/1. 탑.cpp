#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

stack<p> stk;

vector<int> solution(vector<int> v){
    vector<int> ret;
    stk.push({1e9, 0});
    for(int i=0; i<v.size(); i++){
        while(stk.top().first <= v[i]) stk.pop();
        ret.push_back(stk.top().second);
        stk.push({v[i], i+1});
    }
    return ret;
}

/*
https://justicehui.github.io/medium-algorithm/2019/01/01/monotoneStack/
*/