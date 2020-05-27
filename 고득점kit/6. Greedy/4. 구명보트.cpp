#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int k) {
    deque<int> v(people.begin(), people.end());
    sort(v.begin(), v.end());
    int ret = 0;
    while(v.size()){
        if(v.size() == 1){ ret++; break; }
        if(v[0] + v.back() <= k){
            ret++; v.pop_front(); v.pop_back();
        }else{
            ret++; v.pop_back();
        }
    }
    return ret;
}