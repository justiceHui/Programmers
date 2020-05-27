#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

int arr[111][111];
int dp[111][111];

int solution(int m, int n, vector<vector<int>> puddles) {
    for(const auto &i : puddles) arr[i[1]][i[0]] = 1;
    dp[1][1] = 1;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        if(i+1 <= n && !arr[i+1][j]) dp[i+1][j] += dp[i][j];
        if(j+1 <= m && !arr[i][j+1]) dp[i][j+1] += dp[i][j];
        dp[i+1][j] %= mod;
        dp[i][j+1] %= mod;
    }
    return dp[n][m];
}