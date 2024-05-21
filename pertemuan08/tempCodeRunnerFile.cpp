#include <iostream>
#include <vector>
#include <algorithm>

// Fungsi untuk melakukan binary search dan mengembalikan indeks jika ditemukan
int binarySearch(const std::vector<char>& sortedVec, char target) {
    int left = 0;
    int right = sortedVec.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (sortedVec[mid] == target) {
            return mid; // Huruf ditemukan
        }
        if (sortedVec[mid] < target) {
            left = mid + 1; // Cari di sisi kanan
        } else {
            right = mid - 1; // Cari di sisi kiri
        }
    }

    return -1; // Huruf tidak ditemukan
}

int main() {
    std::string input;
    char target;

    // Meminta input dari pengguna
    std::cout << "Masukkan sebuah kalimat: ";
    std::getline(std::cin, input);

    std::cout << "Masukkan huruf yang ingin dicari: ";
    std::cin >> target;

    // Mengubah string menjadi vector char
    std::vector<char> charVec(input.begin(), input.end());
    
    // Menghapus spasi dari vektor
    charVec.erase(std::remove(charVec.begin(), charVec.end(), ' '), charVec.end());

    // Menyimpan indeks asli dari setiap huruf sebelum diurutkan
    std::vector<int> originalIndices(charVec.size());
    for (size_t i = 0; i < charVec.size(); ++i) {
        originalIndices[i] = i;
    }

    // Mengurutkan vektor berdasarkan huruf dan mempertahankan indeks asli
    std::sort(originalIndices.begin(), originalIndices.end(), 
        [&charVec](int a, int b) { return charVec[a] < charVec[b]; });

    std::vector<char> sortedVec = charVec;
    std::sort(sortedVec.begin(), sortedVec.end());

    // Mencetak vektor terurut
    std::cout << "Kalimat setelah diurutkan: ";
    for (char c : sortedVec) {
        std::cout << c;
    }
    std::cout << std::endl;

    // Melakukan binary search
    int sortedIndex = binarySearch(sortedVec, target);

    if (sortedIndex != -1) {
        int originalIndex = originalIndices[sortedIndex];
        std::cout << "Huruf '" << target << "' ditemukan dalam kalimat pada posisi terurut ke-" 
                  << sortedIndex << " dan indeks asli ke-" << originalIndex << "." << std::endl;
    } else {
        std::cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << std::endl;
    }

    return 0;
}
