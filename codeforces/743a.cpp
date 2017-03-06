#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;

const int N = 2e5;

int n, a, b;
char s[N];

int main(){
    scanf(" %d%d%d", &n, &a, &b); --a; --b;
    scanf(" %s", s);
    printf("%d\n", s[a] != s[b]);
}
