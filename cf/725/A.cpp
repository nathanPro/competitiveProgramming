#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;

const int N = 3e5;
char s[N];
int n, ans;

int main(){
    scanf(" %d", &n);
    for(int i=1;i<=n;i++) scanf(" %c", s+i);
    for(int j=0;j<n;j++)
        if(s[j+1] == '<') ans++;
        else break;
    for(int j=n+1;j;j--)
        if(s[j-1] == '>') ans++;
        else break;
    printf("%d\n", ans);
}
