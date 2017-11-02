#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
const int Z = CHAR_MAX;

int n, oc;
int f[Z], D[N];
char M[N], *mid = M;

void use(char * c)
{
    f[*c] -= 2;
    while ((*c) < Z && f[*c] == 0) (*c)++;
}

void solve(int sz)
{
    printf ("%d\n", n/sz);
    static char S[N];
    char * s, c = 0;
    while (f[c] == 0) c++;
    for (int k = 0; k < n/sz; k++){
        s = S;
        for (int i = 0; i < sz/2; i++){
            *s++ = c;
            putchar(c);
            use(&c);
        }
        if (sz&1) {
            if (M < mid)
                putchar (*--mid);
            else {
                *mid++ = c;
                putchar(c);
                use(&c);
            }
        }
        while (S < s) putchar(*--s);
        putchar(' ');
    }
}

int main(){
    scanf(" %d", &n);
    for (int i = 0; i < n; i++){
        char in; scanf(" %c", &in);
        f[in]++;
    }
    for (int i = 0; i < Z; i++) oc += (f[i]&1);
    int * ds = D;
    for (int i = 1; i*i <= n; i++)
        if (n%i == 0){
            *ds++ = i;
            *ds++ = n/i;
        }
    sort(D, ds);
    ds = unique(D, ds);

    for (int * d = D; d != ds; d++){
        int k = *d;
        int s = n/k;
        if ((s&1) == 0 && oc == 0){
            solve(s);
            break;
        }
        if ((s&1) && oc <= k && (k - oc)%2 == 0){
            for (char c = 0; c < Z; c++)
                if (f[c]&1)
                    f[*mid++ = c]--;
            solve(s);
            break;
        }
    }
    putchar('\n');
}
