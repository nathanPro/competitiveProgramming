#include "stdio.h"
#include "stdlib.h"
#include "inttypes.h"
#include "ctype.h"
#define debug(format, ...)\
    fprintf(stderr, "(%s at line %u)\t" format, __func__,  __LINE__, __VA_ARGS__)
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) < (b) ? (b) : (a))

#define N 100003

int icmp(const void * i, const void * j)
{ return *(int *)i - *(int *)j; }

int n, ans, a[N], seen[N], ss;
int64_t k, r, f[N];

int * uniq(int * b, int * e){
    int * p = b+1;
    for(b++; b != e; b++)
        if(*b != *(p-1))
            *p++ = *b;
    return p;
}

int idx(int x){
    return (int*)bsearch(&x, seen, ss, sizeof(int), icmp) - seen;
}

int64_t pairs(int64_t x){ return x*(x - (int64_t)1)>>1; } 

int si, sj;
void solve(uint64_t k, uint64_t r, int i, int j){
    if(j == ss) return solve(k, r, 1 + i, 1 + i);
    uint64_t cnt = f[i] * f[j], _r = 0;
    if(i == j) cnt = pairs(f[i]), _r = f[i];

    if(k < cnt) {
        si = i, sj = j;
        return;
    }
    return solve(k - cnt, r - _r, i, 1 + j);
}

int main(){
    scanf(" %d %" SCNd64, &n, &k); --k;
    for(int i = 0; i < n; i++) {
        scanf(" %d", a+i);
        seen[ss++] = a[i];
    }
    qsort(seen, ss, sizeof(int), icmp);
    ss = uniq(seen, seen + ss) - seen;
    for(int i=0; i<n; i++) f[idx(a[i])]++;

    if(!k){
        qsort(a, n, sizeof(int), icmp);
        printf("%d\n", a[0] + a[1]);
        return 0;
    }

    solve(k, n, 0, 0);

    printf("%d\n", seen[si] + seen[sj]);
}
