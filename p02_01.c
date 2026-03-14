#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char kota[50];
    float beratButet;
    float beratUcok;
    float totalBerat;
    double totalOngkos; // Menggunakan double untuk presisi uang yang lebih besar
    char promo[100];
} Paket;

int main() {
    char inputKota[50];
    // Contoh tarif tetap per kg
    const int TARIF = 15000; 

    while (true) {
        printf("\n--- INPUT DATA PENGIRIMAN ---\n");
        printf("Masukkan Nama Kota (ketik 'end' untuk keluar): ");
        scanf("%s", inputKota);

        if (strcmp(inputKota, "end") == 0) {
            break;
        }

        Paket p;
        strcpy(p.kota, inputKota);

        printf("Berat Paket Butet (kg): ");
        scanf("%f", &p.beratButet);
        printf("Berat Paket Ucok (kg) : ");
        scanf("%f", &p.beratUcok);

        // Proses Logika
        p.totalBerat = p.beratButet + p.beratUcok;
        p.totalOngkos = (double)p.totalBerat * TARIF;

        // Logika Promo: Contoh jika total > 15kg dapat potongan 20rb
        if (p.totalBerat > 15.0) {
            p.totalOngkos -= 20000;
            strcpy(p.promo, "Promo Super Hemat (-Rp 20.000)");
        } else {
            strcpy(p.promo, "Reguler (Tidak Ada Promo)");
        }

        // Tampilan Struk yang lebih rapi
        printf("\n==========================================\n");
        printf("               DEL EXPRESS                \n");
        printf("          Bukti Pengiriman Barang         \n");
        printf("==========================================\n");
        printf(" Kota Tujuan        : %-20s\n", p.kota);
        printf(" Berat Paket Butet  : %6.2f kg\n", p.beratButet);
        printf(" Berat Paket Ucok   : %6.2f kg\n", p.beratUcok);
        printf("------------------------------------------\n");
        printf(" Total Berat        : %6.2f kg\n", p.totalBerat);
        printf(" Promo              : %s\n", p.promo);
        printf(" TOTAL ONGKOS KIRIM : Rp %10.2f\n", p.totalOngkos);
        printf("==========================================\n");
        printf("      Terima Kasih Atas Kepercayaan Anda  \n");
        printf("==========================================\n");
    }

    printf("\nProgram selesai. Sampai jumpa!\n");
    return 0;
}