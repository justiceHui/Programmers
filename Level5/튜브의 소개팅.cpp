#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;
const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1};

ll dp[55][55][3030];

vector<int> solution(int n, int m, int s, vector<vector<int>> mp) {
    memset(dp, 0x3f, sizeof dp); dp[0][0][0] = 0;
    for(int k=0; k<3030-1; k++) for(int i=0; i<n; i++) for(int j=0; j<m; j++) if(mp[i][j] != -1){
        for(int x=0; x<4; x++){
            int ii = i + di[x], jj = j + dj[x];
            if(ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
            if(dp[i][j][k] + mp[i][j] <= s) dp[ii][jj][k+1] = min(dp[ii][jj][k+1], dp[i][j][k] + mp[i][j]);
        }
    }
    for(int k=0; k<3030; k++) if(dp[n-1][m-1][k] <= 1e18) return {k, (int)dp[n-1][m-1][k]};
}