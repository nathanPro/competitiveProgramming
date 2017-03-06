#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

const int N = 2e3;

int n, ans;
char s[N], m[N];
map<char, int> F;

int main(){
    scanf(" %d %s %s", &n, s, m);
    sort(s, s+n);

    for(int i=0;i<n;i++) F[m[i]]++;
    for(int i=0;i<n;i++) {
        auto it = F.lower_bound(s[i]);
        if(it == F.end()) it = F.begin();
        while(it->second == 0) ++it;
        ans += (it->first < s[i]);
        F[it->first]--;
    }
    printf("%d\n", ans);

    ans = 0;
    for(int i=0;i<n;i++) F[m[i]]++;
    for(int i=0;i<n;i++) {
        auto it = F.upper_bound(s[i]);
        if(it == F.end()) it = F.begin();
        while(it->second == 0) ++it;
        ans += (s[i] < it->first);
        F[it->first]--;
    }
    printf("%d\n", ans);
}
