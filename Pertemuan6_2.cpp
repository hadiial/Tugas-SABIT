#include <iostream>
using namespace std;

int main() {
    const int m = 2, n = 3;
    int A[m][n];
    int cari;
    bool ditemukan = false;

    cout << "Masukkan elemen-elemen matriks " << m << "x" << n << ":\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Elemen 4
            [" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    int maks = A[0][0];
    int mins = A[0][0];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] > maks) {
                maks = A[i][j];
            }
            if (A[i][j] < mins) {
                mins = A[i][j];
            }
        }
    }

    cout << "Elemen terbesar: " << maks << endl;
    cout << "Elemen terkecil: " << mins << endl;

    cout << "Masukkan elemen yang ingin dicari: ";
    cin >> cari;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == cari) {
                ditemukan = true;
                break;
            }
        }
    }

    if (ditemukan) {
        cout << "Elemen ditemukan pada matriks\n";
    } else {
        cout << "Elemen tidak ditemukan pada matriks\n";
    }

    return 0;
}
