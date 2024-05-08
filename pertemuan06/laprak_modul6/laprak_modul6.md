  # <h1 align="center">Laporan Praktikum Modul 6 - STACK</h1>
<p align="center">Satrio Wibowo - 2311102149</p>


## Dasar Teori




## Guided

### 1. [Latihan Hash Table]

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();
    cout << "\n";

    destroyArraybuku();

    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}

```


Program tersebut menggunakan struktur data stack dengan prinsip LIFO (Last In, First Out), di mana elemen terakhir yang dimasukkan akan menjadi yang pertama kali dikeluarkan. Array arrayBuku digunakan untuk menyimpan data buku, dengan maksimal menunjukkan batas maksimal elemen yang dapat disimpan. top adalah variabel yang menunjukkan posisi teratas dalam stack. Fungsi isFull() digunakan untuk memeriksa apakah stack sudah penuh, sementara isEmpty() untuk memeriksa apakah stack kosong. Fungsi cetakArrayBuku() bertugas mencetak atau menampilkan semua data buku yang ada dalam stack.

Adapun beberapa fungsi dari setiap bagian program, yaitu:

- Deklarasi Variabel dan Array: Program mendeklarasikan sebuah array bernama arrayBuku yang memiliki kapasitas maksimal 5, serta variabel maksimal dan top. maksimal digunakan untuk menentukan batas maksimal elemen dalam stack, sedangkan top merupakan indeks dari elemen teratas dalam stack.
- Fungsi isFull() dan isEmpty(): Fungsi ini digunakan untuk memeriksa apakah stack penuh atau kosong. Jika top sama dengan maksimal, maka stack dianggap penuh. Sebaliknya, jika top sama dengan 0, maka stack dianggap kosong.
- Fungsi pushArrayBuku(): Fungsi ini digunakan untuk menambahkan elemen baru ke dalam stack. Jika stack belum penuh, elemen baru akan ditambahkan ke posisi top, kemudian nilai top akan ditambah 1.
- Fungsi popArrayBuku(): Fungsi ini digunakan untuk menghapus elemen teratas dari stack. Jika stack tidak kosong, elemen teratas (di posisi top - 1) akan dihapus dan nilai top akan dikurangi 1.
- Fungsi peekArrayBuku(): Fungsi ini digunakan untuk melihat nilai elemen pada posisi tertentu dalam stack tanpa menghapusnya. Fungsi ini melakukan iterasi mundur dari posisi top ke posisi yang ditentukan, kemudian menampilkan nilai elemen pada posisi tersebut.
- Fungsi countStack(): Fungsi ini mengembalikan jumlah elemen dalam stack, yaitu nilai dari variabel top.
- Fungsi changeArrayBuku(): Fungsi ini digunakan untuk mengubah nilai elemen pada posisi tertentu dalam stack. Jika posisi yang ditentukan valid (tidak melebihi jumlah elemen dalam stack), nilai elemen pada posisi tersebut akan diubah sesuai dengan input.
- Fungsi destroyArraybuku(): Fungsi ini menghapus semua elemen dalam stack dengan mengosongkan array dan mengatur top menjadi 0.
- Fungsi cetakArrayBuku(): Fungsi ini digunakan untuk mencetak semua elemen dalam stack, dimulai dari elemen teratas hingga elemen terbawah.
- Fungsi main(): Di dalam fungsi main(), dilakukan serangkaian operasi untuk menguji fungsi-fungsi yang telah didefinisikan sebelumnya. Elemen-elemen buku ditambahkan ke stack menggunakan pushArrayBuku(), kemudian beberapa operasi lainnya seperti mencetak, menghapus, dan mengubah elemen dilakukan untuk mengilustrasikan cara kerja dari masing-masing fungsi stack.

### 2. [Latihan Hash Table Menggunakan Node]

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ukuran tabel hash
const int TABLE_SIZE = 11;

string name; //deklarasi variabel string name
string phone_number; //deklarasi variabel string phone_number

// Struktur Data Untuk Setiap Node
class HashNode
{
//deklarasi variabel name dan phone_number
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};

// Class HashMap
class HashMap
{
private:
    vector<HashNode*> table[TABLE_SIZE];

public:
    // Fungsi Hash Sederhana
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    // Tambah data
    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    // Hapus data
    void remove(string name)
    {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    // Cari data berdasarkan nama
    string searchByName(string name)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }
        return "";
    }

    // Cetak data
    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
        }
    }
};

int main()
{
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;
    cout << "Hash Table : " << endl;
    employee_map.print();

    return 0;
}
```

