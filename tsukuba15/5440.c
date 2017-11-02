#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "inttypes.h"
#include "assert.h"
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) < (b) ? (b) : (a))
#define  N 2017
#define oo ((uint64_t)1000000000000000000)

int n;
char s[N], *e;

typedef struct {
    int len;
    uint64_t cnt;
} sol;
sol *F(char *i, char *j)
{
    static sol _F[N][N];
    return &_F[i - s][j - s];
}

void f(char *i, char *j)
{
    if (j - i <= 1)
	return (void) (*F(i, j) = (sol) { j - i, 1 });
    if (*i == *(j - 1))
	return (void) (*F(i, j) = (sol) { 2 + F(i + 1, j - 1)->len, F(i + 1, j - 1)->cnt });
    int loc = min(F(i + 1, j)->len, F(i, j - 1)->len);
    *F(i, j) = (sol) {loc, 0};
    if (loc == F(i + 1, j)->len)
	F(i, j)->cnt += F(i + 1, j)->cnt;
    if (loc == F(i, j - 1)->len)
	F(i, j)->cnt += F(i, j - 1)->cnt;
    *F(i, j) = (sol) {2 + F(i, j)->len, min(F(i, j)->cnt, oo)};
}

char q[N], *qf, *mid;
void build(char *i, char *j, uint64_t k)
{
    if (i + 1 == j)
	mid = i;
    if (j - i <= 1)
	return;
    if (*i == *(j - 1))
	return *qf++ = *i++, build(i, --j, k);
    if (F(i, j)->len != 2 + F(i, j - 1)->len)
	return *qf++ = *i++, build(i, j, k);
    if (F(i, j)->len != 2 + F(i + 1, j)->len)
	return *qf++ = *--j, build(i, j, k);
    if (*i < *(j - 1)) {
	if (F(i + 1, j)->cnt < k) {
	    k -= F(i + 1, j)->cnt;
	    *qf++ = *--j;
	} else
	    *qf++ = *i++;
	return build(i, j, k);
    }
    if (F(i, j - 1)->cnt < k) {
	k -= F(i, j - 1)->cnt;
	*qf++ = *i++;
    } else
	*qf++ = *--j;
    build(i, j, k);
}

int main()
{
    while (scanf(" %s", s) != EOF) {
	for (e = s; *e; e++);
	uint64_t k;
	scanf(" %" SCNu64, &k);
	{
	    char *i, *j;
	    for (i = e; s <= i; i--)
		for (j = i; j <= e; j++)
		    f(i, j);
	}
	if (F(s, e)->cnt < k)
	    puts("NONE");
	else {
	    char *i;
	    qf = q;
	    mid = NULL;
	    build(s, e, k);
	    for (i = q; i < qf; i++)
		putchar(*i);
	    if (mid)
		putchar(*mid);
	    for (i = qf - 1; q <= i; i--)
		putchar(*i);
	    putchar('\n');
	}
    }
    return 0;
}
