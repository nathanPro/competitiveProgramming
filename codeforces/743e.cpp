#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;

const int N = 2000;

set<int> seen;
int n, s[N], v[8] = {1,2,3,4,5,6,7,8};
vector<int> pos[9];

int main(){
    scanf(" %d", &n);
    for(int i=0;i<n;i++) {
        scanf(" %d", s+i);
        pos[s[i]].push_back(i);
        seen.insert(s[i]);
    }
    if(seen.size() < 8) {
        cout << seen.size() << endl;
        return 0;
    }

    int ans = seen.size();
    for(int f=2;f<126;f++){
        do {
            int fst = 0, bad = 0;
            for(int j=0;j<8;j++){
                int k = v[j];
                int p = lower_bound(pos[k].begin(), pos[k].end(), fst) - pos[k].begin();
                if(p == pos[k].end()) {
                    bad = 1;
                    break;
                }
            }
            if(!bad) ans = max(ans, 
        } while(next_permutation(v, v+8));
    }
}
