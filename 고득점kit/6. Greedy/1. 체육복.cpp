#include <bits/stdc++.h>
using namespace std;

int chk[33];

int solution(int n, vector<int> lost, vector<int> reserve) {
    for(const auto &i : lost) chk[i]--;
    for(const auto &i : reserve) chk[i]++;
    for(int i=1; i<=n; i++) if(chk[i] == 1){
        if(chk[i-1] == -1) chk[i]--, chk[i-1]++;
        else if(chk[i+1] == -1) chk[i]--, chk[i+1]++;
    }
    int ans = 0;
    for(int i=1; i<=n; i++) ans += chk[i] >= 0;
    return ans;
}