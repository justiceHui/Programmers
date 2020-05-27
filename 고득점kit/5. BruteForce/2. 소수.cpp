#include <bits/stdc++.h>
using namespace std;

int isPrime(int x){
    if(x <= 1) return 0;
    for(int i=2; i*i<=x; i++) if(x % i == 0) return 0;
    return 1;
}

int solution(string numbers) {
    set<int> st;
    vector<int> v;
    for(const char &i : numbers) v.push_back(i - '0');
    sort(v.begin(), v.end());
    do{
        int now = 0;
        for(auto i : v){
            now = now * 10 + i;
            if(isPrime(now)) st.insert(now);
        }
    }while(next_permutation(v.begin(), v.end()));
    return st.size();
}

/*
소수 판별은 O(√N)에 할 수 있습니다.
*/