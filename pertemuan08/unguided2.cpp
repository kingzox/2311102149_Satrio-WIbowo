#include <iostream> 
#include <string> 
#include <algorithm> 

using namespace std;

// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat
int hitungHurufVokal_149(const string& kalimat_149, string& hurufVokalDitemukan_149) {
    int jumlah_149 = 0;
    string vokal_149 = "aiueoAIUEO"; // Huruf vokal

    // Menggunakan fungsi count_if dari <algorithm> untuk menghitung jumlah huruf vokal dalam kalimat
    jumlah_149 = count_if(kalimat_149.begin(), kalimat_149.end(), [&](char c_149) {
        if (vokal_149.find(c_149) != string::npos) {
            if (!hurufVokalDitemukan_149.empty()) {
                hurufVokalDitemukan_149 += ", "; // Menambahkan tanda koma jika sudah ada huruf vokal sebelumnya
            }
            hurufVokalDitemukan_149 += c_149; // Menambahkan huruf vokal yang ditemukan ke dalam string hurufVokalDitemukan
            return true;
        }
        return false;
    });

    return jumlah_149;
}

int main() {
    string kalimat_149;
    string hurufVokalDitemukan_149;
    char lanjut_149;

    cout<<"=========================================\n";
    cout<<"  FIND THE VOCAL LETTERS IN A SENTENCE\n";
    cout<<"=========================================\n";

    do {
        // Meminta user memasukkan kalimat
        cout << "Masukkan sebuah kalimat: ";
        getline(cin, kalimat_149);

        // Menghitung jumlah huruf vokal dalam kalimat dan menambahkan huruf vokal yang ditemukan ke dalam hurufVokalDitemukan
        int jumlahHurufVokal_149 = hitungHurufVokal_149(kalimat_149, hurufVokalDitemukan_149);

        // Menampilkan hasil
        cout << "Jumlah huruf vokal dalam kalimat adalah: " << jumlahHurufVokal_149 << endl;
        if (jumlahHurufVokal_149 > 0) {
            cout << "Huruf vokal yang ditemukan dalam kalimat: " << hurufVokalDitemukan_149 << endl;
        }

        // Meminta user apakah ingin melanjutkan atau tidak
        cout << "Apakah Anda ingin mencoba pada kalimat lainnya? (y/n): ";
        cin >> lanjut_149;
        cin.ignore(); // Mengabaikan newline character yang tersisa di input stream
    } while (lanjut_149 == 'y' || lanjut_149 == 'Y');

    return 0;
}
