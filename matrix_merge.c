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

void GSS() {

for (int i = 0; i < b; i++){
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

int main() {
    inputUser();
    GSS();
    return 0; 
}