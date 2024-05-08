#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk membalikkan kalimat menggunakan stack
string reverseSentence_149(string sentence_149) {
    stack<char> charStack_149;
    string reversedSentence_149 = "";

    // Push setiap karakter ke dalam stack
    for (char c_149 : sentence_149) {
        if (c_149 != ' ') {
            charStack_149.push(c_149);
        } else {
            // Ketika menemukan spasi, pop karakter dari stack dan tambahkan ke kalimat terbalik
            while (!charStack_149.empty()) {
                reversedSentence_149 += charStack_149.top();
                charStack_149.pop();
            }
            // Tambahkan spasi
            reversedSentence_149 += ' ';
        }
    }

    // Push sisa karakter ke dalam stack (untuk kata terakhir)
    while (!charStack_149.empty()) {
        reversedSentence_149 += charStack_149.top();
        charStack_149.pop();
    }

    return reversedSentence_149;
}

int main() {
    string kalimat_149, hasil_149;

    do {
        cout << "Masukkan kalimat (minimal 3 kata): ";
        getline(cin, kalimat_149);

        // Periksa jika kalimat kurang dari 3 kata
        if (kalimat_149.find(' ') == string::npos || kalimat_149.find(' ') == kalimat_149.rfind(' ')) {
            cout << "Kalimat harus memiliki minimal 3 kata. Silakan coba lagi." << endl;
        }
    } while (kalimat_149.find(' ') == string::npos || kalimat_149.find(' ') == kalimat_149.rfind(' ')); // Ulangi input jika kalimat kurang dari 3 kata

    hasil_149 = reverseSentence_149(kalimat_149);

    cout << "Hasil pembalikan: " << hasil_149 << endl;

    return 0;
}
