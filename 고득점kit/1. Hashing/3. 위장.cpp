#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int solution(vector<vector<string>> v) {
    int ans = 1;
    for(const auto &i : v) mp[i[1]]++;
    for(const auto &i : mp) ans *= i.second + 1;
    return ans - 1;
}

/*
간단한 수학 문제입니다.
*/