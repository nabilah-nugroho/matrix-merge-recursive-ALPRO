#include <stdio.h>

#define tungs 10

int n;
int b = 2;
int matriks1[2][tungs];
int matriks2[2][tungs];

void inputK (int matriks[][tungs], int i, int j) {
    if (j >= n)
        return;
    
    printf("matriks[%d][%d]: ", i+1, j+1);
    scanf("%d", &matriks[i][j]);
    
    inputK(matriks, i, j+1);
}

void inputB (int matriks[][tungs], int i){
    if (i >= b)
        return;

    inputK(matriks, i, 0);
    inputB(matriks, i+1);
}

void tampilK(int matriks[][tungs], int i, int j){
    if(j >= n)
        return;

    printf("%d", matriks[i][j]);
    tampilK(matriks, i, j+1);
}

void tampilB(int matriks[][tungs], int i){
    if(i >= b)
        return;

    tampilK(matriks, i, 0);
    printf("\n");
    tampilB(matriks, i+1);
}

void GSS_K(int i, int j){
    if(j >= n)
        return;
    
    if(i%2==0)
        printf("%d ", matriks1[i/2][j]);
    else
        printf("%d ", matriks2[i/2][j]);

    GSS_K(i, j+1);
}

void GSS(int i){
    if(i >= b*2)
        return;
    GSS_K(i, 0);
    printf("\n");
    GSS(i+1);
}

void GC_K(int i, int j){
    if(j >= n)
        return;

    if(i%2 == 0){
        if(j%2==0)
            printf("%d ", matriks1[i/2][j]);
        else
            printf("%d ", matriks2[((i/2)+1)%b][j]);

    }
    else{
        if(j%2==0)
            printf("%d ", matriks2[i/2][j]);
        else
            printf("%d ", matriks1[((i/2)+1)%b][j]);
    }
    GC_K(i, j+1);
}

void GC(int i) {
    if(i >= b*2)
        return;

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