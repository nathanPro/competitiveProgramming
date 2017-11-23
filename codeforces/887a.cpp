#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
using ull = uint64_t;
using z_t = size_t;

const z_t N = 200;
const int oo = INT_MAX;

z_t n, m;
char s[N];

int main(){
    scanf(" %s", s);
    n = strlen(s);
    int cnt = 0, i;
    for (i = n - 1; cnt < 6 && i + 1; i--)
        cnt += (s[i] == '0');
    int ok = 0;
    for (; i + 1; i--) ok |= (s[i] == '1');

    if ((cnt == 6)&ok) puts("yes");
    else puts("no");
}
