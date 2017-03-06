#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

int n, x;

int go(int i){
    int s[3];
    for(int j=0;j<3;j++) s[j] = 0;
    s[i] = 1;

    for(int j=0;j<n;j++)
        swap(s[1&j],s[(1&j)+1]);
    for(int j=0;j<3;j++) if(s[j]) return j;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> ws >> x;
    n %= 6;
    for(int i=0;i<3;i++)
        if(go(i) == x)
            printf("%d\n", i);
}
