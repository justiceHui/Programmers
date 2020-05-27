#include <bits/stdc++.h>
using namespace std;

set<int> dp[11];

int solution(int k, int n) {
    int t = 0;
    for(int i=1; i<=8; i++) dp[i].insert(t = t*10+k);
    for(int i=1; i<=8; i++) for(int j=1; j<=i; j++) if(i + j <= 8){
        for(auto a : dp[i]) for(auto b : dp[j]){
            dp[i+j].insert(a+b);
            dp[i+j].insert(abs(a-b));
            dp[i+j].insert(a*b);
            if(a) dp[i+j].insert(b/a);
            if(b) dp[i+j].insert(a/b);
        }
    }
    for(int i=1; i<=8; i++) for(auto j : dp[i]) if(j == n) return i;
    return -1;
}