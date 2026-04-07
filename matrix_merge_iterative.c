#include <stdio.h>

#define tungguDulu 10 
int n; //kolom
int b = 2; //baris

int matriks1[2][tungguDulu]; //baris sudah pasti 2, kolom menyesuaikan dengan input user
int matriks2[2][tungguDulu];


//user input
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

//supaya tidak membuat fungsi loop berulang kali untuk menampilkan matriks
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
for (int i = 0; i < b*2; i++){ //disini b*2 karena total baris akan x2 dari jumlah awal, karena gabungan dari M1 dan M2
    if (i % 2 == 0){ //kondisi baris genap (i/baris dimulai dari 0), karena output diminta untuk baris ganjil menampilkan matriks 1
        for (int j = 0; j < n; j++){
            printf("%d ", matriks1[i/2][j]); // i/2 karena agar dapat nyeseuaiin saat genap atau i=0 yg muncul baris 1 matriks 1, pas ganjil  atau i = 1 yang muncul baris 1 matriks 2, dan seterusnya.
            }
    printf("\n");
        }

    else { //kondisi baris ganjil, pada baris ganjil dia menampilkan M2
        for (int j = 0; j < n; j++){
            printf("%d ", matriks2[i/2][j]);
            }
    printf("\n");
        }
    }
//penjelasan algoritmanya (i=0)
//baris ganjil = matriks 1 (pakai modulo %2 =! 0 untuk ganjil)
//baris genap = matriks 2 (pakai modulo %2 == 0 untuk genap)
//bagaimana cara menyesuaikan 
//i=0 -> 0/2=0 ->baris 0 matriks 1
//i=1 -> 1/2=0.5=0 ->baris 0 matriks 2
//seterusnya....

}

void GC() {
printf("hasil gabung campur: \n");
    for(int i = 0; i < b*2; i++){ //baris total menjadi double
        for(int j = 0; j < n; j++){ //loop kolom
            if(i%2==0){
                if(j%2==0) //kolom genap
                //ambil m1 baris normal (i/2)
                    printf("%d ", matriks1[i/2][j]);
                
                else
                //ambil m2 lompat baris dibawahnya (+1)
                    printf("%d ", matriks2[((i/2)+1)%b][j]);
                }
            else { //baris ganjil
                if(j%2==0) //kolom genap
                //ambil m2 baris normal (i/2)
                    printf("%d ", matriks2[i/2][j]);
                else //kolom ganjil
                //ambil m1 lompat baris bawahnya (+1)
                    printf("%d ", matriks1[((i/2)+1)%b][j]);

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
