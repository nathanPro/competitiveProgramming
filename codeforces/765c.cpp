#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

ll sa, sb, a, b, k;

int main(){
    ios::sync_with_stdio(false);
    cin >> k >> a >> b;
    sa = a/k; sb = b/k;
    a %= k; b %= k;

    a = max(a-(k - ll(1))*sb, ll(0));
    b = max(b-(k - ll(1))*sa, ll(0));

    if(max(a,b) == 0) cout << sa + sb << endl;
    else cout << "-1\n";
}
