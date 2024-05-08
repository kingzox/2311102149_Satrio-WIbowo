#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cstdlib> // Untuk menggunakan system("cls") dan system("pause")

using namespace std;

bool isPalindrome_149(const string& sentence) {
    stack<char> charStack;
    string processedSentence;

    // Menghapus spasi dan mengubah huruf menjadi lowercase
    for (char c_149 : sentence) {
        if (!isspace(c_149)) {
            charStack.push(tolower(c_149));
            processedSentence.push_back(tolower(c_149));
        }
    }

    string reversedSentence;
    while (!charStack.empty()) {
        reversedSentence.push_back(charStack.top());
        charStack.pop();
    }

    return processedSentence == reversedSentence;
}

int main() {
    char choice_149 = ' ';
    string kalimat_149;
    
    do {
        cout << "Masukkan kalimat: ";
        getline(cin, kalimat_149);

        if (isPalindrome_149(kalimat_149)) {
            cout << "Kalimat ini adalah palindrom." << endl;
        } else {
            cout << "Kalimat ini bukan palindrom." << endl;
        }

        cout << "\nTekan Enter untuk melanjutkan atau ketik 'n' untuk keluar...";
        choice_149 = cin.get();
        cin.ignore(); // Membersihkan buffer

        // Membersihkan layar dan mengulang program jika Enter ditekan
        system("cls");
    } while (choice_149 != 'n' && choice_149 != 'N');

    cout << "Terima kasih telah menggunakan program!" << endl;

    // Menunggu untuk menekan tombol sebelum menutup program
    system("pause");
    
    return 0;
}
