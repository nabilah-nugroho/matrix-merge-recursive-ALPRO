# Matrix Merge Recursive ALPRO

Proyek ini berisi dua program C untuk menggabungkan dua matriks 2 x N dengan dua cara:

- **Gabung Selang-Seling (GSS)**: output menampilkan baris dari matriks 1 dan matriks 2 secara bergantian.
- **Gabung Campur (GC)**: output membentuk pola "campur" dengan elemen dari kedua matriks seperti papan catur.

## File dalam proyek

- `matrix_merge_iterative.c`: versi yang menggunakan loop biasa (iteratif).
- `matrix_merge_recursion.c`: versi yang menggunakan fungsi rekursif untuk input, tampilan, dan penggabungan.

## Cara pakai

1. Buka terminal pada folder proyek.
2. Kompilasi salah satu file dengan GCC.

Contoh:

```bash
gcc matrix_merge_iterative.c -o matrix_merge_iterative.exe
gcc matrix_merge_recursion.c -o matrix_merge_recursion.exe
```

3. Jalankan program yang sudah dikompilasi.

```bash
./matrix_merge_iterative.exe
# atau
./matrix_merge_recursion.exe
```

## Input yang diminta

Program akan meminta:

1. Jumlah kolom `N`.
2. Isi `matriks 1` sebanyak 2 baris dan N kolom.
3. Isi `matriks 2` sebanyak 2 baris dan N kolom.

> Baris matriks selalu 2, sedangkan jumlah kolom ditentukan oleh pengguna.

## Output

Program menampilkan:

- Matriks 1
- Matriks 2
- Hasil gabung selang-seling
- Hasil gabung campur

## Contoh sederhana

Jika pengguna memasukkan `N = 3` dan dua matriks berikut:

Matriks 1:
```
1 2 3
4 5 6
```

Matriks 2:
```
7 8 9
10 11 12
```

Maka hasil gabung selang-seling akan menjadi:
```
1 2 3
7 8 9
4 5 6
10 11 12
```

Hasil gabung campur akan menjadi pola campuran berdasarkan kolom genap/ganjil.

## Catatan

- `matrix_merge_iterative.c` lebih mudah dipahami untuk pembelajaran looping.
- `matrix_merge_recursion.c` menunjukkan cara menggunakan rekursi untuk operasi matriks.
- Kedua program memiliki tujuan yang sama: menggabungkan dua matriks 2 x N.
