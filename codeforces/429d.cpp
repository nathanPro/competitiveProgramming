#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
using ull = uint64_t;
using Zi = complex<ll>;

const int N = 2e6;
const int oo = INT_MAX;

int n;
ll tot;
Zi P[N];

ll d (int i, int j)
{
    auto d = P[i] - P[j];
    return real(d*conj(d));
}
bool y_leq(int i, int j)
{
    return imag(P[i]) < imag(P[j]);
}

int main()
{
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf(" %d", &a);
        tot += a;
        P[i] = {1 + i, tot};
    }
    ll ans = d(0, 1);
    {
        int i = 0, j = 0;
        set<int, bool(*)(int, int)> zn(y_leq);
        for (zn.insert(j++); j < n; zn.insert(j++)) {
            while(i < j && ans < real(P[j] - P[i]) * real(P[j] - P[i]))
                zn.erase(i++);
            auto m = zn.lower_bound(j);
            auto p = m;
            int cnt = 0;
            for (int k = 0; k < 6; k++)
                if (p == zn.end()) break;
                else ans = min(ans, d(*p++, j)), cnt++;

            p = m;
            for (int k = 0; k < 6; k++)
                if (p == zn.begin()) break;
                else ans = min(ans, d(*--p, j)), cnt++;
        }
    }
    printf("%" PRId64 "\n", ans);
}
