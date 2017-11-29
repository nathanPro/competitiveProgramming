#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

const int N = 2e6;

int n, a[N];
struct sol{
    ll s, x;
} sb[N], *st = sb;
ll S[N];

int sgn (int x){
    return (x > 0) - (x < 0);
}

int opt(int i){
    if (i == 0 || i == n - 1) return 0;
    int l = min(a[i - 1], a[i + 1]),
        u = max(a[i - 1], a[i + 1]);
    if (l == u) return a[i] != l;
    return u <= a[i] || a[i] <= l;
}

int main()
{
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %d", a + i);
    S[0] = 0;
    *st++ = {0, a[0]};
    for (int i = 1; i < n; i++){
        S[i] = S[i - 1];
        sol * c = st;
        for (int j = 0; j < 6; j++){
            if (c == sb) break;
            sol loc = *--c;
            S[i] = max(S[i], abs(loc.x - ll(a[i])) + loc.s);
        }
        if (opt(i)){
            *st++ = {S[i - 1], a[i]};
            *st++ = {S[i], a[i + 1]};
        }
    }
    printf("%" PRId64 "\n", S[n - 1]);
}
