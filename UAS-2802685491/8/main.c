#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char nim[20];
    char nama[30];
    int nilai;
} Mahasiswa;

Mahasiswa mhs[MAX];
int jumlah = 0;

// Fungsi untuk load data dari file
void loadFile() {
    FILE *fp = fopen("file.txt", "r");
    if (fp == NULL) {
        printf("File tidak ditemukan, mulai dengan data kosong.\n");
        return;
    }

    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = 0; // hapus newline

        // parsing: ambil nim (pertama), nilai (terakhir), sisanya = nama
        char nim[20];
        int nilai;
        char nama[100];

        // ambil nim dulu
        sscanf(line, "%s", nim);

        // cari nilai terakhir
        char *lastSpace = strrchr(line, ' ');
        if (lastSpace == NULL) continue;
        nilai = atoi(lastSpace + 1);

        // ambil nama (antara nim dan nilai)
        *lastSpace = '\0'; // potong string sebelum nilai
        char *namaStart = strchr(line, ' '); // posisi setelah nim
        if (namaStart) {
            namaStart++; // geser setelah spasi
            strcpy(nama, namaStart);
        } else {
            strcpy(nama, "-");
        }

        // simpan ke struct
        strcpy(mhs[jumlah].nim, nim);
        strcpy(mhs[jumlah].nama, nama);
        mhs[jumlah].nilai = nilai;
        jumlah++;
    }
    fclose(fp);
}

// Fungsi untuk save data ke file
void saveFile() {
    FILE *fp = fopen("file.txt", "w");
    if (fp == NULL) {
        printf("Gagal membuka file untuk save!\n");
        return;
    }
    for (int i = 0; i < jumlah; i++) {
        fprintf(fp, "%s %s %d\n", mhs[i].nim, mhs[i].nama, mhs[i].nilai);
    }
    fclose(fp);
}

// Tampilkan data
void tampilkan() {
    printf("\n%-12s %-20s %-5s\n", "NIM", "Nama", "Nilai");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < jumlah; i++) {
        printf("%-12s %-20s %-5d\n", mhs[i].nim, mhs[i].nama, mhs[i].nilai);
    }
}

// Sorting nim ascending
void sortNIMAsc() {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if (strcmp(mhs[i].nim, mhs[j].nim) > 0) {
                Mahasiswa temp = mhs[i];
                mhs[i] = mhs[j];
                mhs[j] = temp;
            }
        }
    }
    printf("\nData setelah sorting NIM ascending:\n");
    tampilkan();
}

// Sorting nilai descending
void sortNilaiDesc() {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if (mhs[i].nilai < mhs[j].nilai) {
                Mahasiswa temp = mhs[i];
                mhs[i] = mhs[j];
                mhs[j] = temp;
            }
        }
    }
    printf("\nData setelah sorting Nilai descending:\n");
    tampilkan();
}

// Validasi NIM (harus angka, 10 digit)
int validasiNIM(char nim[]) {
    if (strlen(nim) != 10) return 0;
    for (int i = 0; i < 10; i++) {
        if (!isdigit(nim[i])) return 0;
    }
    return 1;
}

// Validasi Nama (3 - 20 karakter)
int validasiNama(char nama[]) {
    int len = strlen(nama);
    return (len >= 3 && len <= 20);
}

// Validasi Nilai (0 - 9)
int validasiNilai(int nilai) {
    return (nilai >= 0 && nilai <= 9);
}

// Tambah data
void tambahData() {
    Mahasiswa baru;
    printf("\nInput NIM (10 digit angka): ");
    scanf("%s", baru.nim);
    if (!validasiNIM(baru.nim)) {
        printf("NIM tidak valid!\n");
        return;
    }

    printf("Input Nama (3-20 karakter): ");
    scanf("%s", baru.nama);
    if (!validasiNama(baru.nama)) {
        printf("Nama tidak valid!\n");
        return;
    }

    printf("Input Nilai (0-9): ");
    scanf("%d", &baru.nilai);
    if (!validasiNilai(baru.nilai)) {
        printf("Nilai tidak valid!\n");
        return;
    }

    mhs[jumlah++] = baru;
    printf("Data berhasil ditambahkan!\n");
    tampilkan();
}

int main() {
    int pilihan;
    loadFile();
    printf("Data awal dari file:\n");
    tampilkan();

    do {
        printf("\n=== MENU ===\n");
        printf("1. Sorting NIM Ascending\n");
        printf("2. Sorting Nilai Descending\n");
        printf("3. Tambah Data\n");
        printf("4. Keluar & Save ke File\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1: sortNIMAsc(); break;
            case 2: sortNilaiDesc(); break;
            case 3: tambahData(); break;
            case 4: saveFile(); printf("Data berhasil disimpan. Keluar program.\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 4);

    return 0;
}
