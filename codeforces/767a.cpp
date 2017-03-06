#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

int n, lst;
set<int> a;

int main(){
    scanf(" %d", &n);
    lst = n+1;
    for(int l=0;l<n;l++){
        int in; scanf(" %d", &in);
        a.insert(in);
        while(a.count(lst-1)){
            lst = *a.rbegin();
            printf("%d ", lst);
            a.erase(lst);
        }
        putchar('\n');
    }
}
