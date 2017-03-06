#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

const int S = 505;
char in[S];
int s[CHAR_MAX];

int main(){
    scanf(" %s", in);
    for(int i=0;i<CHAR_MAX;i++) s[i] = S;
    for(int i=0;in[i];i++)
        if(s[in[i]] == S) s[in[i]] = i;

    int ok = 1;
    for(char i='a';i<='z';i++){
        if(i == 'a') continue;
        ok &= (s[i-1] <= s[i]);
    }
    if(ok) puts("YES");
    else   puts("NO");
}
