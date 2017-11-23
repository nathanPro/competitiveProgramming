#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
using ull = uint64_t;
using z_t = size_t;

const z_t N = 25;
const int oo = INT_MAX;

z_t a[N], 
    F[6][8] = {
    {22, 18,  6, 14, 21, 17,  5, 13}, // 1, 2, 3, 4
    { 3, 17, 10, 16,  4, 19,  9, 14}, // 5, 6, 7, 8
    { 7, 19, 23, 15,  8, 20, 24, 16}, // 9, 10, 11, 12
    { 1,  5,  9, 24,  3,  7, 11, 22}, // 13, 14, 15, 16
    { 4, 21, 12,  8,  2, 23, 10,  6}, // 17, 18, 19, 20
    { 2, 13, 11, 20,  1, 15, 12, 18} // 21, 22, 23, 24
};

void apply(z_t f){
    for (z_t i = 1; i < 4; i++)
        swap(a[F[f][0]], a[F[f][i]]);
    for (z_t i = 5; i < 8; i++)
        swap(a[F[f][4]], a[F[f][i]]);
}

void check(){
    int ok = 1;
    for (z_t i = 0; i < 6; i++){
        for (z_t j = 2; j < 5; j++)
            ok &= (a[4*i + 1] == a[4*i + j]);
    }
    if (ok){
        puts("YES");
        exit(0);
    }
}


int main(){
    for (z_t i = 1; i < 25; i++) cin >> a[i];
    for (z_t f = 0; f < 6; f++){
        apply(f);
        check();
        apply(f);
        apply(f);
        check();
        apply(f);
    }
    puts("NO");
}
