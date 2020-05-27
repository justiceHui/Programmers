#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int n = s.size(), ret = 0;
    for(const auto &i : s) ret += min(i - 'A', 26 - i + 'A');
    int t = 1e9+7;
    for(int i=0; i<n; i++){
        int j = i + 1; while(j < n && s[j] == 'A') j++;
        t = min({ t, i+(j==n?0:n+i-j), 2*n+i-2*j });
    }
    return ret + t;
}