#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

const int N = 4e6;
const int X = (1e7+5);

int n, m, k, as;
int a[N], p[N], ans[N];
int tree[X<<1];

ll query(int l, int r){
    ll ans = 0;
    for(l+=X,r+=X; l<r;l>>=1,r>>=1){
        if(l&1) ans += ll(tree[l++]);
        if(r&1) ans += ll(tree[--r]);
    }
    return ans;
}
void insert(int p){
    for(tree[p+=X]++;p;p>>=1)
        tree[p>>1] = tree[p] + tree[p^1];
}

int main(){
    scanf(" %d%d%d", &n, &m, &k);
    for(int i=0;i<n;i++){
        int in; scanf(" %d", &in);
        insert(in);
    }

    for(int i=0;i<m;i++) scanf(" %d", a+i), p[i] = i;
    sort(p,p+m,[&](int i, int j){ return a[i] < a[j]; });

    for(int i=1;i<X;i++)
        if(ll(i)*ll(k) < query(0,i)){
            puts("-1");
            return 0;
        }

    int lo = 0;
    while(lo < X && query(0, lo+1) - query(0, lo) == k) lo++;
    for(int _i=0;_i<m;_i++){
        int i = p[_i];
        if(lo <= a[i]){
            ans[as++] = i;
            insert(lo);
            while(lo < X && query(0, lo+1) - query(0, lo) == k) lo++;
            if(lo == (1e7 + 1)) break;
        }
    }
    printf("%d\n", as);
    for(int i=0;i<as;i++) printf("%d%c", 1+ans[i], " \n"[i+1==as]);
}
