/* Lekce 2b: float/double podle IEEE 754 a proč 0.1 + 0.2 != 0.3. */
#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* Přečte bity doubleu bez porušení pravidel aliasingu (memcpy je správná cesta). */
static uint64_t bity_double(double d)
{
    uint64_t u;
    memcpy(&u, &d, sizeof u);
    return u;
}

static void rozeber(double d)
{
    uint64_t u = bity_double(d);
    unsigned znamenko = (unsigned)(u >> 63);
    unsigned exponent = (unsigned)((u >> 52) & 0x7FF);
    uint64_t mantisa = u & 0xFFFFFFFFFFFFFULL;
    printf("%-8g  znaménko=%u  exponent=%4u (bias 1023 -> %5d)  mantisa=0x%013llx\n",
           d, znamenko, exponent, (int)exponent - 1023, (unsigned long long)mantisa);
}

int main(void)
{
    printf("sizeof(float)=%zu  sizeof(double)=%zu  DBL_EPSILON=%g\n\n",
           sizeof(float), sizeof(double), DBL_EPSILON);

    rozeber(1.0);
    rozeber(-2.0);
    rozeber(0.5);
    rozeber(0.1);

    double s = 0.1 + 0.2;
    printf("\n0.1 + 0.2 = %.17g\n", s);
    printf("0.1 + 0.2 == 0.3 ? %s\n", s == 0.3 ? "ano" : "ne");
    printf("|rozdíl| < eps ? %s\n", fabs(s - 0.3) < DBL_EPSILON ? "ano" : "ne");

    double nula = 0.0;
    printf("\n1/0.0 = %g, -1/0.0 = %g, 0.0/0.0 = %g\n", 1.0 / nula, -1.0 / nula, nula / nula);
    printf("NaN == NaN ? %s\n", (nula / nula) == (nula / nula) ? "ano" : "ne");

    /* float má jen ~7 platných číslic: 16 777 216 + 1 se ztratí. */
    float f = 16777216.0f;
    printf("\nfloat 16777216 + 1 = %.1f\n", (double)(f + 1.0f));

    return 0;
}
