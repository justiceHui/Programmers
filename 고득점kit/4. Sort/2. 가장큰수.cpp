#include <bits/stdc++.h>
using namespace std;

int f(const string &s){
    int ret = 0;
    for(const char &i : s) ret = ret * 10 + (i - '0');
    return ret;
}

bool cmp(int a, int b){
    string sa = to_string(a), sb = to_string(b);
    return f(sa + sb) > f(sb + sa);
}

string solution(vector<int> v){
    sort(v.begin(), v.end(), cmp);
    if(v[0] == 0) return "0";
    string ret;
    for(const int &i : v) ret += to_string(i);
    return ret;
}

/*
두 숫자 A, B가 있을 때 AB와 BA 중 더 큰 값이 나오도록 정렬하면 됩니다.
이 전략이 최적해를 갖는다는 것은 exchange argument로 증명할 수 있습니다.
*/