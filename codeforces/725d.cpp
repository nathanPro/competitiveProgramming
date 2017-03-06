#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;

const int N = 4e5;
int n, bst;
ll t[N], w[N];

struct t_cmp {
    bool operator()(int i, int j) { return t[j] < t[i]; }
};
struct wt_cmp {
    bool operator()(int i, int j) { return w[i]-t[i] < w[j]-t[j]; }
};

int main(){
    multiset<int,wt_cmp> better;
    multiset<int,t_cmp> worse;

    scanf(" %d", &n);
    for(int i=0;i<n;i++) scanf(" %lld%lld", t+i, w+i);
    for(int i=1;i<n;i++)
        if(t[i] > t[0]) better.insert(i);
        else            worse.insert(i);

    bst = 1 + better.size();
    while(t[0] > 0 && !better.empty()) {
        int i = *better.begin();
        t[0] -= w[i] - t[i] + 1;
        if(t[0] < 0) break;
        better.erase(better.begin());

        while(!worse.empty()) {
            i = *worse.begin();
            if(t[0] >= t[i]) break;
            better.insert(i);
            worse.erase(worse.begin());
        }
        bst = min(bst, int(1 + better.size()));
    }
    printf("%d\n", bst);
}
