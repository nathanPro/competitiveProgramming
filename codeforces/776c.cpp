#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

const int N = 2e5;
const ll T = 1e15;

ll n, k, a[N], d[N], ans;
map<ll, ll> F;
set<ll> seen;

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=1;i<n;i++) a[i] += a[i-1];
    for(int i=0;i<n;i++) F[a[i]]++;

    for(ll p=1;p<T;p*=k){
        if(seen.count(p)) break;
        ans += F[p];
        seen.insert(p);
    }

    for(int i=0;i<n;i++){
        F[a[i]]--;
        seen.clear();
        for(ll p=1;p<T;p*=k){
            if(seen.count(p)) break;
            ans += F[a[i] + p];
            seen.insert(p);
        }
    }

    cout << ans << endl;
}
