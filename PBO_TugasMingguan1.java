import java.util.Scanner;

public class PBO_TugasMingguan1 {
    public static void main(String[] args) {
        // Deklarasi variabel
        int[][] HARGA_MENU = {{18000, 1}, {20000, 2}, {25000, 3}, {30000, 4}, {25000, 5}};
        int[] HARGA_ONGKIR = {8000, 20000};
        int JARAK_ONGKIR = 4;
        int BATAS_POTONGAN_ONGKIR_1 = 40000;
        int POTONGAN_ONGKIR_1 = 4000;
        int BATAS_POTONGAN_ONGKIR_2 = 100000;
        int POTONGAN_ONGKIR_2 = 9000;
        int BATAS_POTONGAN_ONGKIR_3 = 150000;
        int POTONGAN_ONGKIR_3 = 12000;

        int pilihan_menu, jumlah_pesanan, jarak, ongkir, potongan_ongkir = 0, total_bayar;
        char ulang;

        // Membuat objek Scanner untuk input
        Scanner scanner = new Scanner(System.in);

        // Main loop
        do {
            // Menampilkan menu makanan menggunakan for loop
            System.out.println("Menu makanan:");
            for (int i = 0; i < 5; ++i) {
                System.out.println(HARGA_MENU[i][1] + ". Nasi Bakar " + getMenuName(i) + " : Rp" + HARGA_MENU[i][0]);
            }

            // Meminta input dari pengguna menggunakan while loop
            System.out.print("Pilih menu (1-5): ");
            pilihan_menu = scanner.nextInt();
            System.out.print("Jumlah pesanan: ");
            jumlah_pesanan = scanner.nextInt();

            // Menghitung total bayar
            total_bayar = HARGA_MENU[pilihan_menu - 1][0] * jumlah_pesanan;

            // Meminta input jarak pengiriman
            System.out.print("Jarak (KM): ");
            jarak = scanner.nextInt();

            // Menghitung biaya ongkir berdasarkan jarak menggunakan for loop
            ongkir = (jarak > JARAK_ONGKIR) ? HARGA_ONGKIR[1] : HARGA_ONGKIR[0];

            //total bayar menggunakan while loop
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
            System.out.println("\nSLIP PEMBAYARAN");
            System.out.println("======================");
            System.out.print("Menu yang dipesan: " + getMenuName(pilihan_menu - 1) + "\nJumlah pesanan: " + jumlah_pesanan +
                    "\nTotal harga: Rp" + total_bayar + "\nBiaya ongkir: Rp" + ongkir + "\nPotongan ongkir: Rp" + potongan_ongkir +
                    "\nTotal bayar: Rp" + (total_bayar + ongkir - potongan_ongkir));

            // Meminta input untuk memesan lagi
            System.out.print("\nIngin memesan lagi? (y/n): ");
            ulang = scanner.next().charAt(0);

        } while (ulang == 'y' || ulang == 'Y');

        // Menutup scanner
        scanner.close();
    }

    // Metode untuk mendapatkan nama menu berdasarkan indeks
    private static String getMenuName(int index) {
        switch (index) {
            case 0:
                return "Ayam";
            case 1:
                return "Tongkol";
            case 2:
                return "MIX";
            case 3:
                return "Cumi";
            case 4:
                return "Goreng Bakar";
            default:
                return "Menu tidak valid";
        }
    }
}
