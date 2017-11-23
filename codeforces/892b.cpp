#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
using ull = uint64_t;

const int N = 2e6;
const int oo = INT_MAX;

int n, reach;
int l[N], dead[N];

int main(){
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) scanf(" %d", l + i);
    int i = n - 1;
    reach = n;
    for (; 0 <= i; i--){
        dead[i] = reach <= i;
        reach = min(reach, i - l[i]);
    }
    int cnt = n;
    for (int i = 0; i < n; i++)
        cnt -= dead[i];
    printf("%d\n", cnt);
}
