#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

const int N = 2e6;

int n, a[N], s[N], mk[N], tot, r;
int ans[2], ok;
int ad[N];
int to[N<<1], nx[N<<1], es = 1;

int dfs(int i){
    mk[i] = 1;
    s[i] = a[i];
    for(int e=ad[i];e;e=nx[e])
        if(!mk[to[e]]) s[i] += dfs(to[e]);
    return s[i];
}

int dis(int i){
    mk[i] = 1;
    int loc = -1;
    for(int e=ad[i];e;e=nx[e])
        if(!mk[to[e]]) {
            int j = dis(to[e]);
            if(j != -1){
                if(loc != -1 && !ok) {
                    ans[0] = loc;
                    ans[1] = j;
                    ok = 1;
                }
                loc = j;
            }
        }
    if(loc == -1 && s[i] == tot) loc = i;
    return loc;
}

int nes(int i, int g){
    mk[i] = 1;
    int loc = -1;
    if(s[i] == g*tot) g--;
    if(g == 0) return i;

    for(int e=ad[i];e;e=nx[e])
        if(!mk[to[e]]){
            int j = nes(to[e], g);
            if(j != -1) {
                if(g == 1 && s[i] == 2*tot){
                    ans[0] = j;
                    ans[1] = i;
                    ok = 1;
                }
                loc = j;
            }
        }

    return loc;
}

int main(){
    scanf(" %d", &n);
    for(int i=0;i<n;i++){
        int j; scanf(" %d %d", &j, a+i); --j;
        tot += a[i];
        if(j == -1) r = i;
        else {
            to[es] = i; nx[es] = ad[j]; ad[j] = es++;
            to[es] = j; nx[es] = ad[i]; ad[i] = es++;
        }
    }
    if(tot%3 != 0){
        puts("-1");
        return 0;
    }
    tot /= 3;
    dfs(r);

    ok = 0; for(int i=0;i<n;i++) mk[i] = 0;
    dis(r);
    if(ok){
        printf("%d %d\n", 1+ans[0], 1+ans[1]);
        return 0;
    }

    ok = 0; for(int i=0;i<n;i++) mk[i] = 0;
    nes(r,3);
    if(ok){
        printf("%d %d\n", 1+ans[0], 1+ans[1]);
        return 0;
    }
    puts("-1");
}
