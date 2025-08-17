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

void loadFile() {
    FILE *fp = fopen("file.txt", "r");
    if (fp == NULL) {
        printf("File tidak ditemukan, mulai dengan data kosong.\n");
        return;
    }

    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = 0; 
 
        char nim[20];
        int nilai;
        char nama[100];
 
        sscanf(line, "%s", nim);
 
        char *lastSpace = strrchr(line, ' ');
        if (lastSpace == NULL) continue;
        nilai = atoi(lastSpace + 1);
 
        *lastSpace = '\0'; 
        char *namaStart = strchr(line, ' ');  
        if (namaStart) {
            namaStart++;  
            strcpy(nama, namaStart);
        } else {
            strcpy(nama, "-");
        }
 
        strcpy(mhs[jumlah].nim, nim);
        strcpy(mhs[jumlah].nama, nama);
        mhs[jumlah].nilai = nilai;
        jumlah++;
    }
    fclose(fp);
}
 
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

void tampilkan() {
    printf("\n         Program Entri Nilai");
    printf("\n         ===================\n");
    printf("==============================================\n");
    printf("| %-12s | %-20s | %-5s |\n", "Nim", "Nama", "Nilai");
    printf("==============================================\n");
    for (int i = 0; i < jumlah; i++) {
        printf("| %-12s | %-20s | %-5d |\n", mhs[i].nim, mhs[i].nama, mhs[i].nilai);
    }
    printf("==============================================\n");
}
 
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
 
int validasiNIM(char nim[]) {
    if (strlen(nim) != 10) return 0;
    for (int i = 0; i < 10; i++) {
        if (!isdigit(nim[i])) return 0;
    }
    return 1;
}
 
int validasiNama(char nama[]) {
    int len = strlen(nama);
    return (len >= 3 && len <= 20);
}
 
int validasiNilai(int nilai) {
    return (nilai >= 0 && nilai <= 9);
}
 
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
    tampilkan();

    do {
        printf("\n1.Sorting nim asc");
        printf("\n2.Sorting nilai desc");
        printf("\n3.Tambah data");
        printf("\n4.Keluar dan Save ke file");
        printf("\n\nMasukkan Pilihan : ");
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

