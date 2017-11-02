#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
using namespace std;
using ll = int64_t;

const int N = 2e5;
const int M = (N<<2);

int T;
int n, k, x, m, s;
int ad[N];
int to[M], nx[M], es;

int q;
ll d[2][N], w[M], oo;

inline void con(int i, int j, ll w) {
    ::w[es] = w; to[es] = j; nx[es] = ad[i]; ad[i] = es++;
}

void djs(int t, int s){
    for(int i=0;i<n;i++) d[t][i] = oo;
    set<pair<ll,int>> reach;
    if(t == 0) reach.insert(mp(d[t][s] = 0, s));
    else if(t == 1) {
        for(int i=0;i<k;i++) reach.insert(mp(d[t][i] = 0, i));
    }
    while(!reach.empty()){
        int i = reach.begin()->second;
        reach.erase(reach.begin());
        for(int e=ad[i];e;e=nx[e])
            if(d[t][i] + w[e] < d[t][to[e]]){
                if(d[t][to[e]] < oo)
                    reach.erase(mp(d[t][to[e]], to[e]));
                reach.insert(mp(d[t][to[e]] = d[t][i] + w[e], to[e])); 
            }
    }
}

int main(){
    scanf(" %d", &T);
    while(T--){
        scanf(" %d%d%d%d%d", &n, &k, &x, &m, &s);
        for(int i=0;i<n;i++) ad[i] = 0;
        --s;
        oo = ll(n<<1)*ll(1e9);
        es = 1;

        while(m--){
            ll _w; int i, j; scanf(" %d%d%lld", &i, &j, &_w); --i; --j;
            if(j < i) swap(i, j);
            con(i, j, _w);
            con(j, i, _w);
        }

        djs(0, s);
        djs(1, s);
        ll mc = oo;
        for(int i=0;i<k;i++) mc = min(mc, d[0][i]);
        for(int i=0;i<n;i++) printf("%lld%c", min(d[0][i], mc + ll(x) + d[1][i]), " \n"[i+1==n]);
    }
}
