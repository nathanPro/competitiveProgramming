#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
using ull = uint64_t;
using z_t = size_t;

const int oo = INT_MAX;

int n, c[3][6], f[3];

int solve(int k){
    int ok = 0;
    if (k == 0) return 1;
    for (int i = 0; i < 3; i++){
        if (f[i] == 0) continue;
        if (binary_search(c[i], c[i] + 6, k%10)){
            f[i] = 0;
            ok |= solve(k/10);
            f[i] = 1;
            if (ok) return 1;
        }
    }
    return 0;
}

int main(){
    scanf(" %d", &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 6; j++)
            scanf(" %d", &c[i][j]);
        sort(c[i], c[i] + 6);
    }
    int k;
    f[0] = f[1] = f[2] = 1;
    for (k = 1; k < 1000; k++){
        if(!solve (k)) break;
    }
    printf("%d\n", k - 1);
}
