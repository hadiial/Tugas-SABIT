#include <iostream>
#include <string>
using namespace std;

const int Nmaks = 100;

struct EstimasiPerjalanan {
    string kota_asal;
    string gerbang_asal;
    string kota_tujuan;
    string gerbang_tujuan;
    int golongan;
    int jarak;
    int biaya;
};

class GerbangTol {
private:
    EstimasiPerjalanan estimasi[Nmaks];
    int jumlahData;

    string ToTitleCase(string s) {
        bool kapital = true;
        for (size_t i = 0; i < s.length(); ++i) {
            if (isspace(s[i])) {
                kapital = true;
            } else if (kapital) {
                s[i] = toupper(s[i]);
                kapital = false;
            } else {
                s[i] = tolower(s[i]);
            }
        }
        return s;
    }

    void TampilkanGerbangTol(const string &kota) {
        if (kota == "Jakarta") {
            cout << "- Cawang\n- Tomang\n- Pondok Gede\n- Halim\n- Semanggi\n- Tanjung Priok\n";
        } else if (kota == "Bandung") {
            cout << "- Pasteur\n- Pasir Koja\n- Kopo\n- Moh Toha\n- Buah Batu\n- Cileunyi\n";
        } else if (kota == "Surabaya") {
            cout << "- Dupak\n- Sidoarjo\n- Waru\n- Waru Gunung\n- Satelit\n- Kertosono\n";
        } else {
            cout << "Mohon maaf, pilihan kota belum tersedia.\n";
        }
    }

