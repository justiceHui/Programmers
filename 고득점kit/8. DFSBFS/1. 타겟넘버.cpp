#include <string>
#include <vector>

using namespace std;

int solution(vector<int> v, int k) {
    int n = v.size(), ret = 0;
    for(int bit=0; bit<(1<<n); bit++){
        int t = 0;
        for(int i=0; i<n; i++){
            if(bit & (1 << i)) t += v[i];
            else t -= v[i];
        }
        if(t == k) ret++;
    }
    return ret;
}