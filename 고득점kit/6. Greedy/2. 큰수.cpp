#include <bits/stdc++.h>
using namespace std;

string solution(string s, int k) {
    string ret;
    int n = s.size();
    deque<char> dq;
	for(int i=0; i<k; i++){
		while(dq.size() && dq.back() < s[i]) dq.pop_back();
		dq.push_back(s[i]);
	}
	for(int i=k; i<n; i++){
		while(dq.size() && dq.back() < s[i]) dq.pop_back();
		dq.push_back(s[i]);
		ret += dq.front(); dq.pop_front();
	}
    return ret;
}