#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

const int S = 2e5;

int T;
int n;
vector<int> blks;
char in[S];

int main(){
    scanf(" %d", &T);
    while(T--){
        ll ans = 0;
        scanf(" %s", in); n = 0; blks.clear();
        for(int i=0;in[i];i++,n++);
        int cnt = 0;
        for(int i=n-1;i+1;i--)
            if(in[i] == '0') cnt++;
            else ans += ll(cnt);

        int sz=0;
        for(int i=0;i<n;i++)
            if(in[i] == '0' && 0 < sz){
                blks.push_back(sz);
                sz = 0;
            } else sz += (in[i] == '1');

        ll tot = 0;
        for(int x: blks){
            tot += ll(x);
            ans += tot;
        }

        printf("%lld\n", ans);
    }
}
