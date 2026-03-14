#include <stdio.h>
#include <string.h>
#include <stdbool.h> // Standar C99 untuk tipe data boolean

#define MAX_MENU 5

// 1. Menggunakan STRUCT untuk menyimpan data menu
typedef struct {
    char nama[30];
    int harga;
    int stok;
} Menu;

// 2. Fungsi untuk menampilkan daftar menu
void tampilkanMenu(Menu list[], int n) {
    printf("\n--- DAFTAR MENU KAFETARIA IT DEL ---\n");
    printf("%-3s %-20s %-10s %-5s\n", "No", "Nama Makanan", "Harga", "Stok");
    printf("----------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-3d %-20s Rp%-9d %-5d\n", i + 1, list[i].nama, list[i].harga, list[i].stok);
    }
    printf("----------------------------------------------\n");
}

int main() {
    // Inisialisasi data menu
    Menu kafetaria[MAX_MENU] = {
        {"Nasi Ayam Penyet", 15000, 20},
        {"Mie Gomak", 10000, 15},
        {"Ikan Mas Arsik", 22000, 10},
        {"Teh Manis Hot", 5000, 30},
        {"Kopi Sitoluama", 8000, 25}
    };

    int pilihan, jumlah;
    int totalBiaya = 0;
    char pilihanLanjut;

    printf("Selamat Datang di Sistem Operasional Kafetaria IT Del\n");

    do {
        tampilkanMenu(kafetaria, MAX_MENU);

        // 3. Memungkinkan pengguna memilih menu dan jumlah porsi
        printf("Pilih nomor menu (1-%d): ", MAX_MENU);
        scanf("%d", &pilihan);

        // Validasi nomor menu
        if (pilihan < 1 || pilihan > MAX_MENU) {
            printf("Pilihan tidak valid!\n");
        } else {
            int index = pilihan - 1; // Konversi ke index array (0-based)
            
            printf("Masukkan jumlah porsi untuk %s: ", kafetaria[index].nama);
            scanf("%d", &jumlah);

            // 4. Validasi stok dan pengurangan stok secara otomatis
            if (jumlah <= 0) {
                printf("Jumlah pesanan tidak valid.\n");
            } else if (kafetaria[index].stok >= jumlah) {
                // Kurangi stok
                kafetaria[index].stok -= jumlah;
                
                // Hitung subtotal
                int subtotal = kafetaria[index].harga * jumlah;
                totalBiaya += subtotal;
                
                printf("Berhasil memesan %d %s.\n", jumlah, kafetaria[index].nama);
                printf("Subtotal: Rp %d\n", subtotal);
            } else {
                printf("Maaf, stok tidak mencukupi! (Sisa stok: %d)\n", kafetaria[index].stok);
            }
        }

        printf("\nApakah ingin menambah pesanan lain? (y/n): ");
        scanf(" %c", &pilihanLanjut);

    } while (pilihanLanjut == 'y' || pilihanLanjut == 'Y');

    // 5. Menampilkan total biaya di akhir transaksi
    printf("\n======================================\n");
    printf("TOTAL PEMBAYARAN: Rp %d\n", totalBiaya);
    printf("Terima kasih, selamat menikmati hidangan Anda!\n");
    printf("======================================\n");

    return 0;
}