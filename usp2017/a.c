#include "stdio.h"
#define debug(format, ...)\
    fprintf(stderr, "(%s at line %u)\t" format, __func__,  __LINE__, __VA_ARGS__)

#define N (50007)
#define M (1000007)
#define add(lst,x,cnt) { int _I = ++cnt; nx[_I] = lst; to[_I] = x; lst=_I; }

int n, m, k;
int ad[N], c[N], seen[N];
int to[M], nx[M], es;

void dfs(int i, int _c){
    int e;
    seen[i] = 1;
    c[i] = _c;
    for(e=ad[i];e;e=nx[e])
        if(!seen[to[e]])
            dfs(to[e], (c[i] + 1)%k);
}

int main() {
    int i;
    scanf(" %d%d%d", &n, &m, &k);
    if(k == 1){
        if(m) puts("-1");
        else {
            for(i=0;i<n;i++)
                puts("1");
        }
        return 0;
    }
    while(m--){
        int i, j, e;
        scanf(" %d%d", &i, &j);
        --i; --j;
        add(ad[i], j, es);
        add(ad[j], i, es);
    }
    for(i=0;i<n;i++)
        if(!seen[i])
            dfs(i, 0);
    for(i=0;i<n;i++)
        printf("%d\n", 1 + c[i]);
}
