#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;
using factor = vector<ll>;

const int N = 2e5;
const ll R = (1e6+1);

ll a,b;
ull ans;
char cmp[R];
factor _S[N];
int fs; ll f[N];

inline factor& S(ll i){ return _S[i-a]; }

int main(){
    cin >> a >> b;
    for(ll p=2;p<R;p++) if(!cmp[p]){
        for(ll q = a-a%p;q<=b;q+=p)
            if(a <= q && q <= b) 
                S(q).push_back(p);
        for(ll q=p*p;q<R;q+=p)
            cmp[q] = 1;
    }
    for(ll i=max(ll(2),a);i<=b;i++){
        if(S(i).empty()) S(i).push_back(i);
        ll n = i;
        for(ll p: S(i)){
            for(;n%p==0;n/=p);
        }
        if(1 < n) S(i).push_back(n);
    }

    for(ll n=max(ll(2),a);n<=b;n++){
        ll loc = 0;
        fs = 0;
        for(ll p: S(n)){
            int cnt = -1;
            for(ll q=1;n%q == 0;q*=p) cnt++;
            f[fs++] = cnt;
        }
        iter_swap(f, max_element(f,f+fs));
        while(0 < f[0]){
            ll prod = 1;
            for(int i=0;i<fs;i++) prod *= (ll(1) + f[i]);
            loc += prod;
            f[0]--; iter_swap(f,max_element(f,f+fs));
        }
        ans += ull(loc);
    }
    cout << ans << endl;
}
