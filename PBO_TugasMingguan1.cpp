#include <iostream>

using namespace std;

int main() {
    // Deklarasi variabel
    int HARGA_MENU[5][2] = {{18000, 1}, {20000, 2}, {25000, 3}, {30000, 4}, {25000, 5}};
    int HARGA_ONGKIR[] = {8000, 20000};
    int JARAK_ONGKIR = 4;
    int BATAS_POTONGAN_ONGKIR_1 = 40000;
    int POTONGAN_ONGKIR_1 = 4000;
    int BATAS_POTONGAN_ONGKIR_2 = 100000;
    int POTONGAN_ONGKIR_2 = 9000;
    int BATAS_POTONGAN_ONGKIR_3 = 150000;
    int POTONGAN_ONGKIR_3 = 12000;

    int pilihan_menu, jumlah_pesanan, jarak, ongkir, potongan_ongkir = 0, total_bayar;
    char ulang;

    // Main loop
    do {
        // Menampilkan menu makanan menggunakan for loop
        cout << "Menu makanan:" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << HARGA_MENU[i][1] << ". Nasi Bakar ";
            switch (i) {
                case 0:
                    cout << "Ayam";
                    break;
                case 1:
                    cout << "Tongkol";
                    break;
                case 2:
                    cout << "MIX";
                    break;
                case 3:
                    cout << "Cumi";
                    break;
                case 4:
                    cout << "Goreng Bakar";
                    break;
            }
            cout << " : Rp" << HARGA_MENU[i][0] << endl;
        }

        // Meminta input dari pengguna menggunakan while loop
        cout << "Pilih menu (1-5): ";
        cin >> pilihan_menu;
        cout << "Jumlah pesanan: ";
        cin >> jumlah_pesanan;

        // Menghitung total bayar
        total_bayar = HARGA_MENU[pilihan_menu - 1][0] * jumlah_pesanan;

        // Meminta input jarak pengiriman
        cout << "Jarak (KM): ";
        cin >> jarak;

        // Menghitung biaya ongkir berdasarkan jarak menggunakan for loop
        for (int i = 0; i < 2; ++i) {
            if (jarak > JARAK_ONGKIR) {
                ongkir = HARGA_ONGKIR[1];
            } else {
                ongkir = HARGA_ONGKIR[0];
            }
        }

        // Menghitung diskon dan potongan ongkir berdasarkan total bayar menggunakan while loop
        int i = 0;
        while (i < 3) {
            if (total_bayar > BATAS_POTONGAN_ONGKIR_3) {
                potongan_ongkir = POTONGAN_ONGKIR_3;
            } else if (total_bayar > BATAS_POTONGAN_ONGKIR_2) {
                potongan_ongkir = POTONGAN_ONGKIR_2;
            } else if (total_bayar > BATAS_POTONGAN_ONGKIR_1) {
                potongan_ongkir = POTONGAN_ONGKIR_1;
            }
            ++i;
        }

        // Menampilkan slip pembayaran
        cout << endl
             << "SLIP PEMBAYARAN" << endl;
        cout << "======================" << endl;
        cout << "Menu yang dipesan: ";
        switch (pilihan_menu) {
            case 1:
                cout << "Nasi Bakar Ayam" << endl;
                break;
            case 2:
                cout << "Nasi Bakar Tongkol" << endl;
                break;
            case 3:
                cout << "Nasi Bakar MIX" << endl;
                break;
            case 4:
                cout << "Nasi Bakar Cumi" << endl;
                break;
            case 5:
                cout << "Nasi Goreng Bakar" << endl;
                break;
            default:
                cout << "Menu tidak valid" << endl;
        }
        cout << "Jumlah pesanan: " << jumlah_pesanan << endl;
        cout << "Total harga: Rp" << total_bayar << endl;
        cout << "Biaya ongkir: Rp" << ongkir << endl;
        cout << "Potongan ongkir: Rp" << potongan_ongkir << endl;
        cout << "Total bayar: Rp" << total_bayar + ongkir - potongan_ongkir << endl;

        // Meminta input untuk memesan lagi
        cout << "Ingin memesan lagi? (y/n): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}
