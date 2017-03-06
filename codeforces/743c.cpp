#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;

ll x,y,z,n;

int main(){
    cin >> n;

    for(x=1;x<2*n;x++){
        for(y=1;y<2*n;y++){
            if(x != y) {
                if(2ll*x*y == n*(x+y)) continue;
                if((n*x*y)%(2ll*x*y - n*x - n*y) != ll(0)) continue;
                z = n*x*y; z /= 2ll*x*y - n*x - n*y;
                if(z == x || z == y) continue;
                if(z < 1 || ll(1e9) < z) continue;
                if(2*x*y*z == n*(y*z + x*z + x*y))
                {
                    cout << x << " " << y << " " << z << endl;
                    return 0;
                }
            }
        }
    }
    cout << "-1" << endl;
}
