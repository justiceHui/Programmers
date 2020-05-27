#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[88] = {0, 1, 1};

long long solution(int n) {
    if(n == 1) return 4;
    if(n == 2) return 6;
    for(int i=2; i<=n; i++) dp[i] = dp[i-1] + dp[i-2];
    ll a = dp[n] + dp[n-1];
    ll b = dp[n-1] + dp[n-2];
    return a+a+b+b;
}