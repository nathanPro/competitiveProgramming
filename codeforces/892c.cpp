#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
using ull = uint64_t;

const int N = 4e3;
const int oo = INT_MAX;

ll gcd (ll a, ll b) { return b? gcd(b, a%b) : a; }

int n, cum;
int a[N];

int main(){
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", a + i);
        cum = gcd (cum, a[i]);
    }
    if (cum != 1){
        printf("-1\n");
        return 0;
    }
    if (*min_element(a, a + n) == 1){
        cum = 0;
        for (int i = 0; i < n; i++)
            cum += (a[i] != 1);
        printf("%d\n", cum);
        return 0;
    }

    int ans = 2*(n - 1);
    for (int i = 0; i < n; i++) {
        int loc = 0;
        int j;
        cum = a[i];
        for (j = i + 1; 1 != cum && j < n; j++) {
            cum = gcd (cum, a[j]);
            loc++;
        }
        if (cum == 1) {
            ans = min(ans, loc + n - 1);
        }
    }
    printf("%d\n", ans);
}
