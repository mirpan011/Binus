#include <stdio.h>

int faktorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * faktorial(n - 1);
}

int main() {
    int n;
    printf("Masukkan bilangan: ");
    scanf("%d", &n);

    printf("Faktorial dari %d adalah %d\n", n, faktorial(n));
    return 0;
}
