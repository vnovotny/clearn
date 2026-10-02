// Lekce 1 — první program v C.
#include <stdio.h>

int secti(int a, int b);

void nic()
{
    printf("Nic nedělám.\n");
}

int main(void)
{
    nic();
    //secti(3, 4);
    char *jmeno = "svět";   // řetězec = ukazatel na pole znaků zakončené nulou
    // Řetězec "svět" je v paměti uložen jako posloupnost znaků zakončená nulovým znakem \0. Proměnná jmeno tedy neobsahuje samotný text, ale odkaz na jeho začátek.

    jmeno[0] = 'S'; // změna prvního znaku řetězce na velké písmeno

    printf("Ahoj, %s!\n", jmeno); // formát se kontroluje až za běhu — překladač typy nehlídá
    return 0;
}
