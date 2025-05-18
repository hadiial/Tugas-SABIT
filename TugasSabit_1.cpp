// Tulis sebuah kodingan untuk menghitung jumlah biaya tiket parkir yang harus dibayar.
// Sistem menerima input dalam satuan detik.
// Nilai harga yang perlu dibayar pada 1 Jam pertama sebesar Rp 1000
// dan untuk setiap jam selanjutnya sebanyak Rp 2000.
// Tampilkan keterangan sudah berapa lama user parkir dan total biaya yang perlu dibayar.

#include <iostream>
using namespace std;

int main() {
    const int hargaPertama = 1000;
    const int hargaSetelahnya = 2000;
    int durasiDetik;

    cout << "Masukkan waktu parkir dalam detik: ";
    cin >> durasiDetik;

    int jam = durasiDetik / 3600;
    int menit = (durasiDetik % 3600) / 60;
    int detik = durasiDetik % 60;

    int biaya;
    if (durasiDetik <= 3600) {
        biaya = hargaPertama;
    } else {
        biaya = hargaPertama + ((jam) * hargaSetelahnya);
    }

    cout << "Waktu parkir: " << jam << " jam, " << menit << " menit, " << detik << " detik." << endl;
    cout << "Total biaya parkir: Rp." << biaya << endl;

    return 0;
}