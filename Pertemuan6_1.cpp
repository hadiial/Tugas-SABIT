#include <iostream>
using namespace std;

int main()
{
    int N = 5;
    int A[N];
    bool cek = true;

    for (int i = 0; i < N; i++)
    {
        cout << "Masukkan elemen ke-" << i + 1 << ": ";
        cin >> A[i];
    }

    for (int i = 1; i < N; i++)
    {
        if (A[0] != A[i])
        {
            cek = false;
            break;
        }
    }

    if (cek == true)
    {
        cout << "Semua elemen pada array sama\n";
    }
    else
    {
        cout << "Tidak semua elemen pada array sama\n";
    }

    return 0;
}