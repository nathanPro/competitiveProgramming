#include "stdio.h"
#include "math.h"
#include "math.h"
#include "stdlib.h"
#include "stdint.h"
#include "ctype.h"
#define debug(format, ...)\
    fprintf(stderr, "[(%s at line %u): " format "]\n", __func__,  __LINE__, __VA_ARGS__)
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) < (b) ? (b) : (a))
#define add(lst,x,cnt) { int _I = ++cnt; nx[_I] = lst; to[_I] = x; lst=_I; }

#define eps (1e-8)

int R;
int ans;
main(){
    int i;
    scanf(" %d", &R);
    for(i=0;i<3;i++){
        int x, y, r;
        scanf(" %d%d", &x, &y);

        for(r=0; r*r <= x*x + y*y ;r += R)
            ;

        r -= R;
        ans += (r*r == x*x + y*y && r);
        ans += max(0, 10-r/R);

        debug("%d", r);
        debug("%d", ans);
    }
    printf("%d\n", ans);
}
