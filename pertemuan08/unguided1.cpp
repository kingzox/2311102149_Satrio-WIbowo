#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi untuk melakukan binary search pada string yang sudah diurutkan
bool binarySearch_149(const string &sorted_str_149, char target_149) {
    int left_149 = 0;
    int right_149 = sorted_str_149.length() - 1;

    while (left_149 <= right_149) {
        int mid_149 = left_149 + (right_149 - left_149) / 2;

        if (sorted_str_149[mid_149] == target_149) {
            return true;  // Huruf ditemukan
        }
        if (sorted_str_149[mid_149] < target_149) {
            left_149 = mid_149 + 1;
        } else {
            right_149 = mid_149 - 1;
        }
    }

    return false;  // Huruf tidak ditemukan
}

// Fungsi untuk mencari semua indeks dari huruf yang ditemukan dalam kalimat asli
vector<int> findIndices_149(const string &original_str_149, char target_149) {
    vector<int> indices_149;
    for (size_t i = 0; i < original_str_149.length(); ++i) {
        if (original_str_149[i] == target_149) {
            indices_149.push_back(i);
        }
    }
    return indices_149;
}

int main() {
    string input_149;
    char target_149;
    char choice_149;

    cout << "======================================================\n";
    cout << "                     BINARY SEARCH                    \n";
    cout << "      Mencari Huruf dari Inputan Sebuah Kalimat       \n";
    cout << "======================================================\n";

    do {
        // Meminta pengguna memasukkan kalimat
        cout << "Masukkan sebuah kalimat: ";
        getline(cin, input_149);

        // Meminta pengguna memasukkan huruf yang ingin dicari
        cout << "Masukkan huruf yang ingin dicari: ";
        cin >> target_149;
        cin.ignore(); // Membersihkan buffer setelah input karakter

        // Membuat salinan kalimat asli untuk pencarian indeks
        string original_input_149 = input_149;

        // Mengurutkan string
        sort(input_149.begin(), input_149.end());

        // Mencetak kalimat yang sudah diurutkan (untuk tujuan debugging atau verifikasi)
        cout << "Kalimat yang sudah diurutkan: " << input_149 << endl;

        // Melakukan binary search
        bool found_149 = binarySearch_149(input_149, target_149);

        // Menampilkan hasil pencarian
        if (found_149) {
            cout << "Huruf '" << target_149 << "' ditemukan dalam kalimat." << endl;

            // Mencari dan menampilkan semua indeks dari huruf yang ditemukan
            vector<int> indices_149 = findIndices_149(original_input_149, target_149);
            cout << "Huruf '" << target_149 << "' terdapat pada index : ";
            for (size_t i = 0; i < indices_149.size(); ++i) {
                cout << indices_149[i];
                if (i < indices_149.size() - 1) {
                    cout << ", ";  // Menambahkan koma jika bukan indeks terakhir
                }
            }
            cout << endl;
        } else {
            cout << "Huruf '" << target_149 << "' tidak ditemukan dalam kalimat." << endl;
        }

        // Menanyakan pengguna apakah ingin mencoba kalimat lain
        cout << "Apakah Anda ingin mencoba kalimat lain? (y/n): ";
        cin >> choice_149;
        cin.ignore(); // Membersihkan buffer setelah input karakter

    } while (choice_149 == 'y' || choice_149 == 'Y');

    return 0;
}
