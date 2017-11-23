#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
using ull = uint64_t;

const int N = 2e6;
const int oo = INT_MAX;

int a[N], b[N];
int n, m;
ll tot;

int main(){
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", a + i);
        tot += a[i];
    }
    for (int i = 0; i < n; i++) {
        scanf (" %d", b + i);
    }
    sort (b, b + n);
    reverse (b, b + n);
    if (ll(b[0] + b[1]) >= tot) puts("YES");
    else puts("NO");
}
