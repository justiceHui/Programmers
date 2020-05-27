#include <bits/stdc++.h>
using namespace std;

int dp[2020][2020], n;
vector<int> a, b;

int f(int i, int j){
    int &res = dp[i][j];
    if(res != -1) return res;
    if(i == a.size() || j == b.size()) return res = 0;
    res = f(i+1, j+1);
    res = max(res, f(i+1, j));
    if(a[i] > b[j]) res = max(res, f(i, j+1) + b[j]);
    return res;
}

int solution(vector<int> left, vector<int> right) {
    a = left, b = right;
    memset(dp, -1, sizeof dp);
    return f(0, 0);
}