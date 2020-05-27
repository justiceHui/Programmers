#include <bits/stdc++.h>
using namespace std;

int n, v[555][555], dp[555][555];

int solution(vector<vector<int>> tri) {
    n = tri.size();
    for(int i=0; i<n; i++) for(int j=0; j<=i; j++) v[i][j] = tri[i][j];
    dp[0][0] = v[0][0];
    for(int i=0; i<n; i++) for(int j=0; j<=i; j++){
        dp[i+1][j] = max(dp[i+1][j], dp[i][j] + v[i+1][j]);
        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + v[i+1][j+1]);
    }
    int mx = dp[n-1][0];
    for(int i=0; i<n; i++) mx = max(mx, dp[n-1][i]);
    return mx;
}