#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "ctype.h"
#define debug(format, ...)\
    fprintf(stderr, "(%s at line %u)\t" format, __func__,  __LINE__, __VA_ARGS__)
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) < (b) ? (b) : (a))

#define add(lst,x,cnt) { int _I = ++cnt; nx[_I] = lst; to[_I] = x; lst=_I; }

#define N 1000003
#define M 103
#define K 21

int n, m, max_k;
char p[M], s[N];

int main(){
    register int i, j;
    scanf(" %d%d%d", &m, &n, &max_k);

    scanf(" %s", p);
    scanf(" %s", s);

    for(i=m;i+1;i--)
        for(j=n;j+1;j--)
            S[i&1][j] = solve(i, j);

    if(S[0][0] <= max_k) puts("S");
    else                 puts("N");
}
