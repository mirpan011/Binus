#include <stdio.h>

int main() {
    int angka;
    printf("Masukkan sebuah bilangan bulat: ");
    scanf("%d", &angka);

    if (angka % 2 == 0)
        printf("%d adalah bilangan genap\n", angka);
    else
        printf("%d adalah bilangan ganjil\n", angka);

    return 0;
}


