#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

const int N = 2e5;
int n, m, k;
vector<int> a[N];
int S[N];

void build(){
    for(int i=0;i<n;i++) S[i] = 1;
    for(int j=0;j<m;j++) a[n].push_back(INT_MAX);

    for(int j=0;j<m;j++){
        int cnt = 0, lst = 0;
        for(int i=0;i<=n;i++){
            int k = i+1;
            for(;k<n;k++)
                if(a[k-1][j] > a[k][j]) break;
            S[i] = max(S[i], k);
            int up = 0;
            while(i < k){
                i++;
                S[i] = max(S[i], k);
                up = 1;
            }
            if(up) i--;
        }
    }
}

int main(){
    scanf(" %d%d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int in; scanf(" %d", &in);
            a[i].push_back(in);
        }
    }
    build();
    scanf(" %d", &k);
    while(k--){
        int l, r; scanf(" %d%d", &l, &r); --l;
        if(r <= S[l]) puts("Yes");
        else          puts("No");
    }
}
