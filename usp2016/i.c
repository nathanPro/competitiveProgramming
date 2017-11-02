#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "ctype.h"
#define debug(format, ...)\
    fprintf(stderr, "(%s at line %u)\t" format, __func__,  __LINE__, __VA_ARGS__)
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) < (b) ? (b) : (a))

#define N 10007
#define M 1000004

int n, m;
int ad[N];
int to[M], nx[M], es=2;
char used[M];

int dfs(int i, int e_a){
    static int seen[N]; seen[i] = 1;
    int lst = 0, ne;
    for(int e = ad[i]; e; e = nx[e]){
        if((1^e) == e_a || used[e]) continue;
        ne = 0;
        if(seen[to[e]] || dfs(to[e], e)) ne = e;
        if(!lst) lst = ne;
        else if (ne){
            used[lst] = used[lst^1] = 1;
            used[ne] = used[ne^1] = 1;
            printf("%d %d %d\n", to[lst], i, to[ne]);
            lst = 0;
        }
    }
    if(lst) {
        used[lst] = used[lst^1] = 1;
        used[e_a] = used[e_a^1] = 1;
        printf("%d %d %d\n", to[lst], i, to[e_a^1]);
        return 0;
    }
    return 1;
}

int main(){
    scanf(" %d%d", &n, &m);
    printf("%d\n", m >> 1);
    while(m--){
        int i, j; scanf(" %d%d", &i, &j);
        to[es] = j; nx[es] = ad[i]; ad[i] = es++;
        to[es] = i; nx[es] = ad[j]; ad[j] = es++;
    }
    dfs(1, 0);
}
