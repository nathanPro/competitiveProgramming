#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

const int N = 2e5;

int n, k, c[N];

int main(){
    scanf(" %d", &n);
    for(ll i=2;i<N;i++)
        if(!c[i]){
            for(ll j=i*i;j<N;j+=i)
                c[j] |= 1;
        }
    printf("%d\n", 1 + (2 < n));
    for(int i=2;i<n+2;i++) printf("%d%c", 1+c[i], " \n"[i==n+1]);
}
