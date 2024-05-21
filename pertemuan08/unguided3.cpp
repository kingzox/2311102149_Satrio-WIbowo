#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk menghitung berapa banyak angka 4 dalam data menggunakan Sequential Search
int hitungAngkaEmpat_149(const vector<int>& data_149) {
    int count_149 = 0;
    int angka_149 = 4; // Angka yang ingin dicari

    for (int i_149 = 0; i_149 < data_149.size(); ++i_149) {
        if (data_149[i_149] == angka_149) {
            count_149++;
        }
    }

    return count_149;
}

int main() {
    // Data yang diberikan
    vector<int> data_149 = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};

    // Menghitung berapa banyak angka 4 dalam data menggunakan Sequential Search
    int jumlahAngkaEmpat_149 = hitungAngkaEmpat_149(data_149);

    // Menampilkan hasil
    cout << "Jumlah angka 4 dalam data adalah: " << jumlahAngkaEmpat_149 << endl;

    return 0;
}
