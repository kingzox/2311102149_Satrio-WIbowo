#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

// Struktur data untuk mahasiswa
struct Mahasiswa {
    string nim_149;
    string nama_149;
    int nilai;
};

// Ukuran tabel hash
const int hash_size = 10;

// Class Hash Table
class HashTable {
private:
    list<Mahasiswa> table[hash_size];

    // Fungsi hash
    int hashFunction(const string& key) {
        int sum = 0;
        for (char c : key) {
            sum += c;
        }
        return sum % hash_size;
    }

public:
    // Fungsi untuk menambahkan data baru
    void tambahData(const string& nama_149, const string& nim_149, int nilai) {
        Mahasiswa mhs;
        mhs.nim_149 = nim_149;
        mhs.nama_149 = nama_149;
        mhs.nilai = nilai;
        int index = hashFunction(nim_149);
        table[index].push_back(mhs);
    }

    // Fungsi untuk menghapus data
    void hapusData(const string& nim_149) {
        int index = hashFunction(nim_149);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->nim_149 == nim_149) {
                table[index].erase(it);
                break;
            }
        }
    }

    // Fungsi untuk mencari data berdasarkan NIM
    Mahasiswa* cariDataNIM(const string& nim_149) {
        int index = hashFunction(nim_149);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->nim_149 == nim_149) {
                return &(*it);
            }
        }
        return nullptr;
    }

    // Fungsi untuk mencari data berdasarkan rentang nilai
    void cariDataNilai(int nilai_min, int nilai_max) {
        for (int i = 0; i < hash_size; ++i) {
            for (auto it = table[i].begin(); it != table[i].end(); ++it) {
                if (it->nilai >= nilai_min && it->nilai <= nilai_max) {
                    cout << "NIM: " << it->nim_149 << ", Nama: " << it->nama_149 << ", Nilai: " << it->nilai << endl;
                }
            }
        }
    }

    // Fungsi untuk menampilkan semua data
    void tampilkanData() {
        cout << setw(10) << "NIM" << setw(20) << "Nama" << setw(10) << "Nilai" << endl;
        for (int i = 0; i < hash_size; ++i) {
            for (auto it = table[i].begin(); it != table[i].end(); ++it) {
                cout << setw(10) << it->nim_149 << setw(20) << it->nama_149 << setw(10) << it->nilai << endl;
            }
        }
    }
};

int main() {
    HashTable hashTable;

    // Menu
    int choice;
    do {
        cout << "\n========== Program Manajemen Data Mahasiswa ==========\n";
        cout << "Menu:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Hapus Data Mahasiswa\n";
        cout << "3. Cari Data Mahasiswa berdasarkan NIM\n";
        cout << "4. Cari Data Mahasiswa berdasarkan Rentang Nilai\n";
        cout << "5. Tampilkan Semua Data Mahasiswa\n";
        cout << "6. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    cout << "\n========== Tambah Data Mahasiswa ==========\n";
                    string nim_149, nama_149;
                    int nilai;
                    cout << "Masukkan nama mahasiswa: ";
                    cin.ignore(); // clear newline character from buffer
                    getline(cin, nama_149);
                    cout << "Masukkan NIM mahasiswa: ";
                    cin >> nim_149;
                    cout << "Masukkan nilai mahasiswa: ";
                    cin >> nilai;
                    hashTable.tambahData(nama_149, nim_149, nilai);
                }
                break;
            case 2:
                {
                    cout << "\n========== Hapus Data Mahasiswa ==========\n";
                    string nim_149;
                    cout << "Masukkan NIM data mahasiswa yang ingin dihapus: ";
                    cin >> nim_149;
                    hashTable.hapusData(nim_149);
                }
                break;
            case 3:
                {
                    cout << "\n========== Cari Data Mahasiswa berdasarkan NIM ==========\n";
                    string nim_149;
                    cout << "Masukkan NIM data mahasiswa yang ingin dicari: ";
                    cin >> nim_149;
                    {
                        Mahasiswa* mhs = hashTable.cariDataNIM(nim_149);
                        if (mhs != nullptr) {
                            cout << "Data ditemukan: NIM=" << mhs->nim_149 << ", Nama=" << mhs->nama_149 << ", Nilai=" << mhs->nilai << endl;
                        } else {
                            cout << "Data tidak ditemukan.\n";
                        }
                    }
                }
                break;
            case 4:
                {
                    cout << "\n========== Cari Data Mahasiswa berdasarkan Rentang Nilai ==========\n";
                    int nilai_min, nilai_max;
                    cout << "Masukkan nilai minimum: ";
                    cin >> nilai_min;
                    cout << "Masukkan nilai maksimum: ";
                    cin >> nilai_max;
                    hashTable.cariDataNilai(nilai_min, nilai_max);
                }
                break;
            case 5:
                cout << "\n========== Tampilkan Semua Data Mahasiswa ==========\n";
                hashTable.tampilkanData();
                break;
            case 6:
                cout << "Anda telah keluar dari program\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
