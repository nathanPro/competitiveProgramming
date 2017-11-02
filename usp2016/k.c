#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "ctype.h"
#define debug(format, ...)\
    fprintf(stderr, "(%s at line %u)\t" format, __func__,  __LINE__, __VA_ARGS__)
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) < (b) ? (b) : (a))

int n, d, cnt;
double ans;

int main(){
    scanf(" %d", &n);
    ans = 1;
    while(1 - ans <= .5){
        ans = ans * (1. - (double)cnt++/n);
    }
    printf("%d\n", cnt);
}
