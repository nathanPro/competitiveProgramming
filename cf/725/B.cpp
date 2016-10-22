#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;

ll n, ans;
int i;
char s, in[500], ord[] = "fedabc";

int main(){
    scanf(" %s", in);
    for(i=0;'0' <= in[i] && in[i] <= '9';i++);
    s = in[i];
    in[i] = 0;
    sscanf(in, " %lld", &n); n--;
    ans = ll(16)*(n/ll(4)) + ll(7)*ll(n&ll(1)) + ll(find(ord,ord+6,s) - ord); ans++;
    printf("%lld\n", ans);
}