Program yang diberikan adalah implementasi sederhana dari struktur data hash table dalam bahasa C++. Tujuannya adalah untuk mengorganisir dan menyimpan data pasangan nama dan nomor telepon. Struktur data utama yang digunakan adalah kelas HashMap, yang mengelola penyimpanan data dalam bentuk array vektor dari pointer ke HashNode. Setiap HashNode menyimpan informasi nama dan nomor telepon. Proses penambahan data dilakukan melalui metode insert, di mana nama dan nomor telepon baru dimasukkan ke dalam tabel hash. Jika entri dengan nama yang sama sudah ada, nomor teleponnya diperbarui. Fungsi remove digunakan untuk menghapus entri dari hash table berdasarkan nama yang diberikan. Untuk mencari nomor telepon berdasarkan nama, digunakan fungsi searchByName. Program mencetak hasil akhir dari hash table dengan metode print. Dalam fungsi main, beberapa entri ditambahkan ke hash table, lalu nomor telepon dicari dan salah satu entri dihapus. Hasil akhir dari hash table dicetak untuk dilihat. Ini adalah contoh sederhana penggunaan hash table untuk menyimpan dan mengakses data dengan efisien berdasarkan kunci unik. 

    
## Unguided 

### 1. [Hash Table]
Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
1. Setiap mahasiswa memiliki NIM dan nilai.
2. Program memiliki tampilan pilihan menu berisi poin C.
3. Implementasikan fungsi untuk menambahkan data baru, menghapus data,
mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai
(80 – 90).

```C++
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
                    hashTable.tambahData(nama_149, nim_149, nilai); //memanggil fungsi tambahData pada case 1
                }
                break;
            case 2:
                {
                    cout << "\n========== Hapus Data Mahasiswa ==========\n";
                    string nim_149;
                    cout << "Masukkan NIM data mahasiswa yang ingin dihapus: ";
                    cin >> nim_149;
                    hashTable.hapusData(nim_149); //memanggil fungsi hapusData pada case 2
                }
                break;
            case 3:
                {
                    cout << "\n========== Cari Data Mahasiswa berdasarkan NIM ==========\n";
                    string nim_149;
                    cout << "Masukkan NIM data mahasiswa yang ingin dicari: ";
                    cin >> nim_149;
                    {
                        Mahasiswa* mhs = hashTable.cariDataNIM(nim_149); //memanggil fungsi cariData pada case 3
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
                    hashTable.cariDataNilai(nilai_min, nilai_max); //memanggil fungsi cariDataNilai pada case 4
                }
                break;
            case 5:
                cout << "\n========== Tampilkan Semua Data Mahasiswa ==========\n";
                hashTable.tampilkanData(); //memanggil fungsi tampilkanData pada case 5
                break;
            case 6:
                cout << "Anda telah keluar dari program\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (choice != 6); //perulangan untuk mengulang menu jika choice bernilai tidak sama dengan 6

    return 0;
}

```
#### Output :
#### 1. Tampilan Menu
![m5 unguided-tampilan menu](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/b33b937a-42c9-44e6-8f22-3a19b6b52b61)<br/>

#### 2. Input Data
![m5 unguided-input data](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/300e4c62-fa06-4dc6-b3da-25658c392af8)<br/>

#### 3. Tampil Data
![m5 unguided tampil data 1](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/c9e350b7-57b3-4523-95ac-8a1ed5a38cd8) <br/>

#### 4. Cari Data Berdasarkan NIM
![m5 unguided-cari data dari nim](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/9fa4aa57-1a59-4128-bec1-df547a02db37)<br/>

#### 5. Cari Data Berdasarkan Rentang Nilai
![m5 unguided cari data rentang nilai](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/3fa6dcc9-d2c0-410c-bb6e-e4aa6d8e3f13)<br/>

