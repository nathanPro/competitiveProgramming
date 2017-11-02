#include <bits/stdc++.h>
using namespace std;

int T;
int main(){
    scanf(" %d", &T);
    while(T--){
        int n, m;
        scanf(" %d%d", &n, &m);
        n -= 2*m;
        while(m--) scanf(" %*d%*d");
        if(n%2 == 0) puts("yes");
        else         puts("no");
    }
}
