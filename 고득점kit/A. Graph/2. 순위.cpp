#include <bits/stdc++.h>
using namespace std;

int dst[111][111];

int solution(int n, vector<vector<int>> results) {
    for(const auto &i : results) dst[i[0]][i[1]] = 1;
    for(int k=1; k<=n; k++) for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        if(dst[i][k] && dst[k][j]) dst[i][j] = 1;
    }
    int ret = 0;
    for(int i=1; i<=n; i++){
        int t = 0;
        for(int j=1; j<=n; j++) if(i ^ j) t += (dst[i][j] || dst[j][i]);
        if(t == n - 1) ret++;
    }
    return ret;
}