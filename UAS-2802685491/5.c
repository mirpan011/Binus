#include <stdio.h>
#include <string.h>

int main() {
    char nama[100];
    printf("Masukkan sebuah string: ");
    scanf("%s", nama);

    printf("Panjang string: %lu\n", strlen(nama));
    return 0;
}
