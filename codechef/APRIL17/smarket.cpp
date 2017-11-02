#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int T;
int n, q, a[N];
vector<int> S[N], fst;

int main(){
    scanf(" %d", &T);
    while(T--){
        scanf(" %d%d", &n, &q);
        for(int i=0;i<n;i++) scanf(" %d", a+i);
        fst.clear();
        for(int i=0;i<=n;i++) S[i].clear();
        for(int i=0;i<n;){
            int j = i+1;
            for(;j<n && a[i] == a[j];j++);
            for(int k=2;k<=j-i;k++) S[k].insert(i);
            fst.insert(i);
            i = j;
        }
        while(q--){
            int l, r, k;
            scanf(" %d%d%d", &l, &r, &k); l--;
            if(k == 1) printf("%d\n", r-l);
            else {
                int hi = upper_bound(begin(S[k]), end(S[k])) - begin(S[k]),
                    lo = lower_bound(begin(S[k]), end(S[k])) - begin(S[k]),
                    base = hi-lo;
                lo = lower_bound(begin(fst), end(fst), l) - begin(fst) - 1;
            }
        }
    }
}
