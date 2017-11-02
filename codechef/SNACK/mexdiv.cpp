#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const int N = 1e6;
const int T = N<<1;
const int oo = 1e9+7;

int n, k, a[N];

const ll M = (1e9 + 7);
struct mod{
    ll x;
    mod () { x = 0; }
    mod (ll y) { x = y; }
    mod operator+(mod b){ return (x+b.x)%M; }
    mod operator-(mod b){ return (x+M-b.x)%M; }
    mod operator*(mod b){ return (x*b.x)%M; }
};

struct node{
    int l, r;
    node operator+(node b){
        node c = {l,r},d = b;
        if(d.l < c.l) swap(c,d);

        if(d.l <= c.r) return {c.l, d.r};
        else           return {c.l, c.r};
    }
}; int mex(node a){ return (a.l == 0)*a.r; }

node tree[T];
node query(int l, int r){
    node ans = {oo, oo+1};
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) ans = ans + tree[l++];
        if(r&1) ans = ans + tree[--r];
    }
    return ans;
}

mod dp[N], D[N], P[N];

int main(){
    ios::sync_with_stdio(false);
    P[0] = 1; for(int i=1;i<N;i++) P[i] = mod(2)*P[i-1];

    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    if(!k){
        int ok = 1;
        mod ans = 1;
        for(int i=0;i<n;i++){
            ok &= (a[i] != 0);
            if(i) ans = ans * mod(2);
        }
        cout << ok*(ans.x) << endl;
        return 0;
    }


    for(int i=0;i<n;i++) tree[i+n] = {a[i],a[i]+1};
    for(int i=n-1;i+1;i--) tree[i] = tree[i<<1] + tree[i<<1|1];

    D[n] = 0;
    dp[n] = 1;
    for(int i=n-1;0<=i;i--){
        if(mex(query(i,n)) <= k) {
            dp[i] = P[n-i-1];
        } else {
            int lo = i+1, hi = n-1;
            while(lo < hi){
                int mid = (lo + hi)/2;
                if(k < mex(query(i,mid+1))) hi = mid;
                else lo = mid + 1;
            }
            dp[i] = D[i] - D[lo+1];
            cerr << i << ":" << lo << endl;
        }
        D[i] = D[i+1] + dp[i];

        cerr << dp[i].x << endl << endl;
    }

    cout << dp[0].x << endl;
}
