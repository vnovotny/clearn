// Lekce 1 — hardwarový přesah: kolik bajtů zabírají základní typy na x64 Windows.
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    printf("char       %zu B\n", sizeof(char));
    printf("int        %zu B\n", sizeof(int));
    printf("long       %zu B   <- na Linuxu x64 je to 8 B (model LLP64 vs LP64)\n", sizeof(long));
    printf("long long  %zu B\n", sizeof(long long));
    printf("void*      %zu B   <- šířka adresy procesoru\n", sizeof(void *));
    printf("double     %zu B\n", sizeof(double));
    printf("int32_t    %zu B   <- pevná šířka, když na ní záleží\n", sizeof(int32_t));

    int x = 0x01020304;
    unsigned char *b = (unsigned char *)&x;     // pohled na surové bajty v paměti
    printf("0x01020304 v paměti: %02x %02x %02x %02x  -> %s\n", b[0], b[1], b[2], b[3],
           b[0] == 0x04 ? "little-endian" : "big-endian");
    return 0;
}
