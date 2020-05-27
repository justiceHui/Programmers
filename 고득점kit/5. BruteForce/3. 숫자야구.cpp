#include <bits/stdc++.h>
using namespace std;

int n, pv;
int N[111], S[111], B[111];

int chk(int x){
    int a = x / 100, b = x / 10 % 10, c = x % 10;
    if(!a || !b || !c || a == b || b == c || c == a) return 0;
    int st = 0, ba = 0;
    for(int i=1; i<=n; i++){
        int aa = N[i] / 100, bb = N[i] / 10 % 10, cc = N[i] % 10;
        st = ba = 0;
        if(aa == a) st++;
        else if(aa == b || aa == c) ba++;
        if(bb == b) st++;
        else if(bb == a || bb == c) ba++;
        if(cc == c) st++;
        else if(cc == a || cc == b) ba++;
        if(st != S[i] || ba != B[i]) return 0;
    }
    return 1;
}

int solution(vector<vector<int>> baseball) {
    n = baseball.size();
    for(const auto &i : baseball){
        pv++; N[pv] = i[0], S[pv] = i[1], B[pv] = i[2];
    }
    int ret = 0;
    for(int i=100; i<1000; i++) ret += chk(i);
    return ret;
}

/*
100부터 999까지의 모든 수를 보면서 정답이 될 수 있는지 확인하면 됩니다. 
*/