#### 6. Hapus Data
![m5 unguided hapus data](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/445fa416-02d2-48af-9968-e838f768efff)<br/>

#### 7. Keluar
![m5 unguided keluar](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/4e70184c-4fb8-4562-a83f-a4a9801c7f22)


Program di atas adalah sebuah sistem manajemen data mahasiswa yang menggunakan struktur data Hash Table untuk penyimpanan data. Program ini mengizinkan user untuk menambah, menghapus, mencari, serta menampilkan data mahasiswa.

Pada awalnya, program menyediakan sebuah struktur data Mahasiswa yang memiliki tiga atribut: nim_149 (NIM mahasiswa), nama_149 (nama mahasiswa), dan nilai (nilai mahasiswa). Selanjutnya, program menggunakan class HashTable untuk mengimplementasikan tabel hash dengan ukuran hash_size yang telah ditentukan sebelumnya.

Kelas HashTable memiliki beberapa fungsi, antara lain:

tambahData: Menambahkan data mahasiswa ke dalam tabel hash dengan menggunakan fungsi hash untuk menentukan indeks penyimpanan. <br/>
hapusData: Menghapus data mahasiswa berdasarkan NIM dari tabel hash. <br/>
cariDataNIM: Mencari data mahasiswa berdasarkan NIM yang diberikan. <br/>
cariDataNilai: Mencari data mahasiswa berdasarkan rentang nilai yang diberikan. <br/>
tampilkanData: Menampilkan semua data mahasiswa yang tersimpan dalam tabel hash. <br/>

Kemudian, di dalam fungsi main, program menampilkan menu yang memungkinkan user untuk memilih operasi yang ingin dilakukan terhadap data mahasiswa, seperti menambah, menghapus, mencari, atau menampilkan data. User dapat memasukkan pilihan menu dan program akan menjalankan fungsi yang sesuai sesuai dengan pilihan yang dibuat. Perulangan akan terus berlangsung hingga User memilih untuk keluar dari program.

Melalui program ini, pengguna dapat dengan mudah mengelola data mahasiswa dan melakukan operasi-operasi dasar seperti penambahan, penghapusan, pencarian berdasarkan NIM atau rentang nilai, serta penampilan keseluruhan data.

## Kesimpulan
Hash Table merupakan struktur data yang efisien untuk menyimpan dan mengakses data dengan cepat menggunakan teknik hashing. Ini memungkinkan akses data dalam waktu yang hampir konstan dengan menggunakan kunci sebagai referensi untuk mengindeks nilai dalam struktur data.

Keuntungan Hash Table meliputi kemampuannya untuk memberikan waktu akses yang cepat, terutama saat jumlah data besar, karena waktu aksesnya hampir konstan. Selain itu, Hash Table dapat digunakan dalam berbagai aplikasi seperti basis data, kamus, cache, dan pengindeksan karena kemampuannya untuk menyimpan dan mencari data dengan efisien. Namun, untuk mencapai efisiensi yang optimal, penting untuk memilih fungsi hash yang baik dan memiliki strategi penanganan konflik yang tepat. Konflik hash terjadi ketika dua kunci menghasilkan nilai hash yang sama, dan strategi seperti chaining atau probing digunakan untuk mengatasi situasi ini.

Secara keseluruhan, Hash Table adalah alat yang sangat berguna dalam pengelolaan data yang memungkinkan akses data cepat dan efisien berdasarkan kunci unik.



## Referensi
[1] Santiago Tapia-Fernández, Daniel García-García, dan Pablo García-Hernandez. Key Concepts, Weakness and Benchmark on Hash Table Data Structures. 15(3). 100. Maret 2022. <br/>
[2] Asisten Praktikum. Modul 6 Stack. Purwokerto: Institut Teknologi Purwokerto. 2024. <br/>
[3] Rahardja, U., Hidayanto, A. N., Lutfiani, N., Febiani, D. A., dan Aini, Q. Immutability of Distributed Hash Model on Blockchain Node Storage. Sci. J. Informatics, 8(1), 137-143. 2021.<br/>




