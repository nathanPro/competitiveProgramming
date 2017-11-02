#include "bits/stdc++.h"
#define mt make_tuple
using namespace std;

const int N = 1e6;
const int K = 1e7;

int cnt;
int n, x[N], y[N];
int seen[K];

int main(){
    scanf (" %d", &n);
    for (int i = 0; i < n; i++){
        scanf (" %d", x + i);
        seen[x[i]] = 1;
    }
    for (int i = 0; i < n; i++){
        scanf (" %d", y + i);
        seen[y[i]] = 1;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cnt += seen[x[i]^y[j]];

    if (cnt&1) printf("Koyomi\n");
    else       printf("Karen\n");
}
