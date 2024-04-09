# <h1 align="center">Laporan Praktikum Modul 5 - HASH TABLE</h1>
<p align="center">Satrio Wibowo - 2311102149</p>

tahap edit

## Dasar Teori



## Guided

### 1. [Latihan Hash Table]

```C++
#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

// Fungsi Hash Sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}

// Struktur Data Untuk Setiap Node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class Hash Table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << " : " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main()
{
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    // Deletion
    ht.remove(4);

    // Traversal
    ht.traverse();

    return 0;
}
```

Program di atas adalah implementasi sebuah hash table dalam bahasa C++. Pertama-tama, sebuah ukuran tabel hash ditentukan, yaitu 10. Kemudian, sebuah fungsi hash, hash_func, dibuat untuk menghasilkan nilai kunci modulo dengan ukuran maksimum tabel hash (MAX_SIZE). Fungsi hash_func bertujuan untuk menghitung indeks dari kunci yang akan dimasukkan.

Selanjutnya, sebuah struktur data Node didefinisikan, yang berisi kunci (key), nilai (value), dan pointer ke node berikutnya. Node ini berfungsi untuk menyimpan data yang akan dimasukkan ke dalam tabel hash.

Setelah itu, sebuah kelas HashTable dibuat yang berisi fungsi-fungsi untuk mengelola tabel hash, yaitu:

Fungsi insert untuk memasukkan data ke dalam tabel hash.
Fungsi get untuk mencari data berdasarkan kunci yang diinputkan.
Fungsi remove untuk menghapus data berdasarkan kunci yang diinputkan.
Output dari program tersebut adalah sebagai berikut:

Get key 1: 10 <br/>
Get key 4: -1 <br/>
3 : 30 <br/>
2 : 20 <br/>
1 : 10 <br/>

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







Program di atas adalah implementasi dari struktur data linked list non circular dalam bahasa C++. Program ini menggunakan dua kelas utama, yaitu Node dan LinkedList. Kelas Node merepresentasikan setiap simpul dalam linked list dengan dua atribut yaitu nama_149 dan nim_149 yang menyimpan nama dan NIM mahasiswa serta sebuah pointer next yang menunjukkan ke simpul selanjutnya dalam linked list. Konstruktor dari kelas Node digunakan untuk inisialisasi atribut-atribut tersebut.

Kelas LinkedList digunakan untuk mengatur linked list secara keseluruhan. Atribut head dari kelas LinkedList adalah pointer ke simpul pertama dalam linked list. Program ini menyediakan beberapa fungsi utama untuk mengelola linked list, antara lain:

tambahDepan: Menambahkan simpul baru di depan linked list. <br/>
tambahBelakang: Menambahkan simpul baru di belakang linked list. <br/>
tambahTengah: Menambahkan simpul baru di posisi tertentu dalam linked list. <br/>
ubahDepan, ubahBelakang, ubahTengah: Mengubah data pada simpul pertama, terakhir, atau di posisi tertentu dalam linked list. <br/>
hapusDepan, hapusBelakang, hapusTengah: Menghapus simpul pertama, terakhir, atau di posisi tertentu dalam linked list. <br/>
hapusList: Menghapus semua data dalam linked list. <br/>
tampilkan: Menampilkan semua data dalam linked list. <br/>

Fungsi-fungsi ini diimplementasikan dalam metode-metode kelas LinkedList sesuai dengan fungsionalitas yang disediakan. Selain itu, terdapat sebuah loop utama dalam fungsi main() yang memberikan menu kepada pengguna untuk memilih operasi yang ingin dilakukan terhadap linked list. Setiap operasi dipanggil dengan memanggil metode yang sesuai dari objek linkedList. Program akan terus berjalan hingga pengguna memilih untuk keluar (pilihan 0).


## Kesimpulan

Dari praktikum yang telah dilakukan dapat disimpulkan bahwa Linked list circular dan non-circular merupakan dua jenis struktur data yang digunakan untuk menyimpan dan mengatur elemen secara dinamis. Linked list non-circular memiliki node terakhir yang tidak terhubung kembali ke node pertama, sehingga tidak membentuk lingkaran. Di sisi lain, linked list circular memiliki node terakhir yang terhubung kembali ke node pertama, membentuk lingkaran tanpa titik akhir yang jelas. 

Keuntungan dari linked list circular adalah tidak perlu adanya pointer NULL karena node terakhir menunjuk kembali ke node pertama, sehingga operasi seperti buffering atau pengulangan data dapat dilakukan lebih efisien. Namun, penggunaan linked list circular memerlukan penanganan khusus untuk menghindari deadlock atau kesalahan pengaturan pointer. 

Sementara itu, linked list non-circular lebih sederhana dalam implementasinya dan lebih mudah dipahami, tetapi memiliki keterbatasan dalam beberapa aplikasi yang memerlukan struktur data berbentuk lingkaran. Dengan demikian, pemilihan jenis linked list yang tepat harus didasarkan pada kebutuhan spesifik dari suatu aplikasi atau masalah yang dihadapi.


## Referensi
[1] Abu Sara, M. R., Klaib, M. F. J., & Hasan, M. (2021). Hybrid Array List: An Efficient Dynamic Array with Linked List Structure. Indonesia Journal on Computing (Indo-JC), 5(3), 47-62. <br/>
[2] Asisten Praktikum. Modul 4 Linked Liar Circular dan Non Circular. 2024. <br/>
[3] GeeksforGeeks. 2023, November 14. Circular Linked List[online]. Available: https://www.geeksforgeeks.org/circular-linked-list/ <br/>




