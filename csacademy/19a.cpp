#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

const int N = 2e5;
ll n, a[N];

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=1;i<n;i++) a[i] += a[i-1];

    ll ans = abs(a[n-1]-ll(2)*a[0]);
    for(int i=1;i<n-1;i++)
        ans = min(ans, abs(a[n-1]-ll(2)*a[i]));
    cout << ans << endl;
}
