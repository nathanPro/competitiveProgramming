#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

const int P = 1e9 + 7;
const int N = 2e3;
const int L = 1.5e4;
const int Z = 2*L;

int n;
int a[N];

struct mod {
    int x;
    mod operator+ (const mod& rhs) { return mod{(ll(x) + ll(rhs.x))%P}; }
};

mod& F(int i, int s){
    static mod mem[N][Z];
    return mem[i][s + L];
}

mod f(int i, int s)
{
    if (i == 0) return mod{s == a[0] || s == -a[0]};
    F(i,s) = {0};
    if (s - a[i] > -L)
        F(i,s) = F(i,s) + F(i - 1, s - a[i]);
    if (s + a[i] <  L)
        F(i,s) = F(i,s) + F(i - 1, s + a[i]);
    return F(i,s);
}

int main(){
    mod ans{0};
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) scanf(" %d", a + i);
    for (int i = 0; i < n; i++) {
        for (int s = -L + 1; s < L; s++)
            F(i,s) = f(i,s);
        ans = ans + F(i, 0);
        F(i,0) = F(i,0) + mod{1};
    }
    printf("%d\n", ans.x);
}
