#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "inttypes.h"
#include "assert.h"
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) < (b) ? (b) : (a))
#define M 3
#define N 53
#define MT 10002
int int_cmp (const void * a, const void * b) { return *(int *)a - *(int *)b; }

int n;
int A[N][N], r[M][N][N];
int c[M];
void multBy (int A[][N], int B[][N])
{
    static int ans[N][N];
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (ans[i][j] = k = 0; k < n; k++)
                ans[i][j] |= A[i][k] && B[k][j];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            A[i][j] = ans[i][j];
}
void fexp (int A[][N], int e)
{
    static int ans[N][N];
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            ans[i][j] = (i == j);
    for (; e; e >>= 1, multBy (A, A))
        if (e&1) multBy (ans, A);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            A[i][j] = ans[i][j];
}
int T;
int S[MT][N];
int s(int t, int i)
{
    int j, k;
    if (i == n - 1) return 0;
    S[t][i] = 0;
    for (k = 0; k < 3; k++){
        int loc = T;
        for (j = 0; j < n; j++) 
            if (r[k][i][j] && t + c[k] < T)
                loc = min (loc, 1 + S[t + c[k]][j]);
        S[t][i] = max (S[t][i], loc);
    }
    return S[t][i];
}

int main()
{
    while (scanf (" %d", &n) != EOF)
    {
        {
            int i, j;
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    A[i][j] = 0;
        }
        int m;
        scanf (" %d%d%d%d", &m, c, c + 1, c + 2);
        qsort (c, 3, sizeof (int), int_cmp);
        while (m--)
        {
            int i, j; scanf (" %d%d", &i, &j);
            A[--i][--j] = 1;
        }
        {
            int i, j, k;
            for (k = 0; k < 3; k++){
                for (i = 0; i < n; i++)
                    for (j = 0; j < n; j++)
                        r[k][i][j] = A[i][j];
                fexp (r[k], c[k]);
            }
        }
        {
            int i, t;
            T = c[2] * n;
            for (t = T - 1; t + 1; t--)
                for (i = 0; i < n; i++)
                    S[t][i] = s(t, i);
        }
        if (S[0][0] == T) puts("IMPOSSIBLE");
        else printf("%d\n", S[0][0]);

    }
    return 0;
}
