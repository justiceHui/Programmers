#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int n = s.size(), stk = 0, ans = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '(') stk++;
        else if(s[i-1] == '(') stk--, ans += stk; //레이저 발사 -> 지금까지 쌓여있는 막대기 모두 자름
        else stk--, ans++;
    }
    return ans;
}

/*
()가 나오면 현재까지 쌓여있는 모든 쇠막대기를 자르게 됩니다. -> 현재 쌓여있는 막대기의 개수만큼 정답이 증가합니다.
*/