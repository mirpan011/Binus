#include <stdio.h>

int main()
{
    int a, b, c;        // Variabel untuk menyimpan tiga bilangan bulat
    int sum, sub, mul;  // Variabel untuk hasil penjumlahan, pengurangan, dan perkalian
    float div, average; // Variabel untuk hasil pembagian dan rata-rata

    // Meminta input dari pengguna
    printf("Masukkan bilangan pertama (integer): ");
    scanf("%d", &a); // Input bilangan pertama

    printf("Masukkan bilangan kedua (integer): ");
    scanf("%d", &b); // Input bilangan kedua

    printf("Masukkan bilangan ketiga (integer): ");
    scanf("%d", &c); // Input bilangan ketiga

    // Operasi aritmatika dasar
    sum = a + b + c;        // Penjumlahan
    sub = a - b - c;        // Pengurangan (berurutan dari a)
    mul = a * b * c;        // Perkalian
    div = (float)a / b / c; // Pembagian, perlu casting ke float agar hasil tidak bulat

    // Menghitung rata-rata
    average = sum / 3.0; // Rata-rata, dibagi 3.0 agar hasilnya float

    // Menampilkan hasil dengan format yang rapi
    printf("\n===== Hasil Perhitungan =====\n");
    printf("Penjumlahan       : %d + %d + %d = %d\n", a, b, c, sum);
    printf("Pengurangan       : %d - %d - %d = %d\n", a, b, c, sub);
    printf("Perkalian         : %d * %d * %d = %d\n", a, b, c, mul);
    printf("Pembagian         : %d / %d / %d = %.2f\n", a, b, c, div);
    printf("Rata-rata         : ( %d + %d + %d ) / 3 = %.2f\n", a, b, c, average);

    return 0; // Menandakan program selesai tanpa error
}
