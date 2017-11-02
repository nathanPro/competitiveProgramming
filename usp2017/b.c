#include "stdio.h"
#include "stdint.h"
#define N 1000007

typedef int64_t ll;

char ans[N];
int n;
ll tot, aux;

main(){
    int i;
    scanf(" %d", &n);
    tot = ((ll) n)*((ll) 1 + n);
    tot >>= 1;

    if(tot&1){
        puts("-1");
        return 0;
    }
    tot >>= 1;

    for(i=n;i;i--)
        if(aux + ((ll)i) <= tot){
            ans[i] = '+';
            aux += i;
        } else break;
    if(aux < tot)
        ans[tot-aux] = '+';

    for(i=1;i<=n;i++)
        if(!ans[i]) putchar('-');
        else        putchar(ans[i]);

    return 0;
}
