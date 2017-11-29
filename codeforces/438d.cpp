#include "bits/stdc++.h"
#define set PASSARINHO
using namespace std;
using ll = int64_t;

const int N = 1.5e5;

int n, m;
int a[N];

struct cell {
    int m;
    ll s;

    cell operator+ (cell b)
    {
        return cell{max(m, b.m), s + b.s};
    }
} tree[N<<1];

int dig(int i, int q)
{
    while (i < n)
        if (tree[i <<= 1].m < q) i++;
    return i - n;
}

int query (int l, int q)
{
    int r = n, i = -1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1){
        if (l&1){
            if (tree[l].m >= q) return dig(l, q);
            l++;
        }
        if (r&1){
            if (tree[--r].m >= q)
                i = r;
        }
    }
    if (i == -1) return n;
    return dig(i, q);
}

void set (int i, int x)
{
    for (tree[i += n] = {x, x}; 1 < i; i >>= 1)
        tree[i>>1] = tree[i] + tree[i^1];
}

void change(int l, int r, int a)
{
    for (int i = query(l, a); i < r; i = query(i, a))
        set(i, (tree[i + n].m)%a);
}

ll sum (int l, int r)
{
    ll ans = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1){
        if (l&1) ans += tree[l++].s;
        if (r&1) ans += tree[--r].s;
    }
    return ans;
}

int main()
{
    scanf(" %d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf(" %d", a + i);
    for (int i = 0; i < n; i++) tree[i + n] = {a[i], a[i]};
    for (int i = n - 1; i; i--) tree[i] = tree[i<<1] + tree[i<<1|1];

    while (m--){
        int t, l, r, x;
        scanf(" %d", &t);
        if (t == 1){
            scanf(" %d%d", &l, &r);
            printf("%" PRId64 "\n", sum(--l, r));
        }
        if (t == 2){
            scanf(" %d%d%d", &l, &r, &x);
            change (--l, r, x);
        }
        if (t == 3){
            scanf(" %d%d", &l, &x);
            set (--l, x);
        }
    }
}
