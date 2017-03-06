#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

const int N = 2e5;
const int M = (N<<1);

int n, m;
int ad[N], d[N], seen[N];
int to[M], nx[M], ans[M], used[M], es;

int dfs(int i){
    seen[i] = 1;
    while(ad[i]) {
        int e = ad[i]; ad[i] = nx[e];
        if(used[e]) continue;
        used[e] = used[e^1] = 1;
        ans[e|1] = (e&1);
        dfs(to[e]);
    }
}

int main(){
    es = 2;
    scanf(" %d%d", &n, &m);
    while(m--){
        int i, j;
        scanf(" %d%d", &i, &j);
        d[--i]++; d[--j]++;
        to[es] = j; nx[es] = ad[i]; ad[i] = es++;
        to[es] = i; nx[es] = ad[j]; ad[j] = es++;
    }
    int ok = 1;
    for(int i=0;i<n;i++) ok &= (d[i]%2 == 0);
    if(ok) dfs(0);
    for(int i=0;i<n;i++) ok &= seen[i];

    if(ok) {
        puts("YES");
        for(int e=3;e<es;e+=2){
            int i = to[e^1], j = to[e];
            if(ans[e]) swap(i,j);
            printf("%d %d\n", 1+i, 1+j);
        }
    } else puts("NO");
}
