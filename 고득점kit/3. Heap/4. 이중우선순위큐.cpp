#include <bits/stdc++.h>
using namespace std;

multiset<int> st;

vector<int> solution(vector<string> operations) {
    for(const string &i : operations){
        if(i == "D -1" && st.size()) st.erase(st.begin());
        else if(i == "D 1" && st.size()) st.erase(st.find(*st.rbegin()));
        else if(i[0] == 'I'){
            int t = 0, flag = 0;
            for(int j=2; j<i.size(); j++){
                if(i[j] == '-') flag = 1;
                else t = t * 10 + (i[j] - '0');
            }
            if(flag) t *= -1;
            st.insert(t);
        }
    }
    if(st.size()) return {*st.rbegin(), *st.begin()};
    return {0, 0};
}

/*
C++의 std::multiset을 이용해 쉽게 해결할 수 있습니다.
*/