// Lekce 1 — první program v C.
#include <stdio.h>

int nic(void)
{
    return 0;
}

int main(void)
{
    nic();
    const char *jmeno = "svět";   // řetězec = ukazatel na pole znaků zakončené nulou
    printf("Ahoj, %s!\n", jmeno); // formát se kontroluje až za běhu — překladač typy nehlídá
    return 0;
}
