#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int jumlahSimpul_2311102149;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> jumlahSimpul_2311102149;

    vector<string> namaSimpul(jumlahSimpul_2311102149);
    vector<vector<int>> matriksBobot(jumlahSimpul_2311102149, vector<int>(jumlahSimpul_2311102149));

    // Input nama-nama simpul
    for (int i = 0; i < jumlahSimpul_2311102149; ++i) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> namaSimpul[i];
    }

    // Input bobot antar simpul, termasuk bobot dari kota ke kota itu sendiri
    for (int i = 0; i < jumlahSimpul_2311102149; ++i) {
        for (int j = 0; j < jumlahSimpul_2311102149; ++j) {
            cout << namaSimpul[i] << "--> " << namaSimpul[j] << " = ";
            cin >> matriksBobot[i][j];
        }
    }

    // Cetak header matriks
    cout << "\n\t";
    for (int i = 0; i < jumlahSimpul_2311102149; ++i) {
        cout << namaSimpul[i] << "\t";
    }
    cout << endl;

    // Cetak baris dan kolom matriks
    for (int i = 0; i < jumlahSimpul_2311102149; ++i) {
        cout << namaSimpul[i] << "\t";
        for (int j = 0; j < jumlahSimpul_2311102149; ++j) {
            cout << matriksBobot[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
