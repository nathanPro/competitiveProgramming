#include <bits/stdc++.h>
using namespace std;
using Zi = complex<int>;

int T;
const int N = 600;

int n;
int _g[2][N], _d[2][N], _seen[2][N];
Zi D[] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int & grid(Zi a){ return _g[imag(a)][real(a)]; }
int & d(Zi a){ return _d[imag(a)][real(a)]; }
int & seen(Zi a){ return _seen[imag(a)][real(a)]; }
int val(Zi a){ return 0 <= real(a) && real(a) < n
                   && 0 <= imag(a) && imag(a) < 2; }

int dfs(Zi z){
    seen(z) = 1;
    for(auto e: D)
        if(val(z+e) && grid(z+e) && !seen(z+e))
            dfs(z+e);
}

int main(){
    scanf(" %d", &T);
    while(T--){
        Zi s;
        scanf(" %d", &n);
        for(int j=0;j<2;j++)
            for(int i=0;i<n;i++){
                char _c;
                scanf(" %c", &_c);
                if(grid({i,j}) = (_c == '#')) s = {i,j};
                d({i,j}) = seen({i,j}) = 0;
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<2;j++){
                Zi z = {i,j};
                if(!grid(z)) continue;
                for(auto e: D)
                    d(z) += (val(z + e) && grid(z + e));
            }
        dfs(s);
        for(int j=0;j<2;j++)
            for(int i=0;i<n;i++)
                printf("[%d]%c", d({i,j}), " \n"[i+1==n]);
        for(int j=0;j<2;j++)
            for(int i=0;i<n;i++)
                printf("[%d]%c", seen({i,j}), " \n"[i+1==n]);


        int ok = 1, odd = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<2;j++)
                if(grid({i,j})) {
                    ok &= seen({i,j});
                    odd += (d({i,j})%2);
                }
        ok &= (odd == 2) || (odd == 0);
        if(ok) puts("yes");
        else   puts("no");
    }
}
