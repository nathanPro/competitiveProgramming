#include "bits/stdc++.h"
#define mt make_tuple
using namespace std;
using ll = int64_t;

int64_t a, b;

int main(){
    cin >> a >> b;

    if(a == b){
        cout << 1 << endl;
        return 0;
    }
    if (1000 < b - a){
        cout << 0 << endl;
        return 0;
    }

    int64_t ans;
    a++;
    for (ans = 1; a <= b; a++)
        ans = (ans * a)%ll(10);
    cout << ans << endl;
}
