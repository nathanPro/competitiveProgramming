#include <bits/stdc++.h>
using namespace std;

set<string> seen;
int T;

int main(){
    cin >> T;
    while(T--){
        int cnt = 0;
        seen.clear();
        string in;
        for(int i=0;i<4;i++){
            cin >> in;
            seen.insert(in);
        }
        for(int i=0;i<4;i++){
            cin >> in;
            cnt += seen.count(in);
        }
        if(cnt < 2) printf("dis");
        puts("similar");
    }
}
