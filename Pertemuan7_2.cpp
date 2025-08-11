#include <iostream>
#include <iomanip>
using namespace std;

struct Jam {
    int hh, mm, ss;
};

Jam durasi(Jam J1, Jam J2) {
    Jam hasil;
    int detik1 = J1.hh * 3600 + J1.mm * 60 + J1.ss;
    int detik2 = J2.hh * 3600 + J2.mm * 60 + J2.ss;

    int selisih = detik2 - detik1;
    if (selisih < 0) {
        selisih += 24 * 3600;
    }

    hasil.hh = selisih / 3600;
    selisih %= 3600;
    hasil.mm = selisih / 60;
    hasil.ss = selisih % 60;

    return hasil;
}

int main() {
    Jam J1, J2, J3;

    cout << "Masukkan waktu awal (hh mm ss): ";
    cin >> J1.hh >> J1.mm >> J1.ss;
    cout << "Masukkan waktu akhir (hh mm ss): ";
    cin >> J2.hh >> J2.mm >> J2.ss;

    J3 = durasi(J1, J2);

    cout << "Durasi: "
         << setfill('0') << setw(2) << J3.hh << ":"
         << setfill('0') << setw(2) << J3.mm << ":"
         << setfill('0') << setw(2) << J3.ss << endl;

    return 0;
}
