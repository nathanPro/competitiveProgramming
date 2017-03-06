#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;

int n;
ull k;

ull solve(int n, ull k){
    ull siz = (1ull<<n),
        mid = (siz>>1ull);
    if(k == mid) return n;
    if(k  < mid) return solve(n-1, k);
    else         return solve(n-1, k-mid);
}

int main(){
    cin >> n >> k;
    cout << solve(n, k) << endl;
}
