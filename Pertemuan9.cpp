#include <iostream>
using namespace std;

class Parkir {
private:
    int pilihan;
    int durasi;
    int total;
    const int hargaAwal = 1000;
    const int hargaMotor = 2000;
    const int hargaMobil = 3000;

public:
    Parkir(int p, int d) : pilihan(p), durasi(d), total(0) {}

    void hitungBiaya() {
        if (durasi <= 3600) {
            total = hargaAwal;
        } else {
            int durasiTambahan = durasi - 3600;
            int jamTambahan = (durasiTambahan + 3599) / 3600;
            if (pilihan == 1) {
                total = hargaAwal + (jamTambahan * hargaMotor);
            } else if (pilihan == 2) {
                total = hargaAwal + (jamTambahan * hargaMobil);
            }
        }
    }

    void tampilkanHasil() {
        int jam = durasi / 3600;
        int menit = (durasi % 3600) / 60;
        int detik = durasi % 60;

        if (pilihan == 1) {
            cout << "Jenis Kendaraan = Motor\n";
        } else if (pilihan == 2) {
            cout << "Jenis Kendaraan = Mobil\n";
        }

        cout << "Waktu Parkir = " << jam << " jam, " << menit << " menit, " << detik << " detik." << endl;
        cout << "Total Biaya Parkir = Rp." << total << endl;
    }
};

int main() {
    int pilihan;
    int durasi;

    cout << "Parkir\n";
    cout << "1. Motor\n";
    cout << "2. Mobil\n";
    cout << "3. Keluar\n";

    do {
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == 1 || pilihan == 2) {
            cout << "Masukkan durasi parkir (dalam detik): ";
            cin >> durasi;

            Parkir p(pilihan, durasi);
            p.hitungBiaya();
            p.tampilkanHasil();
        }

    } while (pilihan != 3);

    return 0;
}
