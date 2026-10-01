// Lekce 1 — první program v C.
#include <stdio.h>

int main(void)
{
    const char *jmeno = "svět";        // řetězec = ukazatel na pole znaků zakončené nulou
    printf("Ahoj, %s!\n", jmeno);       // formát se kontroluje až za běhu — překladač typy nehlídá
    return 0;
}
