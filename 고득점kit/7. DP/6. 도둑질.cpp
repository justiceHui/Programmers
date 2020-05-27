#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1010101];
int ret;

int solution(vector<int> v) {
    n = v.size();
    dp[0] = dp[1] = v[0];
    for(int i=2; i<n-1; i++) dp[i] = max(dp[i-1], dp[i-2] + v[i]);
    ret = *max_element(dp, dp+n);
    memset(dp, 0, sizeof dp);
    dp[0] = 0, dp[1] = v[1];
    for(int i=2; i<n; i++) dp[i] = max(dp[i-1], dp[i-2] + v[i]);
    ret = max(ret, *max_element(dp, dp+n));
    return ret;
}