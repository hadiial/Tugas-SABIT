#include <iostream>
using namespace std;

int main() {
    int A[5] = {1,1,1,1,1};
    bool cek = true;

    for (int i = 0; i < 5; i++) {
        if (A[0] != A[i]) {
            cek = false;
            break;
        }
    }

    if (cek == true) {
        cout << "Semua elemen pada array sama\n";
    } else {
        cout << "Tidak semua elemen pada array sama\n";
    }
    
  return 0;
}