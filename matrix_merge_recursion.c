#include <stdio.h>

#define tungs 10

int n; //jumlah kolom dari user
int b = 2; //jumlah baris default 2
int matriks1[2][tungs];
int matriks2[2][tungs];

//input dan print matrix

//fungsi untuk isi tiap kolom dalam satu baris
void inputK (int matriks[][tungs], int i, int j) {
    if (j >= n) return; //berhenti kalau kolom sudah mentok
    
    printf("matriks[%d][%d]: ", i+1, j+1);
    scanf("%d", &matriks[i][j]);
    
    inputK(matriks, i, j+1); //bergeser ke kolom berikutnya
}

//fungsi buat pindah baris (i) pas input
void inputB (int matriks[][tungs], int i){
    if (i >= b) return; //berhenti kalau semua baris sudah terisi

    inputK(matriks, i, 0); //Isi kolom mulai dari index 0
    inputB(matriks, i+1); //pindah ke baris di bawahnya
}

//fungsi print elemen per baris
void tampilK(int matriks[][tungs], int i, int j){
    if(j >= n) return;
    printf("%d ", matriks[i][j]); 
    tampilK(matriks, i, j+1);
}

//fungsi print baris secara vertikal
void tampilB(int matriks[][tungs], int i){
    if(i >= b) return;
    tampilK(matriks, i, 0);
    printf("\n"); // Ganti baris setelah satu baris kolom selesai di-print
    tampilB(matriks, i+1);
}

//gabung selang-seling(GSS)

//mengambil elemen berdasarkan ganjil/genap baris output
void GSS_K(int i, int j){
    if(j >= n) return;
    
    // i/2 digunakan agar index baris asli (0-1) sinkron dengan index baris output (0-3)
    if(i % 2 == 0) // jika baris output genap, ambil dari  M1
        printf("%d ", matriks1[i/2][j]);
    else           // jika baris output ganjil, ambil dari  M2
        printf("%d ", matriks2[i/2][j]);

    GSS_K(i, j+1);
}

void GSS(int i){
    if(i >= b*2) return; // Output jadi double baris (b*2)
    GSS_K(i, 0);
    printf("\n");
    GSS(i+1);
}

//gabung campur (GC)

//pola catur
void GC_K(int i, int j){
    if(j >= n) return;

    if(i % 2 == 0){ //pola baris genap (0, 2)
        if(j % 2 == 0) // kolom genap ambil M1 baris normal
            printf("%d ", matriks1[i/2][j]);
        else           // kolom ganjil Ambil M2 baris lompat +1
            // %b agar index tetap dalam range 0-1
            printf("%d ", matriks2[((i/2)+1)%b][j]);
    }
    else { //pola baris ganjil (1, 3)
        if(j % 2 == 0) //kolom genap ambil M2 baris normal
            printf("%d ", matriks2[i/2][j]);
        else           //kolom ganjil ambil M1 baris lompat (+1)
            printf("%d ", matriks1[((i/2)+1)%b][j]);
    }
    GC_K(i, j+1);
}

void GC(int i) {
    if(i >= b*2) return;
    GC_K(i, 0);
    printf("\n");
    GC(i+1);
}

int main () {
    printf("jumlah kolom: "); scanf("%d", &n);
    printf("\n");
    printf("input matriks 1\n"); inputB(matriks1, 0);
    printf("\n");
    printf("input matriks 2\n"); inputB(matriks2, 0);
    printf("\n\n");

    printf("matriks 1\n"); tampilB(matriks1, 0);
    printf("\n");
    printf("matriks 2\n"); tampilB(matriks2, 0);
    printf("\n\n");

    printf("gabung selang-seling\n"); GSS(0);
    printf("\n\n");
    printf("gabung campur\n"); GC(0);

    return 0;
}

//https://github.com/nabilah-nugroho/matrix-merge-recursive-ALPRO.git