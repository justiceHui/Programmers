#include <bits/stdc++.h>
using namespace std;

int A[] = {1, 2, 3, 4, 5};
int B[] = {2, 1, 2, 3, 2, 4, 2, 5};
int C[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> v) {
    int a = 0, b = 0, c = 0; int n = v.size();
    for(int i=0; i<n; i++){
        a += A[i%5] == v[i];
        b += B[i%8] == v[i];
        c += C[i%10] == v[i];
    }
    int mx = max({a, b, c});
    vector<int> ret;
    if(a == mx) ret.push_back(1);
    if(b == mx) ret.push_back(2);
    if(c == mx) ret.push_back(3);
    return ret;
}

/*
no comment.
*/