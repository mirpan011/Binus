#include <stdio.h>

int main()
{
    int nilai[5];     // Array untuk menyimpan 5 nilai ujian
    int *ptr = nilai; // Pointer untuk mengakses elemen array
    int i;
    int max, min;
    float total = 0.0, rata_rata;

    // Input nilai ujian
    printf("Masukkan 5 nilai ujian:\n");
    for (i = 0; i < 5; i++)
    {
        printf("Nilai ke-%d: ", i + 1);
        scanf("%d", ptr + i); // Menggunakan pointer untuk menyimpan nilai
    }

    // Inisialisasi nilai max dan min dengan elemen pertama
    max = min = *(ptr); // ptr == &nilai[0]

    // Proses perhitungan menggunakan pointer
    for (i = 0; i < 5; i++)
    {
        if (*(ptr + i) > max)
        {
            max = *(ptr + i); // Update nilai maksimum
        }
        if (*(ptr + i) < min)
        {
            min = *(ptr + i); // Update nilai minimum
        }
        total += *(ptr + i); // Akumulasi untuk rata-rata
    }

    // Hitung rata-rata
    rata_rata = total / 5.0;

    // Output hasil
    printf("\n=== Hasil Analisis Nilai Ujian ===\n");
    printf("Nilai Tertinggi : %d\n", max);
    printf("Nilai Terendah  : %d\n", min);
    printf("Rata-rata Nilai : %.2f\n", rata_rata);

    return 0;
}
