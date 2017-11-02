#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "ctype.h"
#define debug(format, ...)\
    fprintf(stderr, "(%s at line %u)\t" format, __func__,  __LINE__, __VA_ARGS__)

#define min(a,b) ((a) < (b) ? (a) : (b))
#define N 100005

typedef int64_t ll;

compare(const void * i, const void * j){ return (*(int *)i - *(int*)j); }

int n;
int x[N];
ll S[N];

read_uint(){
    char c;
    register int ans = 0;
    for(;isspace(c=getchar()););
    ans = c - '0';
    for(;isdigit(c=getchar());)
        ans = (ans<<3) + (ans<<1) + c - '0';
    return ans;
}

main(){
    register int i;

    n = read_uint();
    for(i=0;i<n;i++)
        x[i] = read_uint();
    qsort((void *)x, n, sizeof(int), compare);

    S[0] = x[0];
    S[1] = x[1];
    for(i=2;i<n;i++){
        S[i] = S[i-1] + (ll)x[i] + (ll)x[0];
        if(2 < i)
            S[i] = min(S[i], S[i-2] + (ll)x[i] + (ll)x[0] + (ll)(2*x[1]));
    }
    
    for(i=0;i<n;i++) debug("%lld%c", S[i], " \n"[i+1==n]);

    printf("%lld\n", S[n-1]);
}
