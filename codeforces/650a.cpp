#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

const int N = 4e5;

int n, x[N], y[N];
int seen[N], ss;
int cnt[N];
int idx(int x){
    return lower_bound(seen, seen + ss, x) - seen; 
}
ll f(ll i){
    return (i * ll(i - 1))>>1;
}

void solve(int * a){
    ss = 0;
    for (int i = 0; i < n; i++) seen[ss++] = a[i];
    sort(seen, seen + ss);
    ss = unique(seen, seen + ss) - seen;
    for (int i = 0; i < 2*n; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++)
        cnt[idx(a[i])]++;
}

int main()
{
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %d%d", x + i, y + i);

    ll ans = 0;
    solve(x);
    for (int i = 0; i < 2*n; i++) ans += f(cnt[i]);

    solve(y);
    for (int i = 0; i < 2*n; i++) ans += f(cnt[i]);

    map<pair<int, int>, int> F;
    for (int i = 0; i < n; i++) F[make_pair(x[i], y[i])]++;
    for (auto it: F)
        ans -= f(it.second);
    printf("%" PRId64 "\n", ans);
}
