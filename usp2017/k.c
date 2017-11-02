#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "ctype.h"
#define debug(format, ...)\
    fprintf(stderr, "(%s at line %u)\t" format, __func__,  __LINE__, __VA_ARGS__)
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) < (b) ? (b) : (a))

#define add(lst,x,cnt) { int _I = ++cnt; nx[_I] = lst; to[_I] = x; lst=_I; }

int main(){
    int k;
    uint32_t a;

    scanf(" %d", &k);
    a = (1<<(++k));

    printf("%u\n", --a);
}
