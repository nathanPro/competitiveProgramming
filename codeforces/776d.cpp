#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

const int N = 2e5;
const int V = (N<<2);
const int E = (N<<3);

int n, m;
int ps, ss, cs;
int ad[V], mk[V], S[V], C[V], st[V];
int to[E], nx[E], es=1;
int r[N];
vector<int> sw[N];

void insert(int i, int j){ to[es] = j; nx[es] = ad[i]; ad[i] = es++; }
int vx(int i, int b){ return ((i<<1)|b); }
void either(int a, int b){
    insert(1^a,b);
    insert(1^b,a);
}
int dfs(int i){
    S[i] = mk[i] = ++ps;
    st[ss++] = i;
    for(int e=ad[i];e;e=nx[e])
        if(!mk[to[e]]) S[i] = min(S[i], dfs(to[e]));
        else if(!C[to[e]]) S[i] = min(S[i], mk[to[e]]);

    if(S[i] == mk[i]) {
        C[i] = ++cs;
        while(st[ss-1] != i)
            C[st[--ss]] = C[i];
        --ss;
    }
    return S[i];
}

int main(){
    scanf(" %d%d", &n, &m);
    for(int i=0;i<n;i++)
        scanf(" %d", r+i);
    for(int i=0;i<m;i++){
        int x;
        scanf(" %d", &x);
        while(x--){
            int j; scanf(" %d", &j); --j;
            sw[j].push_back(i);
        }
    }
    for(int k=0;k<n;k++){
        int a = vx(sw[k][0],1), b = vx(sw[k][1],1);
        if(r[k]) {
            either(1^a,b);
            either(1^b,a);
        } else {
            either(a,b);
            either(1^a,1^b);
        }
    } 
    for(int i=0;i<m;i++)
        for(int b=0;b<2;b++)
            if(!mk[vx(i,b)])
                dfs(vx(i,b));
    int ok = 1;
    for(int i=0;i<m;i++) ok &= (C[vx(i,0)] != C[vx(i,1)]);
    if(ok) puts("YES");
    else   puts("NO");
}
