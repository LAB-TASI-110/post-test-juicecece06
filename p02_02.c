#include <stdio.h>

int main() {
    int n;
    
    // Input pertama: Jumlah total data (N)
    printf("Masukkan jumlah total data (N): ");
    scanf("%d", &n);

    // Deklarasi array dengan ukuran n (fitur Variable Length Array di C99)
    int stok[n];

    // Input kedua: Deret stok (s1, s2, ..., sN)
    printf("Masukkan %d deret stok: \n", n);
    for (int i = 0; i < n; i++) {
        printf("Stok ke-%d: ", i + 1);
        scanf("%d", &stok[i]);
    }

    // Input ketiga: Kode kategori barang (A atau B)
    char kategori;
    printf("Masukkan kategori (A untuk Ganjil, B untuk Genap): ");
    scanf(" %c", &kategori); // Spasi sebelum %c untuk mengabaikan karakter newline

    int total = 0;

    // Logika perhitungan
    if (kategori == 'A' || kategori == 'a') {
        // Kategori A: Urutan ganjil (1, 3, 5...) -> Indeks array (0, 2, 4...)
        for (int i = 0; i < n; i += 2) {
            total += stok[i];
        }
        printf("Total stok urutan ganjil: %d\n", total);
    } 
    else if (kategori == 'B' || kategori == 'b') {
        // Kategori B: Urutan genap (2, 4, 6...) -> Indeks array (1, 3, 5...)
        for (int i = 1; i < n; i += 2) {
            total += stok[i];
        }
        printf("Total stok urutan genap: %d\n", total);
    } 
    else {
        printf("Kategori tidak valid!\n");
    }

    return 0;
}