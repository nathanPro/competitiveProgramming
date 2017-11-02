#include "stdio.h"
#include "stdlib.h"
#include "inttypes.h"
#include "ctype.h"
#include "math.h"
#include "time.h"
#define debug(format, ...)\
    fprintf(stderr, "(%s at line %u)\t" format, __func__,  __LINE__, __VA_ARGS__)
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) < (b) ? (b) : (a))

#define N 17
#define S 65538
#define T 2097152

int n, m, ss;
int a[N], b[N];

uint64_t P, Q;

uint64_t hash(int * b, int * e, int bm, uint64_t p){
    uint64_t ans = 1;
    for(;b != e; b++, bm >>= 1)
        if(bm&1)
            ans = (ans * ((uint64_t)*b))%p;
    return ans;
}

struct rec {
    uint64_t hsh;
    int bm;
} R[S], *rs = R, *table[T];
typedef struct rec rec;

void insert(uint64_t h, int bm){
    register rec ** p = table + h%T;
    for(; 42; p = table + (1 + p - table)%T)
        if(*p == NULL){
            *p = rs++;
            (*p)->hsh = h;
            (*p)->bm  = bm;
            return ;
        }
}

rec * find(uint64_t h, int bm){
    register rec ** p = table + h%T;
    for(; *p; p = table + (1 + p - table)%T)
        if((*p)->hsh == h)
            return *p;
    return NULL;
}

uint64_t gen_prime(){
    uint64_t P = (int64_t)1e9 + (int64_t)rand();
    char prime;
    do {
        P++;
        prime = 1;
        prime &= (P%2 != 0);
        prime &= (P%3 != 0);
        prime &= (P%5 != 0);
        for(uint64_t w = 6; prime && w*w < P; w++){
            w++;
            prime &= (P%w != 0);
            w += 4;
            prime &= (P%w != 0);
        }
    } while(!prime);
    return P;
}

int main() {
    srand(time(NULL));
    P = gen_prime();
    Q = gen_prime();

    scanf(" %d%d", &n, &m);
    for(int i=0; i<n; i++)
        scanf(" %d", a+i);
    for(int i=0; i<m; i++)
        scanf(" %d", b+i);

    for(int bm=1; bm < (1<<n); bm++)
        insert(hash(a, a + n, bm, P), bm);

    for(int bm=1; bm < (1<<m); bm++){
        rec * p = find(hash(b, b + m, bm, P), bm);
        if(!p) continue;
        if(hash(a, a + n, p->bm, Q) != hash(b, b + m, bm, Q)) continue;

        puts("Y");
        printf("%u %u\n", __builtin_popcount(p->bm),
                          __builtin_popcount(bm));
        for(int i = 0; i < n; i++, (p->bm) >>= 1)
            if(1&(p->bm)) printf("%d ", a[i]);
        printf("\n");

        for(int i = 0; i < m; i++, bm >>= 1)
            if(bm&1) printf("%d ", b[i]);
        printf("\n");
        return 0;
    }

    puts("N");
}