    int TarifTolDalamKota(string asal, string tujuan, int gol, int &jarak) {
        // Denda jika masuk dan keluar tol dari gerbang yang sama (putar balik)
        if (asal == tujuan) {
            jarak = 0;
            if (gol == 1) return 800000;
            if (gol == 2) return 1200000;
            if (gol == 3) return 1600000;
        }
    
        // Gerbang tol di Kota Jakarta
        // Dari atau ke Cawang
        if ((asal == "Cawang" && tujuan == "Tomang") || (asal == "Tomang" && tujuan == "Cawang")) {
            jarak = 14;
            if (gol == 1) return 11000;
            if (gol == 2) return 16500;
            if (gol == 3) return 19000;
        }
        if ((asal == "Cawang" && tujuan == "Pondok Gede") || (asal == "Pondok Gede" && tujuan == "Cawang")) {
            jarak = 6;
            if (gol == 1) return 5500;
            if (gol == 2) return 8000;
            if (gol == 3) return 11000;
        }
        if ((asal == "Cawang" && tujuan == "Halim") || (asal == "Halim" && tujuan == "Cawang")) {
            jarak = 7;
            if (gol == 1) return 5500;
            if (gol == 2) return 8000;
            if (gol == 3) return 11000;
        }
        if ((asal == "Cawang" && tujuan == "Semanggi") || (asal == "Semanggi" && tujuan == "Cawang")) {
            jarak = 10;
            if (gol == 1) return 7500;
            if (gol == 2) return 11000;
            if (gol == 3) return 14500;
        }
        if ((asal == "Cawang" && tujuan == "Tanjung Priok") || (asal == "Tanjung Priok" && tujuan == "Cawang")) {
            jarak = 20;
            if (gol == 1) return 12500;
            if (gol == 2) return 18000;
            if (gol == 3) return 24000;
        }
        // Dari atau ke Tomang
        if ((asal == "Tomang" && tujuan == "Pondok Gede") || (asal == "Pondok Gede" && tujuan == "Tomang")) {
            jarak = 18;
            if (gol == 1) return 8000;
            if (gol == 2) return 12000;
            if (gol == 3) return 15500;
        }
        if ((asal == "Tomang" && tujuan == "Halim") || (asal == "Halim" && tujuan == "Tomang")) {
            jarak = 17;
            if (gol == 1) return 11000;
            if (gol == 2) return 16500;
            if (gol == 3) return 22000;
        }
        if ((asal == "Tomang" && tujuan == "Semanggi") || (asal == "Semanggi" && tujuan == "Tomang")) {
            jarak = 8;
            if (gol == 1) return 6000;
            if (gol == 2) return 9000;
            if (gol == 3) return 12000;
        }
        if ((asal == "Tomang" && tujuan == "Tanjung Priok") || (asal == "Tanjung Priok" && tujuan == "Tomang")) {
            jarak = 19;
            if (gol == 1) return 12000;
            if (gol == 2) return 17500;
            if (gol == 3) return 23000;
        }
        // Dari atau ke Pondok Gede
        if ((asal == "Pondok Gede" && tujuan == "Halim") || (asal == "Halim" && tujuan == "Pondok Gede")) {
            jarak = 5;
            if (gol == 1) return 5000;
            if (gol == 2) return 7500;
            if (gol == 3) return 10000;
        }
        if ((asal == "Pondok Gede" && tujuan == "Semanggi") || (asal == "Semanggi" && tujuan == "Pondok Gede")) {
            jarak = 18;
            if (gol == 1) return 11000;
            if (gol == 2) return 16500;
            if (gol == 3) return 22000;
        }
        if ((asal == "Pondok Gede" && tujuan == "Tanjung Priok") || (asal == "Tanjung Priok" && tujuan == "Pondok Gede")) {
            jarak = 23;
            if (gol == 1) return 14000;
            if (gol == 2) return 19500;
            if (gol == 3) return 25500;
        }
        // Dari atau ke Halim
        if ((asal == "Halim" && tujuan == "Semanggi") || (asal == "Semanggi" && tujuan == "Halim")) {
            jarak = 14;
            if (gol == 1) return 10000;
            if (gol == 2) return 15000;
            if (gol == 3) return 20000;
        }
        if ((asal == "Halim" && tujuan == "Tanjung Priok") || (asal == "Tanjung Priok" && tujuan == "Halim")) {
            jarak = 19;
            if (gol == 1) return 12000;
            if (gol == 2) return 18000;
            if (gol == 3) return 23000;
        }
        // Dari atau ke Semanggi
        if ((asal == "Semanggi" && tujuan == "Tanjung Priok") || (asal == "Tanjung Priok" && tujuan == "Semanggi")) {
            jarak = 15;
            if (gol == 1) return 11000;
            if (gol == 2) return 16000;
            if (gol == 3) return 21000;
        }
    
        // Gerbang tol di Kota Bandung
        // Dari atau ke Pasteur
        if ((asal == "Pasteur" && tujuan == "Pasir Koja") || (asal == "Pasir Koja" && tujuan == "Pasteur")) {
            jarak = 12;
            if (gol == 1) return 8000;
            if (gol == 2) return 12000;
            if (gol == 3) return 15500;
        }
        if ((asal == "Pasteur" && tujuan == "Kopo") || (asal == "Kopo" && tujuan == "Pasteur")) {
            jarak = 15;
            if (gol == 1) return 9000;
            if (gol == 2) return 13500;
            if (gol == 3) return 17000;
        }
        if ((asal == "Pasteur" && tujuan == "Moh Toha") || (asal == "Moh Toha" && tujuan == "Pasteur")) {
            jarak = 17;
            if (gol == 1) return 10000;
            if (gol == 2) return 15000;
            if (gol == 3) return 19000;
        }
        if ((asal == "Pasteur" && tujuan == "Buah Batu") || (asal == "Buah Batu" && tujuan == "Pasteur")) {
            jarak = 21;
            if (gol == 1) return 11000;
            if (gol == 2) return 16500;
            if (gol == 3) return 21000;
        }
        if ((asal == "Pasteur" && tujuan == "Cileunyi") || (asal == "Cileunyi" && tujuan == "Pasteur")) {
            jarak = 26;
            if (gol == 1) return 13000;
            if (gol == 2) return 19500;
            if (gol == 3) return 25500;
        }
        // Dari atau ke Pasir Koja
        if ((asal == "Pasir Koja" && tujuan == "Kopo") || (asal == "Kopo" && tujuan == "Pasir Koja")) {
            jarak = 6;
            if (gol == 1) return 6000;
            if (gol == 2) return 9000;
            if (gol == 3) return 12000;
        }
        if ((asal == "Pasir Koja" && tujuan == "Moh Toha") || (asal == "Moh Toha" && tujuan == "Pasir Koja")) {
            jarak = 9;
            if (gol == 1) return 7000;
            if (gol == 2) return 10500;
            if (gol == 3) return 14000;
        }
        if ((asal == "Pasir Koja" && tujuan == "Buah Batu") || (asal == "Buah Batu" && tujuan == "Pasir Koja")) {
            jarak = 13;
            if (gol == 1) return 9000;
            if (gol == 2) return 13500;
            if (gol == 3) return 17500;
        }
        if ((asal == "Pasir Koja" && tujuan == "Cileunyi") || (asal == "Cileunyi" && tujuan == "Pasir Koja")) {
            jarak = 18;
            if (gol == 1) return 11000;
            if (gol == 2) return 16500;
            if (gol == 3) return 22000;
        }
        // Dari atau ke Kopo
        if ((asal == "Kopo" && tujuan == "Moh Toha") || (asal == "Moh Toha" && tujuan == "Kopo")) {
            jarak = 5;
            if (gol == 1) return 5000;
            if (gol == 2) return 7500;
            if (gol == 3) return 10000;
        }
        if ((asal == "Kopo" && tujuan == "Buah Batu") || (asal == "Buah Batu" && tujuan == "Kopo")) {
            jarak = 9;
            if (gol == 1) return 7000;
            if (gol == 2) return 10500;
            if (gol == 3) return 14000;
        }
        if ((asal == "Kopo" && tujuan == "Cileunyi") || (asal == "Cileunyi" && tujuan == "Kopo")) {
            jarak = 14;
            if (gol == 1) return 9000;
            if (gol == 2) return 13500;
            if (gol == 3) return 18000;
        }
        // Dari atau ke Moh Toha
        if ((asal == "Moh Toha" && tujuan == "Buah Batu") || (asal == "Buah Batu" && tujuan == "Moh Toha")) {
            jarak = 5;
            if (gol == 1) return 5000;
            if (gol == 2) return 7500;
            if (gol == 3) return 10000;
        }
        if ((asal == "Moh Toha" && tujuan == "Cileunyi") || (asal == "Cileunyi" && tujuan == "Moh Toha")) {
            jarak = 10;
            if (gol == 1) return 7000;
            if (gol == 2) return 10500;
            if (gol == 3) return 14000;
        }
        // Dari atau ke Buah Batu
        if ((asal == "Buah Batu" && tujuan == "Cileunyi") || (asal == "Cileunyi" && tujuan == "Buah Batu")) {
            jarak = 6;
            if (gol == 1) return 6000;
            if (gol == 2) return 9000;
            if (gol == 3) return 12000;
        }
    
        // Gerbang tol di Kota Surabaya
        // Dari atau ke Dupak
        if ((asal == "Dupak" && tujuan == "Sidoarjo") || (asal == "Sidoarjo" && tujuan == "Dupak")) {
            jarak = 26;
            if (gol == 1) return 6000;
            if (gol == 2) return 9000;
            if (gol == 3) return 12000;
        }
        if ((asal == "Dupak" && tujuan == "Waru") || (asal == "Waru" && tujuan == "Dupak")) {
            jarak = 15;
            if (gol == 1) return 6000;
            if (gol == 2) return 9000;
            if (gol == 3) return 12000;
        }
        if ((asal == "Dupak" && tujuan == "Waru Gunung") || (asal == "Waru Gunung" && tujuan == "Dupak")) {
            jarak = 13;
            if (gol == 1) return 6750;
            if (gol == 2) return 10250;
            if (gol == 3) return 13750;
        }
        if ((asal == "Dupak" && tujuan == "Satelit") || (asal == "Satelit" && tujuan == "Dupak")) {
            jarak = 11;
            if (gol == 1) return 6000;
            if (gol == 2) return 8750;
            if (gol == 3) return 11750;
        }
        if ((asal == "Dupak" && tujuan == "Kertosono") || (asal == "Kertosono" && tujuan == "Dupak")) {
            jarak = 91;
            if (gol == 1) return 40000;
            if (gol == 2) return 60500;
            if (gol == 3) return 88000;
        }
        // Dari atau ke Sidoarjo
        if ((asal == "Sidoarjo" && tujuan == "Waru") || (asal == "Waru" && tujuan == "Sidoarjo")) {
            jarak = 23;
            if (gol == 1) return 6500;
            if (gol == 2) return 10500;
            if (gol == 3) return 13500;
        }
        if ((asal == "Sidoarjo" && tujuan == "Waru Gunung") || (asal == "Waru Gunung" && tujuan == "Sidoarjo")) {
            jarak = 25;
            if (gol == 1) return 8500;
            if (gol == 2) return 12750;
            if (gol == 3) return 17000;
        }
        if ((asal == "Sidoarjo" && tujuan == "Satelit") || (asal == "Satelit" && tujuan == "Sidoarjo")) {
            jarak = 28;
            if (gol == 1) return 9000;
            if (gol == 2) return 13500;
            if (gol == 3) return 18000;
        }
        if ((asal == "Sidoarjo" && tujuan == "Kertosono") || (asal == "Kertosono" && tujuan == "Sidoarjo")) {
            jarak = 92;
            if (gol == 1) return 40500;
            if (gol == 2) return 61000;
            if (gol == 3) return 89500;
        }
        // Dari atau ke Waru
        if ((asal == "Waru" && tujuan == "Waru Gunung") || (asal == "Waru Gunung" && tujuan == "Waru")) {
            jarak = 12;
            if (gol == 1) return 6500;
            if (gol == 2) return 9500;
            if (gol == 3) return 12500;
        }
        if ((asal == "Waru" && tujuan == "Satelit") || (asal == "Satelit" && tujuan == "Waru")) {
            jarak = 17;
            if (gol == 1) return 7500;
            if (gol == 2) return 11000;
            if (gol == 3) return 14500;
        }
        if ((asal == "Waru" && tujuan == "Kertosono") || (asal == "Kertosono" && tujuan == "Waru")) {
            jarak = 94;
            if (gol == 1) return 41000;
            if (gol == 2) return 63000;
            if (gol == 3) return 91500;
        }
        // Dari atau ke Waru Gunung
        if ((asal == "Waru Gunung" && tujuan == "Satelit") || (asal == "Satelit" && tujuan == "Waru Gunung")) {
            jarak = 14;
            if (gol == 1) return 7000;
            if (gol == 2) return 10500;
            if (gol == 3) return 14000;
        }
        if ((asal == "Waru Gunung" && tujuan == "Kertosono") || (asal == "Kertosono" && tujuan == "Waru Gunung")) {
            jarak = 85;
            if (gol == 1) return 38500;
            if (gol == 2) return 58000;
            if (gol == 3) return 85000;
        }
        // Dari atau ke Satelit
        if ((asal == "Satelit" && tujuan == "Kertosono") || (asal == "Kertosono" && tujuan == "Satelit")) {
            jarak = 87;
            if (gol == 1) return 39500;
            if (gol == 2) return 59000;
            if (gol == 3) return 86500;
        }
    
        jarak = 0;
        return -1;
    }
    
