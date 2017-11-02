#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;

int T;
int n, k;
int F[N];
set<int> I[N];

int main(){
    scanf(" %d", &T);
    while(T--){
        scanf(" %d%d", &n, &k);
        for(int i=0;i<k;i++) F[i] = 0;
        for(int i=0;i<n;i++) I[i].clear();

        for(int i=0;i<n;i++){
            int p, in;
            scanf(" %d", &p);
            while(p--){
                scanf(" %d", &in);
                I[i].insert(--in);
            }
        }
        for(int i=0;i<n;i++)
            for(auto x : I[i])
                F[x]++;

        if(*min_element(F,F+k) == 0) puts("sad");
        else {
            int skip = 0;
            for(int i=0;i<n;i++){
                int loc = 1;
                for(auto x : I[i])
                    loc &= (1 < F[x]);
                skip |= loc;
            }
            if(skip) puts("some");
            else     puts("all");
        }
    }
}
