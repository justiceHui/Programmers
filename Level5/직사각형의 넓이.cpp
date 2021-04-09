#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define IDX(v, x) lower_bound(all(v), x) - v.begin()
using namespace std;

typedef long long ll;

struct Line{
    ll x, y, yy, v;
    Line() = default;
    Line(ll x, ll y, ll yy, ll v) : x(x), y(y), yy(yy), v(v) {}
    bool operator < (const Line &t) const { return x < t.x; }
};

int n;
vector<Line> v;
vector<ll> comp;

struct Seg{
    ll tree[1 << 20], cnt[1 << 20];
    void get(int node, int s, int e){
        if(cnt[node]) tree[node] = comp[e] - comp[s-1];
        else if(s != e) tree[node] = tree[node << 1] + tree[node << 1 | 1];
        else tree[node] = 0;
    }
    void update(int node, int s, int e, int l, int r, ll v){
        if(r < s || e < l) return;
        if(l <= s && e <= r){
            cnt[node] += v; get(node, s, e);
            return;
        }
        int m = s + e >> 1;
        update(node << 1, s, m, l, r, v);
        update(node << 1 | 1, m+1, e, l, r, v);
        get(node, s, e);
    }
    ll query(){ return tree[1]; }
} seg;

long long solution(vector<vector<int>> inp){
    n = inp.size();
    for(int i=0; i<n; i++){
        ll x = inp[i][0], xx = inp[i][2];
        ll y = inp[i][1], yy = inp[i][3];
        v.emplace_back(x, y, yy, 1);
        v.emplace_back(xx, y, yy, -1);
        comp.push_back(y); comp.push_back(yy);
    }
    sort(all(v));
    compress(comp);
    
    ll prv = v[0].x, ans = 0;
    for(auto i : v){
        ans += (i.x - prv) * seg.query();
        seg.update(1, 1, comp.size()-1, IDX(comp, i.y)+1, IDX(comp, i.yy), i.v);
        prv = i.x;
    }
    return ans;
}
