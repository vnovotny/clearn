/* Lekce 2a: celá čísla, dvojkový doplněk, přetečení.
 * Sestavení: viz CMake; výstup ukazuje, jak vypadají bity a co se stane na hranici rozsahu. */
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

/* Vypíše hodnotu jako 8 bitů (jen pro 8bitové typy, ať je výstup čitelný). */
static void bity8(const char *popis, uint8_t v)
{
    printf("%-14s = ", popis);
    for (int i = 7; i >= 0; i--) {
        putchar((v >> i) & 1 ? '1' : '0');
    }
    printf("  (bez znaménka: %u)\n", (unsigned)v);
}

int main(void)
{
    /* 1) Dvojkový doplněk: -1 má všechny bity jedničky. */
    int8_t a = 5;
    int8_t minus_a = (int8_t)-a;
    bity8("5", (uint8_t)a);
    bity8("-5", (uint8_t)minus_a);
    bity8("~5 + 1", (uint8_t)(~a + 1)); /* negace = invertuj bity a přičti 1 */

    /* 2) Rozsahy typů z <limits.h> a <stdint.h>. */
    printf("\nint:      %d .. %d\n", INT_MIN, INT_MAX);
    printf("uint32_t: 0 .. %u\n", (unsigned)UINT32_MAX);
    printf("int64_t:  %lld .. %lld\n", (long long)INT64_MIN, (long long)INT64_MAX);

    /* 3) Přetečení bez znaménka je DEFINOVANÉ: počítá se modulo 2^N. */
    uint8_t u = 250;
    u = (uint8_t)(u + 10);
    printf("\nuint8_t 250 + 10 = %u (modulo 256)\n", (unsigned)u);

    /* 4) Přetečení se znaménkem je NEDEFINOVANÉ chování (UB).
     *    Volatile brání tomu, aby kompilátor výraz spočítal za překladu. */
    volatile int big = INT_MAX;
    int res = big + 1; /* UB! na -O0 obvykle INT_MIN, na -O2 se může stát cokoli */
    printf("INT_MAX + 1 = %d (UB, nespoléhat)\n", res);

    /* 5) Pozor na míchání znaménkových a neznaménkových typů. */
    int zaporne = -1;
    unsigned int kladne = 1;
    printf("\n-1 < 1u ? %s\n", zaporne < (int)kladne ? "ano" : "ne");
    printf("-1 < 1u (bez přetypování) ? %s\n", zaporne < kladne ? "ano" : "ne");

    return 0;
}
