#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
const ll N = 1e7 + 7;

ll f, T, t[3], a[3], p[3], n[3];

ll ceil(ll a, ll b){
    return a/b + (a%b != 0);
}

ll solve(int i){
    ll ans = 1e18;
    int j = 1 + (1^(i - 1));
    for (n[i] = 0; n[i] < N; n[i]++){
        if (a[i] * (n[i] - 5) > f) break;
        n[j] = ceil(T - f * t[0] - n[i] * a[i] * (t[i] - t[0]), a[j] * (t[j] - t[0]));
        n[0] = f - n[2] * a[2] - n[1] * a[1];
        fprintf(stderr, "n[0] = %lld, n[1] = %lld, n[2] = %lld\n",
                n[0], n[1], n[2]);
        int ok = 1;
        n[0] = max((ll)0, n[0]);
        n[j] = max((ll)0, n[j]);
        ok &= (n[0] * t[0] + n[1] * a[1] * t[1] + n[2] * a[2] * t[1] <= T);
        if (ok)
            ans = min(ans, n[1] * p[1] + n[2] * p[2]);
    }
    return ans;
}

int main()
{
    cin >> f >> T >> t[0];
    for (int i = 1; i < 3; i++)
        cin >> a[i] >> t[i] >> p[i];

    ll tmp = *min_element(t, t + 3);
    if (T < tmp * f){
        cout << "-1\n";
        return 0;
    } /* It is possible */

    if (t[0] <= t[1] && t[0] <= t[2]){
        cout << "0\n";
        return 0;
    }

    if (t[0] <= t[1]){
        n[2] = ceil(T - f * t[0], a[2] * (t[2] - t[0]));
        cout << n[2] * p[2] << endl;
        return 0;
    }

    if (t[0] <= t[1]){
        n[1] = ceil(T - f * t[0], a[1] * (t[1] - t[0]));
        cout << n[1] * p[1] << endl;
        return 0;
    }

    cout << min(solve(1), solve(2)) << endl;
}
