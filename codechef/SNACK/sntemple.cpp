#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

const int N = 2e5;

int n, T;
ll h[N], L[N], R[N], tot;
ll f(ll x){ return x*x; }

int main(){
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        ll tot = 0, ans = 0;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> h[i];
            tot += h[i];
        }

        L[0] = 1;
        for(int i=1;i<n;i++)
            L[i] = min(1 + L[i-1], h[i]);
        R[n-1] = 1;
        for(int i=n-2;i+1;i--)
            R[i] = min(1 + R[i+1], h[i]);

        ans = tot;
        for(int i=0;i<n;i++)
            ans = min(ans, tot - f(min(L[i], R[i])));
        cout << ans << endl;
    }
}
