#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
stack<p> stk;

vector<int> solution(vector<int> v){
    vector<int> ret; int n = v.size();
    stk.push({-1, n-1});
    for(int i=n-1; i>=0; i--){
        while(stk.top().first >= v[i]) stk.pop();
        ret.push_back(stk.top().second - i);
        stk.push({v[i], i});
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

/*
https://justicehui.github.io/medium-algorithm/2019/01/01/monotoneStack/
*/