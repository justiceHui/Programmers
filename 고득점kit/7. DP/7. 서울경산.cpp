#include <bits/stdc++.h>
using namespace std;

int w[111], wc[111], b[111], bc[111]; //walk / cost, bike / cost
int dp[111][101010];

int solution(int k, vector<vector<int>> v) {
    int n = v.size();
    for(int i=1; i<=n; i++){
        w[i] = v[i-1][0];
        wc[i] = v[i-1][1];
        b[i] = v[i-1][2];
        bc[i] = v[i-1][3];
    }
    
    int mx = 0;
    dp[1][w[1]] = wc[1], dp[1][b[1]] = bc[1];
    for(int i=2; i<=n; i++) for(int j=0; j<=k; j++){
        if(!dp[i-1][j]) continue;
        if(j + w[i] <= k) dp[i][j+w[i]] = max(dp[i][j+w[i]], dp[i-1][j] + wc[i]);
        if(j + b[i] <= k) dp[i][j+b[i]] = max(dp[i][j+b[i]], dp[i-1][j] + bc[i]);
        mx = max({mx, dp[i][j+w[i]], dp[i][j+b[i]]});
    }
    return mx;
}