#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

const int N = 2e5;

int in[N][2], n;
int S[N][2];

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> in[i][0] >> in[i][1];
    S[0][0] = 0; S[0][1] = 1;
    for(int i=1;i<n;i++) {
        S[i][0] = S[i][1] = N;
        for(int b=0;b<2;b++){
            int l = in[i-1][b], r = in[i-1][b^1];
            if(in[i][0] == r) S[i][0] = min(S[i][0], S[i-1][b]);
            if(in[i][1] == r) S[i][1] = min(S[i][1], 1 + S[i-1][b]);
        }
    }
    int ans = min(S[n-1][0], S[n-1][1]);
    if(ans == N) cout << "-1\n";
    else cout << ans << "\n";
}
