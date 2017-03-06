#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;

const int N = 1e6;
const ll BAD = -ll(1e15);

int n;
int seen[N];
ll a[N], S[N], T[N], A[N];
vector<int> G[N];

ll dfs(int i){
    seen[i] = 1;
    S[i] = a[i];
    A[i] = T[i] = BAD;
    vector<ll> kids;

    for(auto j : G[i]) if(seen[j] == 0) {
        A[i] = max(A[i], dfs(j));
        T[i] = max(T[i], T[j]);
        S[i] += S[j];
        kids.push_back(T[j]);
    }
    T[i] = max(S[i], T[i]);

    if(kids.size() > 1){
        sort(kids.begin(), kids.end());
        int s = kids.size();
        A[i] = max(A[i], kids[s-1] + kids[s-2]);
    }

    return A[i];
}

int main(){
    scanf(" %d", &n);
    for(int i=0;i<n;i++) {
        int k; scanf(" %d", &k); a[i] = k;
    }
    for(int k=1;k<n;k++){
        int i, j;
        scanf(" %d%d", &i, &j); --i; --j;
        G[i].push_back(j); G[j].push_back(i);
    }

    ll ans = dfs(0);
    if(ans == BAD) puts("Impossible");
    else cout << ans << endl;
}
