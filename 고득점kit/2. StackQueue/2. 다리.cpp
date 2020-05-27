#include <bits/stdc++.h>
using namespace std;

int n, w, l; //bridge length, limit weight
int arr[10101];
int sum, ans = 1;

void move(){
    for(int i=1; i<=w; i++) arr[i-1] = arr[i];
    arr[w] = 0; sum -= arr[0]; ans++;
}

int solution(int bridge_length, int weight, vector<int> v){
    w = bridge_length, l = weight; n = v.size();
    for(int i=0; i<n; i++){
        bool flag = 0;
        while(sum + v[i] > l) move(), flag = 1;
        if(!flag && sum) move();
        arr[w] = v[i]; sum += v[i];
    }
    while(sum > 0) move();
    return ans;
}

/*
트럭을 한 칸 이동시키는 것만 잘 구현하면 어렵지 않게 풀 수 있습니다.
*/