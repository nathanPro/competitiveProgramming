#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

int n;
string v[2];

int main(){
    ios::sync_with_stdio(false);
    cin >> v[0] >> v[1] >> ws >> n;
    for(int i=0;i<n;i++){
        for(int i=0;i<2;i++) cout << v[i] << " \n"[i];
        string dead, rep;
        cin >> dead >> rep;
        for(int i=0;i<2;i++)
            if(dead == v[i]) {
                v[i] = rep;
            }
    }
    for(int i=0;i<2;i++) cout << v[i] << " \n"[i];
}
