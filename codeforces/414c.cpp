#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

const int D = 21;
const int N = (1<<D);

int n;
int a[N];

ll tot;
struct cnt {
    int status;
    ll x[2];
    cnt operator+(cnt b)
    {
        return {0, {x[0] + b.x[0], x[1] + b.x[1]}};
    }
} ans[D];

cnt merge (int *l, int *m, int *r)
{
    static int aux[N];
    cnt ans{0,0,0};
    int *i = l, *j = m, *os = aux + (l - a);
    while (i < m && j < r) {
        if (*i < *j) {
            *os++ = *i++;
            ans.x[1] += r - j;
        } else if (*i == *j) {
            int g = *i;
            ll eqr = 0, eql = 0;
            while (j < r && g == *j) eqr++, *os++ = *j++;
            while (i < m && g == *i) eql++, *os++ = *i++;
            ans = ans + cnt{0, ll(m - i) * eqr, ll(r - j) * eql};
        } else {
            *os++ = *j++;
            ans.x[0] += m - i;
        }
    }
    while (i < m) *os++ = *i++;
    while (j < r) *os++ = *j++;
    i = l, os = aux + (l - a);
    while (i < r) *i++ = *os++;
    return ans;
}

int main()
{
    scanf(" %d", &n);
    for (int i = 0; i < (1<<n); i++)
        scanf(" %d", a + i);

    for (int d = n; 0 < d; d--) {
        int l = (1<<(n - d));
        for (int i = 0; i < (1<<n); i += (l<<1))
            ans[d - 1] = ans[d - 1] + merge(a + i, a + i + l, a + i + (l<<1));
        tot += ans[d - 1].x[0];
    }

    int m, q;
    scanf(" %d", &m);
    while (m--) {
        scanf(" %d", &q);
        for (int d = n - q; d <= n; d++) {
            tot -= ans[d].x[ans[d].status];
            ans[d].status ^= 1;
            tot += ans[d].x[ans[d].status];
        }
        printf("%" PRId64 "\n", tot);
    }
}