    int TarifTolAntarKota(string asal, string tujuan, string kotaAsal, string kotaTujuan, int gol, int &jarak) {
        if (kotaAsal == kotaTujuan) {
            jarak = 0;
            return 0;
        }

        // Dari Jakarta ke Bandung atau Bandung ke Jakarta
        if ((kotaAsal == "Jakarta" && kotaTujuan == "Bandung") || (kotaAsal == "Bandung" && kotaTujuan == "Jakarta")) {
            // Dari atau ke Cawang
            if ((asal == "Cawang" && tujuan == "Pasteur") || (asal == "Pasteur" && tujuan == "Cawang")) {
                jarak = 138;
                if (gol == 1) return 75000;
                if (gol == 2) return 125000;
                if (gol == 3) return 165000;
            }
            if ((asal == "Cawang" && tujuan == "Pasir Koja") || (asal == "Pasir Koja" && tujuan == "Cawang")) {
                jarak = 140;
                if (gol == 1) return 75500;
                if (gol == 2) return 126000;
                if (gol == 3) return 166000;
            }
            if ((asal == "Cawang" && tujuan == "Kopo") || (asal == "Kopo" && tujuan == "Cawang")) {
                jarak = 142;
                if (gol == 1) return 76000;
                if (gol == 2) return 127000;
                if (gol == 3) return 168000;
            }
            if ((asal == "Cawang" && tujuan == "Moh Toha") || (asal == "Moh Toha" && tujuan == "Cawang")) {
                jarak = 144;
                if (gol == 1) return 76500;
                if (gol == 2) return 128000;
                if (gol == 3) return 169000;
            }
            if ((asal == "Cawang" && tujuan == "Buah Batu") || (asal == "Buah Batu" && tujuan == "Cawang")) {
                jarak = 146;
                if (gol == 1) return 77000;
                if (gol == 2) return 129000;
                if (gol == 3) return 170000;
            }
            if ((asal == "Cawang" && tujuan == "Cileunyi") || (asal == "Cileunyi" && tujuan == "Cawang")) {
                jarak = 154;
                if (gol == 1) return 80000;
                if (gol == 2) return 132000;
                if (gol == 3) return 175000;
            }
            // Dari atau ke Tomang
            if ((asal == "Tomang" && tujuan == "Pasteur") || (asal == "Pasteur" && tujuan == "Tomang")) {
                jarak = 140;
                if (gol == 1) return 75500;
                if (gol == 2) return 126000;
                if (gol == 3) return 168000;
            }
            if ((asal == "Tomang" && tujuan == "Pasir Koja") || (asal == "Pasir Koja" && tujuan == "Tomang")) {
                jarak = 142;
                if (gol == 1) return 76000;
                if (gol == 2) return 127000;
                if (gol == 3) return 169000;
            }
            if ((asal == "Tomang" && tujuan == "Kopo") || (asal == "Kopo" && tujuan == "Tomang")) {
                jarak = 144;
                if (gol == 1) return 76500;
                if (gol == 2) return 128000;
                if (gol == 3) return 170000;
            }
            if ((asal == "Tomang" && tujuan == "Moh Toha") || (asal == "Moh Toha" && tujuan == "Tomang")) {
                jarak = 146;
                if (gol == 1) return 77000;
                if (gol == 2) return 129000;
                if (gol == 3) return 171000;
            }
            if ((asal == "Tomang" && tujuan == "Buah Batu") || (asal == "Buah Batu" && tujuan == "Tomang")) {
                jarak = 148;
                if (gol == 1) return 77500;
                if (gol == 2) return 130000;
                if (gol == 3) return 172000;
            }
            if ((asal == "Tomang" && tujuan == "Cileunyi") || (asal == "Cileunyi" && tujuan == "Tomang")) {
                jarak = 156;
                if (gol == 1) return 80500;
                if (gol == 2) return 133000;
                if (gol == 3) return 177000;
            }
            // Dari atau ke Pondok Gede
            if ((asal == "Pondok Gede" && tujuan == "Pasteur") || (asal == "Pasteur" && tujuan == "Pondok Gede")) {
                jarak = 141;
                if (gol == 1) return 75500;
                if (gol == 2) return 126000;
                if (gol == 3) return 168000;
            }
            if ((asal == "Pondok Gede" && tujuan == "Pasir Koja") || (asal == "Pasir Koja" && tujuan == "Pondok Gede")) {
                jarak = 143;
                if (gol == 1) return 76000;
                if (gol == 2) return 127000;
                if (gol == 3) return 169000;
            }
            if ((asal == "Pondok Gede" && tujuan == "Kopo") || (asal == "Kopo" && tujuan == "Pondok Gede")) {
                jarak = 145;
                if (gol == 1) return 76500;
                if (gol == 2) return 128000;
                if (gol == 3) return 170000;
            }
            if ((asal == "Pondok Gede" && tujuan == "Moh Toha") || (asal == "Moh Toha" && tujuan == "Pondok Gede")) {
                jarak = 147;
                if (gol == 1) return 77000;
                if (gol == 2) return 129000;
                if (gol == 3) return 171000;
            }
            if ((asal == "Pondok Gede" && tujuan == "Buah Batu") || (asal == "Buah Batu" && tujuan == "Pondok Gede")) {
                jarak = 149;
                if (gol == 1) return 77500;
                if (gol == 2) return 130000;
                if (gol == 3) return 172000;
            }
            if ((asal == "Pondok Gede" && tujuan == "Cileunyi") || (asal == "Cileunyi" && tujuan == "Pondok Gede")) {
                jarak = 157;
                if (gol == 1) return 80500;
                if (gol == 2) return 133000;
                if (gol == 3) return 177000;
            }
            // Dari atau ke Halim
            if ((asal == "Halim" && tujuan == "Pasteur") || (asal == "Pasteur" && tujuan == "Halim")) {
                jarak = 137;
                if (gol == 1) return 74500;
                if (gol == 2) return 124000;
                if (gol == 3) return 166000;
            }
            if ((asal == "Halim" && tujuan == "Pasir Koja") || (asal == "Pasir Koja" && tujuan == "Halim")) {
                jarak = 139;
                if (gol == 1) return 75000;
                if (gol == 2) return 125000;
                if (gol == 3) return 167000;
            }
            if ((asal == "Halim" && tujuan == "Kopo") || (asal == "Kopo" && tujuan == "Halim")) {
                jarak = 141;
                if (gol == 1) return 75500;
                if (gol == 2) return 126000;
                if (gol == 3) return 168000;
            }
            if ((asal == "Halim" && tujuan == "Moh Toha") || (asal == "Moh Toha" && tujuan == "Halim")) {
                jarak = 143;
                if (gol == 1) return 76000;
                if (gol == 2) return 127000;
                if (gol == 3) return 169000;
            }
            if ((asal == "Halim" && tujuan == "Buah Batu") || (asal == "Buah Batu" && tujuan == "Halim")) {
                jarak = 145;
                if (gol == 1) return 76500;
                if (gol == 2) return 128000;
                if (gol == 3) return 170000;
            }
            if ((asal == "Halim" && tujuan == "Cileunyi") || (asal == "Cileunyi" && tujuan == "Halim")) {
                jarak = 153;
                if (gol == 1) return 79500;
                if (gol == 2) return 131000;
                if (gol == 3) return 175000;
            }
            // Dari atau ke Semanggi
            if ((asal == "Semanggi" && tujuan == "Pasteur") || (asal == "Pasteur" && tujuan == "Semanggi")) {
                jarak = 142;
                if (gol == 1) return 76000;
                if (gol == 2) return 127000;
                if (gol == 3) return 170000;
            }
            if ((asal == "Semanggi" && tujuan == "Cileunyi") || (asal == "Cileunyi" && tujuan == "Semanggi")) {
                jarak = 158;
                if (gol == 1) return 81000;
                if (gol == 2) return 135000;
                if (gol == 3) return 180000;
            }
            if ((asal == "Semanggi" && tujuan == "Pasir Koja") || (asal == "Pasir Koja" && tujuan == "Semanggi")) {
                jarak = 144;
                if (gol == 1) return 76500;
                if (gol == 2) return 128000;
                if (gol == 3) return 171000;
            }
            if ((asal == "Semanggi" && tujuan == "Kopo") || (asal == "Kopo" && tujuan == "Semanggi")) {
                jarak = 146;
                if (gol == 1) return 77000;
                if (gol == 2) return 129000;
                if (gol == 3) return 172000;
            }
            if ((asal == "Semanggi" && tujuan == "Moh Toha") || (asal == "Moh Toha" && tujuan == "Semanggi")) {
                jarak = 148;
                if (gol == 1) return 77500;
                if (gol == 2) return 130000;
                if (gol == 3) return 173000;
            }
            if ((asal == "Semanggi" && tujuan == "Buah Batu") || (asal == "Buah Batu" && tujuan == "Semanggi")) {
                jarak = 150;
                if (gol == 1) return 78000;
                if (gol == 2) return 131000;
                if (gol == 3) return 174000;
            }
            // Dari atau ke Tanjung Priok
            if ((asal == "Tanjung Priok" && tujuan == "Pasteur") || (asal == "Pasteur" && tujuan == "Tanjung Priok")) {
                jarak = 145;
                if (gol == 1) return 77000;
                if (gol == 2) return 129000;
                if (gol == 3) return 172000;
            }
            if ((asal == "Tanjung Priok" && tujuan == "Cileunyi") || (asal == "Cileunyi" && tujuan == "Tanjung Priok")) {
                jarak = 160;
                if (gol == 1) return 82000;
                if (gol == 2) return 136000;
                if (gol == 3) return 183000;
            }
            if ((asal == "Tanjung Priok" && tujuan == "Pasir Koja") || (asal == "Pasir Koja" && tujuan == "Tanjung Priok")) {
                jarak = 147;
                if (gol == 1) return 77500;
                if (gol == 2) return 129500;
                if (gol == 3) return 172500;
            }
            if ((asal == "Tanjung Priok" && tujuan == "Kopo") || (asal == "Kopo" && tujuan == "Tanjung Priok")) {
                jarak = 149;
                if (gol == 1) return 78000;
                if (gol == 2) return 131000;
                if (gol == 3) return 174000;
            }
            if ((asal == "Tanjung Priok" && tujuan == "Moh Toha") || (asal == "Moh Toha" && tujuan == "Tanjung Priok")) {
                jarak = 151;
                if (gol == 1) return 78500;
                if (gol == 2) return 132000;
                if (gol == 3) return 175000;
            }
            if ((asal == "Tanjung Priok" && tujuan == "Buah Batu") || (asal == "Buah Batu" && tujuan == "Tanjung Priok")) {
                jarak = 153;
                if (gol == 1) return 79000;
                if (gol == 2) return 133000;
                if (gol == 3) return 176000;
            }
        }

        // Dari Jakarta ke Surabaya atau Surabaya ke Jakarta
        if ((kotaAsal == "Jakarta" && kotaTujuan == "Surabaya") || (kotaAsal == "Surabaya" && kotaTujuan == "Jakarta")) {
            //Dari atau ke Cawang
            if ((asal == "Cawang" && tujuan == "Dupak") || (asal == "Dupak" && tujuan == "Cawang")) {
                jarak = 780;
                if (gol == 1) return 859500;
                if (gol == 2) return 1287000;
                if (gol == 3) return 1771500;
            }
            if ((asal == "Cawang" && tujuan == "Sidoarjo") || (asal == "Sidoarjo" && tujuan == "Cawang")) {
                jarak = 782;
                if (gol == 1) return 861000;
                if (gol == 2) return 1289000;
                if (gol == 3) return 1774000;
            }
            if ((asal == "Cawang" && tujuan == "Waru") || (asal == "Waru" && tujuan == "Cawang")) {
                jarak = 783;
                if (gol == 1) return 862500;
                if (gol == 2) return 1291000;
                if (gol == 3) return 1776000;
            }
            if ((asal == "Cawang" && tujuan == "Waru Gunung") || (asal == "Waru Gunung" && tujuan == "Cawang")) {
                jarak = 784;
                if (gol == 1) return 864000;
                if (gol == 2) return 1293000;
                if (gol == 3) return 1779000;
            }
            if ((asal == "Cawang" && tujuan == "Satelit") || (asal == "Satelit" && tujuan == "Cawang")) {
                jarak = 786;
                if (gol == 1) return 865500;
                if (gol == 2) return 1296000;
                if (gol == 3) return 1781000;
            }
            if ((asal == "Cawang" && tujuan == "Kertosono") || (asal == "Kertosono" && tujuan == "Cawang")) {
                jarak = 790;
                if (gol == 1) return 869000;
                if (gol == 2) return 1301000;
                if (gol == 3) return 1792000;
            }
            // Dari atau ke Tomang
            if ((asal == "Tomang" && tujuan == "Dupak") || (asal == "Dupak" && tujuan == "Tomang")) {
                jarak = 781;
                if (gol == 1) return 860000;
                if (gol == 2) return 1288000;
                if (gol == 3) return 1772000;
            }
            if ((asal == "Tomang" && tujuan == "Sidoarjo") || (asal == "Sidoarjo" && tujuan == "Tomang")) {
                jarak = 783;
                if (gol == 1) return 861500;
                if (gol == 2) return 1290000;
                if (gol == 3) return 1775000;
            }
            if ((asal == "Tomang" && tujuan == "Waru") || (asal == "Waru" && tujuan == "Tomang")) {
                jarak = 784;
                if (gol == 1) return 863000;
                if (gol == 2) return 1292000;
                if (gol == 3) return 1777000;
            }
            if ((asal == "Tomang" && tujuan == "Waru Gunung") || (asal == "Waru Gunung" && tujuan == "Tomang")) {
                jarak = 785;
                if (gol == 1) return 864500;
                if (gol == 2) return 1294000;
                if (gol == 3) return 1779000;
            }
            if ((asal == "Tomang" && tujuan == "Satelit") || (asal == "Satelit" && tujuan == "Tomang")) {
                jarak = 788;
                if (gol == 1) return 866500;
                if (gol == 2) return 1298000;
                if (gol == 3) return 1785000;
            }
            if ((asal == "Tomang" && tujuan == "Kertosono") || (asal == "Kertosono" && tujuan == "Tomang")) {
                jarak = 792;
                if (gol == 1) return 870500;
                if (gol == 2) return 1303000;
                if (gol == 3) return 1795000;
            }
            //Dari atau ke Pondok Gede
            if ((asal == "Pondok Gede" && tujuan == "Dupak") || (asal == "Dupak" && tujuan == "Pondok Gede")) {
                jarak = 780;
                if (gol == 1) return 859500;
                if (gol == 2) return 1287000;
                if (gol == 3) return 1771500;
            }
            if ((asal == "Pondok Gede" && tujuan == "Sidoarjo") || (asal == "Sidoarjo" && tujuan == "Pondok Gede")) {
                jarak = 782;
                if (gol == 1) return 861000;
                if (gol == 2) return 1289000;
                if (gol == 3) return 1774000;
            }
            if ((asal == "Pondok Gede" && tujuan == "Waru") || (asal == "Waru" && tujuan == "Pondok Gede")) {
                jarak = 783;
                if (gol == 1) return 862500;
                if (gol == 2) return 1291000;
                if (gol == 3) return 1776000;
            }
            if ((asal == "Pondok Gede" && tujuan == "Waru Gunung") || (asal == "Waru Gunung" && tujuan == "Pondok Gede")) {
                jarak = 784;
                if (gol == 1) return 864000;
                if (gol == 2) return 1293000;
                if (gol == 3) return 1779000;
            }
            if ((asal == "Pondok Gede" && tujuan == "Satelit") || (asal == "Satelit" && tujuan == "Pondok Gede")) {
                jarak = 786;
                if (gol == 1) return 865500;
                if (gol == 2) return 1296000;
                if (gol == 3) return 1781000;
            }
            if ((asal == "Pondok Gede" && tujuan == "Kertosono") || (asal == "Kertosono" && tujuan == "Pondok Gede")) {
                jarak = 790;
                if (gol == 1) return 869000;
                if (gol == 2) return 1301000;
                if (gol == 3) return 1792000;
            }
            // Dari atau ke Halim
            if ((asal == "Halim" && tujuan == "Dupak") || (asal == "Dupak" && tujuan == "Halim")) {
                jarak = 781;
                if (gol == 1) return 860000;
                if (gol == 2) return 1288000;
                if (gol == 3) return 1772000;
            }
            if ((asal == "Halim" && tujuan == "Sidoarjo") || (asal == "Sidoarjo" && tujuan == "Halim")) {
                jarak = 783;
                if (gol == 1) return 861500;
                if (gol == 2) return 1290000;
                if (gol == 3) return 1775000;
            }
            if ((asal == "Halim" && tujuan == "Waru") || (asal == "Waru" && tujuan == "Halim")) {
                jarak = 784;
                if (gol == 1) return 863000;
                if (gol == 2) return 1292000;
                if (gol == 3) return 1777000;
            }
            if ((asal == "Halim" && tujuan == "Waru Gunung") || (asal == "Waru Gunung" && tujuan == "Halim")) {
                jarak = 785;
                if (gol == 1) return 864500;
                if (gol == 2) return 1294000;
                if (gol == 3) return 1779000;
            }
            if ((asal == "Halim" && tujuan == "Satelit") || (asal == "Satelit" && tujuan == "Halim")) {
                jarak = 787;
                if (gol == 1) return 866000;
                if (gol == 2) return 1297000;
                if (gol == 3) return 1783000;
            }
            if ((asal == "Halim" && tujuan == "Kertosono") || (asal == "Kertosono" && tujuan == "Halim")) {
                jarak = 791;
                if (gol == 1) return 869500;
                if (gol == 2) return 1302000;
                if (gol == 3) return 1794000;
            }
            // Dari atau ke Semanggi
            if ((asal == "Semanggi" && tujuan == "Dupak") || (asal == "Dupak" && tujuan == "Semanggi")) {
                jarak = 783;
                if (gol == 1) return 862000;
                if (gol == 2) return 1290000;
                if (gol == 3) return 1776000;
            }
            if ((asal == "Semanggi" && tujuan == "Sidoarjo") || (asal == "Sidoarjo" && tujuan == "Semanggi")) {
                jarak = 785;
                if (gol == 1) return 863500;
                if (gol == 2) return 1292000;
                if (gol == 3) return 1778000;
            }
            if ((asal == "Semanggi" && tujuan == "Waru") || (asal == "Waru" && tujuan == "Semanggi")) {
                jarak = 786;
                if (gol == 1) return 865000;
                if (gol == 2) return 1294000;
                if (gol == 3) return 1780000;
            }
            if ((asal == "Semanggi" && tujuan == "Waru Gunung") || (asal == "Waru Gunung" && tujuan == "Semanggi")) {
                jarak = 787;
                if (gol == 1) return 866500;
                if (gol == 2) return 1296000;
                if (gol == 3) return 1782000;
            }
            if ((asal == "Semanggi" && tujuan == "Satelit") || (asal == "Satelit" && tujuan == "Semanggi")) {
                jarak = 789;
                if (gol == 1) return 868000;
                if (gol == 2) return 1299000;
                if (gol == 3) return 1785000;
            }
            if ((asal == "Semanggi" && tujuan == "Kertosono") || (asal == "Kertosono" && tujuan == "Semanggi")) {
                jarak = 793;
                if (gol == 1) return 871500;
                if (gol == 2) return 1304000;
                if (gol == 3) return 1795000;
            }
            // Dari atau ke Tanjung Priok
            if ((asal == "Tanjung Priok" && tujuan == "Dupak") || (asal == "Dupak" && tujuan == "Tanjung Priok")) {
                jarak = 784;
                if (gol == 1) return 863000;
                if (gol == 2) return 1291000;
                if (gol == 3) return 1777000;
            }
            if ((asal == "Tanjung Priok" && tujuan == "Sidoarjo") || (asal == "Sidoarjo" && tujuan == "Tanjung Priok")) {
                jarak = 786;
                if (gol == 1) return 864500;
                if (gol == 2) return 1293000;
                if (gol == 3) return 1779000;
            }
            if ((asal == "Tanjung Priok" && tujuan == "Waru") || (asal == "Waru" && tujuan == "Tanjung Priok")) {
                jarak = 787;
                if (gol == 1) return 866000;
                if (gol == 2) return 1295000;
                if (gol == 3) return 1781000;
            }
            if ((asal == "Tanjung Priok" && tujuan == "Waru Gunung") || (asal == "Waru Gunung" && tujuan == "Tanjung Priok")) {
                jarak = 788;
                if (gol == 1) return 867500;
                if (gol == 2) return 1297000;
                if (gol == 3) return 1783000;
            }
            if ((asal == "Tanjung Priok" && tujuan == "Satelit") || (asal == "Satelit" && tujuan == "Tanjung Priok")) {
                jarak = 790;
                if (gol == 1) return 869000;
                if (gol == 2) return 1300000;
                if (gol == 3) return 1786000;
            }
            if ((asal == "Tanjung Priok" && tujuan == "Kertosono") || (asal == "Kertosono" && tujuan == "Tanjung Priok")) {
                jarak = 794;
                if (gol == 1) return 872500;
                if (gol == 2) return 1305000;
                if (gol == 3) return 1796000;
            }
        }

        // Dari Bandung ke Surabaya atau Surabaya ke Bandung
        if ((kotaAsal == "Bandung" && kotaTujuan == "Surabaya") || (kotaAsal == "Surabaya" && kotaTujuan == "Bandung")) {
            // Dari atau ke Pasteur
            if ((asal == "Pasteur" && tujuan == "Dupak") || (asal == "Dupak" && tujuan == "Pasteur")) {
                jarak = 683;
                if (gol == 1) return 891000;
                if (gol == 2) return 1155000;
                if (gol == 3) return 1570000;
            }
            if ((asal == "Pasteur" && tujuan == "Sidoarjo") || (asal == "Sidoarjo" && tujuan == "Pasteur")) {
                jarak = 685;
                if (gol == 1) return 893500;
                if (gol == 2) return 1158000;
                if (gol == 3) return 1574000;
            }
            if ((asal == "Pasteur" && tujuan == "Waru") || (asal == "Waru" && tujuan == "Pasteur")) {
                jarak = 686;
                if (gol == 1) return 895000;
                if (gol == 2) return 1160000;
                if (gol == 3) return 1576000;
            }
            if ((asal == "Pasteur" && tujuan == "Waru Gunung") || (asal == "Waru Gunung" && tujuan == "Pasteur")) {
                jarak = 687;
                if (gol == 1) return 896500;
                if (gol == 2) return 1162000;
                if (gol == 3) return 1578000;
            }
            if ((asal == "Pasteur" && tujuan == "Satelit") || (asal == "Satelit" && tujuan == "Pasteur")) {
                jarak = 689;
                if (gol == 1) return 898000;
                if (gol == 2) return 1165000;
                if (gol == 3) return 1581000;
            }
            if ((asal == "Pasteur" && tujuan == "Kertosono") || (asal == "Kertosono" && tujuan == "Pasteur")) {
                jarak = 693;
                if (gol == 1) return 901500;
                if (gol == 2) return 1170000;
                if (gol == 3) return 1590000;
            }
            // Dari atau ke Pasir Koja
            if ((asal == "Pasir Koja" && tujuan == "Dupak") || (asal == "Dupak" && tujuan == "Pasir Koja")) {
                jarak = 684;
                if (gol == 1) return 892000;
                if (gol == 2) return 1156000;
                if (gol == 3) return 1572000;
            }
            if ((asal == "Pasir Koja" && tujuan == "Sidoarjo") || (asal == "Sidoarjo" && tujuan == "Pasir Koja")) {
                jarak = 686;
                if (gol == 1) return 894500;
                if (gol == 2) return 1159000;
                if (gol == 3) return 1575000;
            }
            if ((asal == "Pasir Koja" && tujuan == "Waru") || (asal == "Waru" && tujuan == "Pasir Koja")) {
                jarak = 687;
                if (gol == 1) return 896000;
                if (gol == 2) return 1161000;
                if (gol == 3) return 1577000;
            }
            if ((asal == "Pasir Koja" && tujuan == "Waru Gunung") || (asal == "Waru Gunung" && tujuan == "Pasir Koja")) {
                jarak = 688;
                if (gol == 1) return 897500;
                if (gol == 2) return 1163000;
                if (gol == 3) return 1579000;
            }
            if ((asal == "Pasir Koja" && tujuan == "Satelit") || (asal == "Satelit" && tujuan == "Pasir Koja")) {
                jarak = 690;
                if (gol == 1) return 899000;
                if (gol == 2) return 1166000;
                if (gol == 3) return 1582000;
            }
            if ((asal == "Pasir Koja" && tujuan == "Kertosono") || (asal == "Kertosono" && tujuan == "Pasir Koja")) {
                jarak = 694;
                if (gol == 1) return 902500;
                if (gol == 2) return 1171000;
                if (gol == 3) return 1591000;
            }
            // Dari atau ke Kopo
            if ((asal == "Kopo" && tujuan == "Dupak") || (asal == "Dupak" && tujuan == "Kopo")) {
                jarak = 685;
                if (gol == 1) return 893000;
                if (gol == 2) return 1157000;
                if (gol == 3) return 1573000;
            }
            if ((asal == "Kopo" && tujuan == "Sidoarjo") || (asal == "Sidoarjo" && tujuan == "Kopo")) {
                jarak = 687;
                if (gol == 1) return 895500;
                if (gol == 2) return 1160000;
                if (gol == 3) return 1576000;
            }
            if ((asal == "Kopo" && tujuan == "Waru") || (asal == "Waru" && tujuan == "Kopo")) {
                jarak = 688;
                if (gol == 1) return 897000;
                if (gol == 2) return 1162000;
                if (gol == 3) return 1578000;
            }
            if ((asal == "Kopo" && tujuan == "Waru Gunung") || (asal == "Waru Gunung" && tujuan == "Kopo")) {
                jarak = 689;
                if (gol == 1) return 898500;
                if (gol == 2) return 1164000;
                if (gol == 3) return 1580000;
            }
            if ((asal == "Kopo" && tujuan == "Satelit") || (asal == "Satelit" && tujuan == "Kopo")) {
                jarak = 691;
                if (gol == 1) return 900000;
                if (gol == 2) return 1167000;
                if (gol == 3) return 1583000;
            }
            if ((asal == "Kopo" && tujuan == "Kertosono") || (asal == "Kertosono" && tujuan == "Kopo")) {
                jarak = 695;
                if (gol == 1) return 903500;
                if (gol == 2) return 1172000;
                if (gol == 3) return 1593000;
            }
            // Dari atau ke Moh Toha
            if ((asal == "Moh Toha" && tujuan == "Dupak") || (asal == "Dupak" && tujuan == "Moh Toha")) {
                jarak = 686;
                if (gol == 1) return 894000;
                if (gol == 2) return 1158000;
                if (gol == 3) return 1574000;
            }
            if ((asal == "Moh Toha" && tujuan == "Sidoarjo") || (asal == "Sidoarjo" && tujuan == "Moh Toha")) {
                jarak = 688;
                if (gol == 1) return 896500;
                if (gol == 2) return 1161000;
                if (gol == 3) return 1577000;
            }
            if ((asal == "Moh Toha" && tujuan == "Waru") || (asal == "Waru" && tujuan == "Moh Toha")) {
                jarak = 689;
                if (gol == 1) return 898000;
                if (gol == 2) return 1163000;
                if (gol == 3) return 1579000;
            }
            if ((asal == "Moh Toha" && tujuan == "Waru Gunung") || (asal == "Waru Gunung" && tujuan == "Moh Toha")) {
                jarak = 690;
                if (gol == 1) return 899500;
                if (gol == 2) return 1165000;
                if (gol == 3) return 1581000;
            }
            if ((asal == "Moh Toha" && tujuan == "Satelit") || (asal == "Satelit" && tujuan == "Moh Toha")) {
                jarak = 692;
                if (gol == 1) return 901000;
                if (gol == 2) return 1168000;
                if (gol == 3) return 1584000;
            }
            if ((asal == "Moh Toha" && tujuan == "Kertosono") || (asal == "Kertosono" && tujuan == "Moh Toha")) {
                jarak = 696;
                if (gol == 1) return 904500;
                if (gol == 2) return 1173000;
                if (gol == 3) return 1594000;
            }
            // Dari atau ke Buah Batu
            if ((asal == "Buah Batu" && tujuan == "Dupak") || (asal == "Dupak" && tujuan == "Buah Batu")) {
                jarak = 688;
                if (gol == 1) return 896000;
                if (gol == 2) return 1160000;
                if (gol == 3) return 1575000;
            }
            if ((asal == "Buah Batu" && tujuan == "Sidoarjo") || (asal == "Sidoarjo" && tujuan == "Buah Batu")) {
                jarak = 690;
                if (gol == 1) return 898000;
                if (gol == 2) return 1163000;
                if (gol == 3) return 1578000;
            }
            if ((asal == "Buah Batu" && tujuan == "Waru") || (asal == "Waru" && tujuan == "Buah Batu")) {
                jarak = 691;
                if (gol == 1) return 899500;
                if (gol == 2) return 1165000;
                if (gol == 3) return 1580000;
            }
            if ((asal == "Buah Batu" && tujuan == "Waru Gunung") || (asal == "Waru Gunung" && tujuan == "Buah Batu")) {
                jarak = 692;
                if (gol == 1) return 901000;
                if (gol == 2) return 1167000;
                if (gol == 3) return 1582000;
            }
            if ((asal == "Buah Batu" && tujuan == "Satelit") || (asal == "Satelit" && tujuan == "Buah Batu")) {
                jarak = 694;
                if (gol == 1) return 903000;
                if (gol == 2) return 1170000;
                if (gol == 3) return 1585000;
            }
            if ((asal == "Buah Batu" && tujuan == "Kertosono") || (asal == "Kertosono" && tujuan == "Buah Batu")) {
                jarak = 698;
                if (gol == 1) return 906500;
                if (gol == 2) return 1175000;
                if (gol == 3) return 1596000;
            }
            // Dari atau ke Cileunyi
            if ((asal == "Cileunyi" && tujuan == "Dupak") || (asal == "Dupak" && tujuan == "Cileunyi")) {
                jarak = 682;
                if (gol == 1) return 890000;
                if (gol == 2) return 1153000;
                if (gol == 3) return 1568500;
            }
            if ((asal == "Cileunyi" && tujuan == "Sidoarjo") || (asal == "Sidoarjo" && tujuan == "Cileunyi")) {
                jarak = 684;
                if (gol == 1) return 892500;
                if (gol == 2) return 1156000;
                if (gol == 3) return 1571000;
            }
            if ((asal == "Cileunyi" && tujuan == "Waru") || (asal == "Waru" && tujuan == "Cileunyi")) {
                jarak = 685;
                if (gol == 1) return 894000;
                if (gol == 2) return 1158000;
                if (gol == 3) return 1573000;
            }
            if ((asal == "Cileunyi" && tujuan == "Waru Gunung") || (asal == "Waru Gunung" && tujuan == "Cileunyi")) {
                jarak = 686;
                if (gol == 1) return 895500;
                if (gol == 2) return 1160000;
                if (gol == 3) return 1575000;
            }
            if ((asal == "Cileunyi" && tujuan == "Satelit") || (asal == "Satelit" && tujuan == "Cileunyi")) {
                jarak = 688;
                if (gol == 1) return 897500;
                if (gol == 2) return 1163000;
                if (gol == 3) return 1578000;
            }
            if ((asal == "Cileunyi" && tujuan == "Kertosono") || (asal == "Kertosono" && tujuan == "Cileunyi")) {
                jarak = 692;
                if (gol == 1) return 901000;
                if (gol == 2) return 1168000;
                if (gol == 3) return 1588000;
            }
        }

        jarak = 0;
        return -1;
    }

