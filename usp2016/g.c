#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "ctype.h"
#define debug(format, ...)\
    fprintf(stderr, "(%s at line %u)" format, __func__,  __LINE__, __VA_ARGS__)
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) < (b) ? (b) : (a))

#define Q 100007

int to[Q], nx[Q];
int ad[Q], es;

int ans[Q], x[Q], out[Q], os;
char type[Q];

void dfs(int i){
    static int q[Q], seen[Q], qf, qb;

    if(seen[i]) return;
    seen[i] = 1;

    ans[i] = q[qf];
    if(type[i] == 'E')
        q[qb++] = x[i];
    else if(qf < qb) qf++;

    for(int e = ad[i]; e; e = nx[e])
        dfs(to[e]);

    if(type[i] == 'E') qb--;
    else qf--;
}

int main(){
    int q;
    scanf(" %d", &q);

    es = 1; // So that 0 is the end
    // for(int i=0;i<=q;i++) ad[i] = 0;

    type[0] = 'D';
    for(int k=1;k<=q;k++){
        char c;
        int i, _x;
        scanf(" %c%d", &c, &i);
        type[k] = c;

        to[es] = k;
        nx[es] = ad[i];
        ad[i] = es++;

        if(c == 'E'){
            scanf(" %d", &_x);
            x[k] = _x;
        } else out[os++] = k;
    }
    for(int i=0;i<q;i++) dfs(i);
    for(int i=0;i<os;i++)
        printf("%d\n", ans[out[i]]);
}
