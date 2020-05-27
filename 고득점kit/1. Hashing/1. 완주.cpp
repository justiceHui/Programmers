#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> v, vector<string> fin) {
    multiset<string> st;
    for(const string &i : v) st.insert(i);
    for(const string &i : fin) st.erase(st.find(i));
    return *st.begin();
}

/*
중복을 허용하는 set에 모든 참가자를 집어넣고, 완주한 선수들을 모두 빼면 완주하지 못한 선수만 남게 됩니다.
*/