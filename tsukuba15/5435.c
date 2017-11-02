#include "stdio.h"
#include "math.h"

#define N 501
#define max(a,b) ((a) < (b) ? (b) : (a))
#define min(a,b) ((a) < (b) ? (a) : (b))

int n, r[N];
double x[N];

int main()
{
    int i, j;
    while (scanf (" %d", &n) != EOF){
        for (i = 0; i < n; i++) scanf (" %d", r + i);
        for (i = 0; i < n; i++){
            x[i] = r[i];
            for (j = 0; j < i; j++)
                x[i] = max (x[i], x[j] + 2 * sqrt (r[i] * r[j]));
        }
        double ans = 0.0;
        for (i = 0; i < n; i++)
            ans = max (ans, x[i] + r[i]);
        printf ("%.20lf\n", ans);
    }
}