    void TampilkanSemuaData() {
        if (jumlahData == 0) {
            cout << "Belum ada data perjalanan yang tercatat.\n";
            return;
        }

        int total = 0;
        int totalJarak = 0;

        cout << "\n=========== RINCIAN BIAYA PERJALANAN ===========\n";
        for (int i = 0; i < jumlahData; i++) {
            cout << i + 1 << ". ";
            if (estimasi[i].gerbang_asal != "-" && estimasi[i].gerbang_tujuan != "-") {
                cout << estimasi[i].kota_asal << " (" << estimasi[i].gerbang_asal << ") --> "
                    << estimasi[i].kota_tujuan << " (" << estimasi[i].gerbang_tujuan << ")";
            } else {
                cout << estimasi[i].kota_asal << " --> " << estimasi[i].kota_tujuan;
            }
            cout << " | Biaya: Rp." << estimasi[i].biaya;
            cout << " | Jarak: " << estimasi[i].jarak << " km\n";

            total += estimasi[i].biaya;
            totalJarak += estimasi[i].jarak;
        }

        cout << "\n================ TOTAL ESTIMASI ================\n";
        cout << "Total Biaya: Rp." << total << endl;
        cout << "Total Jarak: " << totalJarak << " km";
        cout << "\nHati-hati di jalan. Semoga selamat sampai tujuan.\n";
    }
    
public:
    void run() {
        jumlahData = 0;
        int pilihan;
        char ulang;
        int golongan;

        cout << "========== HITUNG ESTIMASI BIAYA TOL ==========\n";
        do {
            cout << "Masukkan golongan kendaraan Anda (1-3): ";
            cin >> golongan;
            if (golongan < 1 || golongan > 3) {
                cout << "Golongan kendaraan tidak valid!\n\n";
            }
        } while (golongan < 1 || golongan > 3);
        cin.ignore();

        do {
            cout << "\n========== PILIH KATEGORI PERJALANAN ==========\n";
            do {
                cout << "1. Perjalanan dalam kota\n";
                cout << "2. Perjalanan antar kota\n";
                cout << "Pilihan (1/2): ";
                cin >> pilihan;
                if (pilihan != 1 && pilihan != 2) {
                    cout << "Pilihan tidak valid!\n\n";
                }
            } while (pilihan != 1 && pilihan != 2);
            cin.ignore();

            estimasi[jumlahData].golongan = golongan;

            if (pilihan == 1) {
                cout << "\n============ PERJALANAN DALAM KOTA ============\n";
                do {
                    cout << "Pilih kota (Jakarta/Bandung/Surabaya): ";
                    getline(cin, estimasi[jumlahData].kota_asal);
                    estimasi[jumlahData].kota_asal = ToTitleCase(estimasi[jumlahData].kota_asal);

                    if (estimasi[jumlahData].kota_asal == "Jakarta" || estimasi[jumlahData].kota_asal == "Bandung" || estimasi[jumlahData].kota_asal == "Surabaya") {
                        break;
                    } else {
                        cout << "Mohon maaf, pilihan kota belum tersedia.\n";
                    }                    
                } while (true);

                TampilkanGerbangTol(estimasi[jumlahData].kota_asal);
                cout << "Gerbang asal: ";
                getline(cin, estimasi[jumlahData].gerbang_asal);
                estimasi[jumlahData].gerbang_asal = ToTitleCase(estimasi[jumlahData].gerbang_asal);
                cout << "Gerbang tujuan: ";
                getline(cin, estimasi[jumlahData].gerbang_tujuan);
                estimasi[jumlahData].gerbang_tujuan = ToTitleCase(estimasi[jumlahData].gerbang_tujuan);

                estimasi[jumlahData].biaya = TarifTolDalamKota(estimasi[jumlahData].gerbang_asal, estimasi[jumlahData].gerbang_tujuan, estimasi[jumlahData].golongan, estimasi[jumlahData].jarak);
            } else {
                cout << "\n============ PERJALANAN ANTAR KOTA ============\n";
                do {
                    cout << "Pilih kota asal (Jakarta/Bandung/Surabaya): ";
                    getline(cin, estimasi[jumlahData].kota_asal);
                    estimasi[jumlahData].kota_asal = ToTitleCase(estimasi[jumlahData].kota_asal);

                    if (estimasi[jumlahData].kota_asal == "Jakarta" || estimasi[jumlahData].kota_asal == "Bandung" || estimasi[jumlahData].kota_asal == "Surabaya") {
                        break;
                    } else {
                        cout << "Mohon maaf, pilihan kota belum tersedia.\n";
                    }                    
                } while (true);

                TampilkanGerbangTol(estimasi[jumlahData].kota_asal);
                cout << "Gerbang asal: ";
                getline(cin, estimasi[jumlahData].gerbang_asal);
                estimasi[jumlahData].gerbang_asal = ToTitleCase(estimasi[jumlahData].gerbang_asal);

                do {
                    cout << "Pilih kota tujuan (Jakarta/Bandung/Surabaya): ";
                    getline(cin, estimasi[jumlahData].kota_tujuan);
                    estimasi[jumlahData].kota_tujuan = ToTitleCase(estimasi[jumlahData].kota_tujuan);

                    if (estimasi[jumlahData].kota_tujuan == "Jakarta" || estimasi[jumlahData].kota_tujuan == "Bandung" || estimasi[jumlahData].kota_tujuan == "Surabaya") {
                        break;
                    } else {
                        cout << "Mohon maaf, pilihan kota belum tersedia.\n";
                    }                    
                } while (true);                

                TampilkanGerbangTol(estimasi[jumlahData].kota_tujuan);
                cout << "Gerbang tujuan: ";
                getline(cin, estimasi[jumlahData].gerbang_tujuan);
                estimasi[jumlahData].gerbang_tujuan = ToTitleCase(estimasi[jumlahData].gerbang_tujuan);

                estimasi[jumlahData].biaya = TarifTolAntarKota(estimasi[jumlahData].gerbang_asal, estimasi[jumlahData].gerbang_tujuan, estimasi[jumlahData].kota_asal, estimasi[jumlahData].kota_tujuan, estimasi[jumlahData].golongan, estimasi[jumlahData].jarak);
            }

            if (estimasi[jumlahData].biaya == -1) {
                cout << "Rute tidak ditemukan. Periksa kembali gerbang asal dan tujuan.\n";
            } 
            else if (estimasi[jumlahData].biaya == 800000 || estimasi[jumlahData].biaya == 1200000 || estimasi[jumlahData].biaya == 1600000) {
                cout << "!!! MASUK DAN KELUAR DARI GERBANG YANG SAMA !!!\n";
                cout << "Biaya denda: Rp " << estimasi[jumlahData].biaya << endl;
            } 
            else {
                cout << "Biaya: Rp " << estimasi[jumlahData].biaya << endl;
                cout << "Jarak: " << estimasi[jumlahData].jarak << " km" << endl;
            }

            jumlahData++;

            cout << "Tambah rute perjalanan lagi? (y/t): ";
            cin >> ulang;
            cin.ignore();
        } while (ulang == 'y');

        TampilkanSemuaData();
    }
};

int main() {
    GerbangTol app;
    app.run();
    return 0;
}