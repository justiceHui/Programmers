#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int n, m; // n + m - 2 = brown / 2
    for(int i=1; i<=brown; i++){
        int j = brown / 2 + 2 - i;
        if(i >= j && (i-2) * (j-2) == yellow) return {i, j};
    }
}

/*
식을 세우면 쉽게 풀 수 있습니다.
*/