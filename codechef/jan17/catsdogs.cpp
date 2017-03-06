#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

int T, c, d, l;

int main(){
    scanf(" %d", &T);
    while(T--){
        scanf(" %d%d%d", &c, &d, &l);
        int ok = 0, t;
        if(l%4 != 0) ok = 1, puts("no");
        l /= 4; t = l - d;
        if(!ok){
            if(0 <= t && 0 <= c-t && c-t <= 2*d)
                puts("yes");
            else puts("no");
        }
    }
}
