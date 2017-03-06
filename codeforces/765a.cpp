#include <bits/stdc++.h>
// Todo mundo Null
using namespace std;
using ll = int64_t;
using ull = uint64_t;

const int S = 256;
int n, home;
char in[S], hm[S];

int main(){
    scanf(" %d %s", &n, hm);
    for(int i=0;i<n;i++){
        scanf(" %s", in);
        home = !strcmp(in+5, hm);
    }
    if(n%2 == 0) puts("home");
    else puts("contest");
}
