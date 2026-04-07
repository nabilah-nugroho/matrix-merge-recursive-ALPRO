#include <stdio.h>

#define tungguDulu 10
int n; //kolom
int b = 2; //baris

int matriks1[2][tungguDulu];
int matriks2[2][tungguDulu];


void inputUser(){
    printf("masukkan kolom yang diinginkan: "); scanf("%d", &n);
    printf("\n\n");

    printf("input matriks 1\n");
    for (int i = 0; i < b; i++){
        for (int j = 0; j < n; j++){
            printf("matriks1[%d][%d]: ", i+1, j+1);
            scanf("%d", &matriks1[i][j]);
        }
    }
    printf("\n\n");
    printf("input matriks 2\n");
    for (int i = 0; i < b; i++){
        for (int j = 0; j < n; j++){
            printf("matriks2[%d][%d]: ", i+1, j+1);
            scanf("%d", &matriks2[i][j]);
        }
    }
}

void tampil(int matriks[][tungguDulu], int baris, int kolom, char nama[]){
    printf("%s\n", nama);
    for (int i = 0; i < baris; i++){
        for(int j = 0; j < kolom; j++){
            printf("%d ", matriks[i][j]);
        }
        printf("\n");
    }
}

void GSS() {
printf("hasil gabung selang-seling: \n");
for (int i = 0; i < b*2; i++){
    if (i % 2 == 0){
        for (int j = 0; j < n; j++){
            printf("%d ", matriks1[i/2][j]);
            }
    printf("\n");
        }

    else {
        for (int j = 0; j < n; j++){
            printf("%d ", matriks2[i/2][j]);
            }
    printf("\n");
        }
    }

}

void GC() {
printf("hasil gabung campur: \n");
    for(int i = 0; i < b*2; i++){
        for(int j = 0; j < n; j++){
            if(i%2==0){
                if(j%2==0)
                    printf("%d ", matriks1[i/2][j]);
                
                else
                    printf("%d ", matriks2[(i/2)+1][j]);
                }
            else {
                if(j%2==0)
                    printf("%d ", matriks2[i/2][j]);
                else
                    printf("%d ", matriks1[(i/2)+1][j]);

                }
        }
        printf("\n");

    }
}

int main() {
    inputUser();
    printf("\n");
    tampil(matriks1, b, n, "matriks 1");
    printf("\n");
    tampil(matriks2, b, n, "matriks 2");
    printf("\n");
    GSS();
    printf("\n");
    GC();
    return 0; 
}