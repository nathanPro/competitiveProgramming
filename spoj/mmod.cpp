#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
const int P = 29;

int x;
inline int fexp(int a, int e){
    int t = 1;
    for(;e;e>>=1,a=(a*a)%P)
        if(e&1) t = (t*a)%P;
    return t;
}
int sum(ll a, ll e){
    ll ans = (fexp(a,e+1) + P-1)%P;
    return (ans*fexp(a-1,P-2))%P;
}

int main(){
    while(scanf(" %d", &x) != EOF && x){
        int ans = (sum(2, 2*x)*sum(3, x)*sum(167, x))%P;
        printf("%d\n", ans);
    }
}
