#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef uint32_t unt;

const int N = 314;

char in[N];
int T, n, m, x, y;

set<ll> S[2][N];
ll ans;

inline ll _d(char c) { return c - '0'; }
ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a; }

int main(){
    assert(!gcd(0,0));
    scanf(" %d", &T);
    while(T--){
        scanf(" %d %s %d %d %d", &n, in, &m, &x, &y);
        for(int i=n;i+1;i--) {
            S[0][i].clear();
            if(i == n) continue;
            if(m < n-i) continue;
            ll d = 0;
            for(int j=i;j<n;j++) d = ll(10)*d + _d(in[j]);
            S[0][i].insert(d);
        }
        ans = 1;
        for(int b=1;b<=y;b++){
            int c = (1^b);
            for(int i=n-1;i+1;i--){
                S[1&b][i].clear();
                ll d = _d(in[i]);
                for(int j=i+1;j<=n;j++) {
                    if(m < j-i) break;
                    for(auto f: S[1&c][j]) S[1&b][i].insert(gcd(d,f));
                    d = ll(10)*d + _d(in[j]);
                }
            }
            if(x <= b && !S[1&b][0].empty())
                ans = max(ans, *(S[1&b][0].rbegin()));
        }
        cout << ans << endl;
    }
}
