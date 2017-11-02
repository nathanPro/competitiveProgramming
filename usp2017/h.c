#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "ctype.h"
#define debug(format, ...)\
    fprintf(stderr, "(%s at line %u)\t" format, __func__,  __LINE__, __VA_ARGS__)
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) < (b) ? (b) : (a))

#define add(lst,x,cnt) { int _I = ++cnt; nx[_I] = lst; to[_I] = x; lst=_I; }

enum dir {N,E,S,W};
int dx[] = {0,1,0,-1},
    dy[] = {1,0,-1,0};

struct move {
    char t;
    int s;
} ans[10];

char c;
int d, aux;
int as, x[2], y[2];

int parse(char c){
    if(c == 'N') return 0;
    if(c == 'E') return 1;
    if(c == 'S') return 2;
    if(c == 'O') return 3;
}

int sgn(int x){ return (x > 0) - (x < 0); }


int main(){
    int i;

    scanf(" %d%d %c%d%d", x, y, &c, x+1, y+1);

    for(d = parse(c); x[0] != x[1] || y[0] != y[1]; d = (1 + d)%4) {
        if(x[1] != x[0] && sgn(x[1] - x[0]) == dx[d]){
            ans[as].t = 'A';
            ans[as].s = dx[d]*(x[1] - x[0]);
            as++;
            x[0] = x[1];
        }

        if(y[1] != y[0] && sgn(y[1] - y[0]) == dy[d]) {
            ans[as].t = 'A';
            ans[as].s = dy[d]*(y[1] - y[0]);
            as++;
            y[0] = y[1];
        }

        if(x[0] != x[1] || y[0] != y[1])
            ans[as++].t = 'D';
    }

    printf("%d\n", as);
    for(i=0;i<as;i++){
        putchar(ans[i].t);
        if(ans[i].t == 'A') printf(" %d", ans[i].s);
        putchar('\n');
    }
}
