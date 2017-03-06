#include <bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
using namespace std;
using ll = int64_t;
using ull = uint64_t;

const int N = 2e5;
int n, a[N], b[N], h[N], p[N];
int la, lb;
ll ans, loc;
int seen[N], ss;
int idx(int x){ return lower_bound(seen, seen+ss, x) - seen;}

ll tree[N<<1];
ll query(int l, int r){
    ll ans = 0;
    for(l+=ss,r+=ss;l<r;l>>=1,r>>=1){
        if(l&1) ans = max(ans, tree[l++]);
        if(r&1) ans = max(ans, tree[--r]);
    }
    return ans;
}
void insert(int p, ll x){
    p += ss;
    tree[p] = max(tree[p], x);
    for(;p;p>>=1)
        tree[p>>1] = max(tree[p], tree[p^1]);
}

int main(){
    scanf(" %d", &n);
    for(int i=0;i<n;i++) scanf(" %d%d%d", a+i, b+i, h+i);
    for(int i=0;i<n;i++) {
        seen[ss++] = a[i];
        seen[ss++] = b[i];
        p[i] = i;
    }
    sort(seen, seen+ss);
    ss = unique(seen, seen+ss) - seen;
    sort(p,p+n,[&](int i, int j){ return mp(b[i],-a[i]) < mp(b[j],-a[j]); });

    for(int _i=0;_i<n;_i++){
        int i = p[_i], a = idx(::a[i]), b = idx(::b[i]);
        insert(b, h[i] + query(a+1, b+1));
    }

    cout << query(0,ss) << endl;
}
