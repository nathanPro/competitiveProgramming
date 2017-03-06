#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;

const int N = 1e5;
const int K = 20;
const int T = N<<2;

int a[N], n, m;
ull tree[K][T];
char lz[K][T];

void unlazy(int p, int t, int l, int r){
    if(!lz[p][t]) return;
    tree[p][t] = ull(r-l) - tree[p][t];
    if(1 < r-l){
        lz[p][t<<1]   ^= 1;
        lz[p][t<<1|1] ^= 1;
    }
    lz[p][t] = 0;
}

int ql, qr;
ull query(int p, int t, int l, int r){
    unlazy(p, t, l, r);
    if(ql <= l && r <= qr) return tree[p][t];
    if(r <= ql || qr <= l) return 0;
    int m = (l+r)/2;
    return query(p,t<<1,l,m) + query(p,t<<1|1,m,r);
}

void update(int p, int t, int l, int r){
    unlazy(p, t, l, r);
    if(ql <= l && r <= qr){
        lz[p][t] = 1; unlazy(p, t, l, r);
        return;
    }
    if(r <= ql || qr <= l) return;
    int m = (l+r)/2;
    if(1 < r-l) {
        update(p,t<<1,l,m); update(p,t<<1|1,m,r);
        tree[p][t] = tree[p][t<<1] + tree[p][t<<1|1];
    }
}

ull build(int p, int t, int l, int r){
    if(r-l < 1) return 0;
    if(1 == r-l) return tree[p][t] = (1&(a[l]>>p));
    int m = (l+r)/2;
    return tree[p][t] = build(p,t<<1,l,m) + build(p,t<<1|1,m,r);
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int p=0;p<K;p++) build(p, 1, 0, n);
    cin >> m;
    while(m--){
        int t, x;
        cin >> t >> ql >> qr;
        --ql;
        if(t == 1) {
            ull ans = 0;
            for(int p=0;p<K;p++) ans += ull(1<<p)*query(p, 1, 0, n);
            cout << ans << '\n';
        } else {
            cin >> x;
            for(int p=0;p<K;p++) if(1&(x>>p)) update(p, 1, 0, n);
        }
    }
}
