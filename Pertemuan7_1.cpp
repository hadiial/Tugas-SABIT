#include <iostream>
using namespace std;

void hitungJumlahBilGenap(int N) {
    int jumlah = 0;
    for (int i = 0; i < N; i++) {
        jumlah += 2 * i;
    }
    cout << "Jumlah " << N << " bilangan genap pertama: " << jumlah << endl;
}

int main() {
    int N;
    cout << "Masukkan banyaknya bilangan: ";
    cin >> N;

    hitungJumlahBilGenap(N);

    return 0;
}