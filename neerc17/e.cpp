#include "bits/stdc++.h"
using namespace std;

const int N = 100;
const int Z = CHAR_MAX;

int n, m, f[Z], a[Z];
char s[N];
set<int> P[Z];

int main(){
    for (char c = 'a'; c < 'z' + 1; c++) a[c] = 1;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++){
        char in;
        scanf(" %c", &in);
        a[in] = 0;
        P[in].insert(i);
    }
    scanf(" %d", &m);
    while (m--){
        scanf(" %s", s);
        for (int i = 0; i < Z; i++) f[i] = 0;
        for (char * c = s; *c; c++) f[*c]++;
        int ok = 1;
        for (char c = 'a'; c < 'z' + 1; c++){
            for (auto i : P[c])
                if (s[i] == c) f[c]--;
                else ok = 0;
            if (!P[c].empty()) ok &= (f[c] == 0);
        }
        if (!ok) continue;
        for (char c = 'a'; c < 'z' + 1; c++) a[c] &= (f[c] > 0);
    }
    int ans = 0;
    for (int c = 'a'; c < 'z' + 1; c++) ans += a[c];
    printf("%d\n", ans);
}
