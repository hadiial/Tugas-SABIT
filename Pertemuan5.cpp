#include <iostream>
using namespace std;

int main() {
    int pilihan;
    int durasi;
    int total;
    const int hargaAwal = 1000;
    const int hargaMotor = 2000;
    const int hargaMobil = 3000;

    cout << "Parkir\n";
    cout << "1. Motor\n";
    cout << "2. Mobil\n";
    cout << "3. Keluar\n";
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    do {
        if (pilihan == 1) {
            cout << "Masukkan durasi parkir: ";
            cin >> durasi;

            int jam = durasi / 3600;
            int menit = (durasi % 3600) / 60;
            int detik = durasi % 60;

            if (durasi <= 3600) {
                total = hargaAwal;
            } else {
                int durasiTambahan = durasi - 3600;
                int jamTambahan = (durasiTambahan + 3599) / 3600;
                total = hargaAwal + (jamTambahan * hargaMotor);
            }
            cout << "Jenis Kendaraan = Motor\n";
            cout << "Waktu Parkir = " << jam << " jam, " << menit << " menit, " << detik << " detik." << endl;
            cout << "Total Biaya Parkir = Rp." << total << endl;

        } else if (pilihan == 2) {
            cout << "Masukkan durasi parkir: ";
            cin >> durasi;

            int jam = durasi / 3600;
            int menit = (durasi % 3600) / 60;
            int detik = durasi % 60;

            if (durasi <= 3600) {
                total = hargaAwal;
            } else {
                int durasiTambahan = durasi - 3600;
                int jamTambahan = (durasiTambahan + 3599) / 3600;
                total = hargaAwal + (jamTambahan * hargaMobil);
            }
            cout << "Jenis Kendaraan = Mobil\n";
            cout << "Waktu Parkir = " << jam << " jam, " << menit << " menit, " << detik << " detik." << endl;
            cout << "Total Biaya Parkir = Rp." << total << endl;
        }

    } while (pilihan != 3);

    return 0;
}