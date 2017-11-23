#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
using ull = uint64_t;

const int N = 2e3;
const int oo = INT_MAX;

int n, m;
struct cell {
    int i, j, x;
} C[N * N], *cs = C;
pair<int,int> f(int i, int j) {
    return i < j ? make_pair(i, j) : make_pair(j, i);
}

vector<int> R[N];

int main(){
    scanf(" %d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            int in;
            scanf(" %d", &in);
            *cs++ = {i, j, in};
        }
    sort (C, cs, [](const cell& lhs, const cell& rhs){ return rhs.x < lhs.x; });

    set<pair<int, int>> seen;
    for (cell * c = C; c < cs; c++){
        for (auto i: R[c->j])
            if (seen.count(f(i, c->i))) {
                printf("%d\n", c->x);
                return 0;
            } else seen.insert(f(i, c->i));
        R[c->j].push_back(c->i);
    }
}
