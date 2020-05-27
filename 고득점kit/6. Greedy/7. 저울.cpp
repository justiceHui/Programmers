#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> v) {
    sort(v.begin(), v.end());
    int sum = 0;
    for(int i=0; i<v.size(); i++){
        if(sum+1 < v[i]) return sum + 1;
        sum += v[i];
    }
    return sum + 1;
}