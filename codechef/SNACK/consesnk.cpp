#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const int N = 2e5;

int T;
ll ans;
ll n, a, b, l, s[N];

ll f(ll x){
    if(b < x + n*l - ll(1)) return LLONG_MAX;
    ll loc = 0;
    for(ll i=0;i<n;i++)
        loc += abs(s[i] - (x + i*l));
    ans = min(ans, loc);
    return loc;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> n >> l >> a >> b;
        for(int i=0;i<n;i++) cin >> s[i];
        sort(s,s+n);

        ans = LLONG_MAX;
        ll lo = a,
           hi = b;
        while(256 < hi-lo){
            ll ds = (hi-lo)/ll(3);
            if(f(lo + ds) <= f(hi - ds)) hi -= ds;
            else                         lo += ds;
        }
        for(ll i=lo;i<hi+1;i++) f(i);
        cout << ans << endl;
    }
}
