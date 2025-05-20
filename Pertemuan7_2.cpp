#include <iostream>
using namespace std;

int main()
{
    const int m = 2, n = 3;
    int A[m][n];

    cout << "Masukkan elemen-elemen matriks: \n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Elemen [" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    int maks = A[0][0];
    int mins = A[0][0];
    int cari;
    bool ditemukan = false;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] > maks)
                maks = A[i][j];
            if (A[i][j] < mins)
                mins = A[i][j];
        }
    }

    cout << "Elemen terbesar: " << maks << endl;
    cout << "Elemen terkecil: " << mins << endl;

    cout << "\nMasukkan elemen yang ingin dicari: ";
    cin >> cari;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == cari)
            {
                ditemukan = true;
                break;
            }
        }
    }

    if (ditemukan)
        cout << "Elemen ditemukan pada matriks\n";
    else
        cout << "Elemen tidak ditemukan pada matriks\n";

    return 0;
}
