#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

const int N = 2e5 + 5;

int n, ans, q[N], qf, qb;
set<int> adj[N], child[N];
int mk[N];

int main(){
    scanf(" %d", &n);
    for(int k=0;k<n-1;k++){
        int i, j;
        scanf(" %d%d", &i, &j); --i; --j;
        adj[i].insert(j); adj[j].insert(i);
    }
    for(int i=0;i<n;i++)
        if(adj[i].size() == 1)
            child[q[qb++] = i].insert(0);

    int i;
    while(qf < qb){
        i  = q[qf++];
        int j  = *adj[i].begin(),
            _k = child[i].size();

        if(_k != 1) continue;
        if(adj[i].empty()) continue;

        mk[i] = 1;
        child[j].insert(1 + *child[i].begin());
        adj[j].erase(i);

        if(adj[j].size() == 1) q[qb++] = j;
    }
    qf = 0; for(int j=0;j<n;j++) qf += mk[j];
    if(1 + qf < n) puts("-1");
    else{
        if(1 + qf == n){
            for(i = 0;i<n;i++)
                if(!mk[i]) break;
        }

        if(2 < child[i].size()) puts("-1");
        else {
            for(auto x: child[i]) ans += x;
            while(!(1&ans)) ans >>= 1;
            printf("%d\n", ans);
        }
    }
}
