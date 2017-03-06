#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

const int N = 1e5;
const int M = (N<<1);

int n, P[N], T;

int p[N];
set<int> ad[N];

int main(){
    scanf(" %d", &T);
    while(T--){
        scanf(" %d", &n);
        for(int i=0;i<n;i++) scanf(" %d", P+i), p[i] = i, ad[i].clear();
        sort(p,p+n,[&](int i, int j){ return P[j] < P[i]; });
        for(int k=0;k<n-1;k++){
            int i,j; scanf(" %d%d", &i, &j); --i; --j;
            ad[i].insert(j); ad[j].insert(i);
        }

        for(int i=0;i<n;i++){
            int ans = -1;
            for(int j=0;ans < 0 && j<n;j++)
                if(p[j] != i && ad[i].count(p[j]) == 0)
                    ans = p[j];
            printf("%d ", ++ans);
        }
        puts("");
    }
}
