#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> v) {
    sort(v.begin(), v.end(), greater<int>());
    for(int i=v.size(); i>=1; i--) if(v[i-1] >= i) return i;
	return 0;
}

/*
no comment.
*/