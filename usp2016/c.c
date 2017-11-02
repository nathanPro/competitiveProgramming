#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "ctype.h"
#define debug(format, ...)\
    fprintf(stderr, "(%s at line %u)\t" format, __func__,  __LINE__, __VA_ARGS__)
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) < (b) ? (b) : (a))

#define H 100 ## 003

int ans, h, w;
int l[H], in;

int main(){
    scanf(" %d %d", &h, &w);
    ans = w;
    for(int i=0; i<h; i++)
        scanf(" %d", l+i);
    for(int i=0; i<h; i++){
        scanf(" %d", &in);
        ans = min(ans, w - l[i] - in);
    }
    printf((ans&1) ? "%.1f\n" : "%.0f\n", .5*ans);
}
