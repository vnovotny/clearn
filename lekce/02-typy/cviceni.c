/* Lekce 2 – cvičení: bezpečné sčítání bez nedefinovaného chování. */
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

/* Vrátí true a zapíše součet do *vysledek, pokud a + b nepřeteče.
 * Vrátí false, pokud by přetekl (a *vysledek nechá beze změny).
 * Důležité: samotné `a + b` při přetečení je UB, takže přetečení
 * musíš zjistit DŘÍV, než sčítání provedeš. */
static bool secti_bezpecne(int a, int b, int *vysledek)
{
    // TODO(human): implementuj kontrolu přetečení pomocí INT_MAX / INT_MIN
    (void)a;
    (void)b;
    (void)vysledek;
    return false;
}

int main(void)
{
    int v = 0;
    printf("1 + 2           -> %s\n", secti_bezpecne(1, 2, &v) ? "ok" : "přetečení");
    printf("INT_MAX + 1     -> %s\n", secti_bezpecne(INT_MAX, 1, &v) ? "ok" : "přetečení");
    printf("INT_MIN + (-1)  -> %s\n", secti_bezpecne(INT_MIN, -1, &v) ? "ok" : "přetečení");
    printf("INT_MAX + (-1)  -> %s\n", secti_bezpecne(INT_MAX, -1, &v) ? "ok" : "přetečení");
    return 0;
}
