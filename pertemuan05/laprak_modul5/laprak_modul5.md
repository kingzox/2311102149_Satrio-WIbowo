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
Program di atas merupakan sebuah program yang menggunakan single linked list circular untuk menyimpan data. Dalam program ini, digunakan struktur Node yang memiliki data bertipe string dan pointer next. Variabel head, tail, baru, bantu, dan hapus dideklarasikan sebagai pointer yang menunjuk ke Node. Fungsi-fungsi dibuat untuk menambahkan data ke depan, belakang, dan tengah; menghapus data dari depan, belakang, dan tengah; menghitung jumlah data; menampilkan data; serta menghapus semua data. Semua fungsi ini kemudian dipanggil dari dalam main function. Berikut untuk output dari program di atas:
Ayam <br/>
Bebek Ayam <br/>
Bebek Ayam Cicak <br/>
Bebek Ayam Cicak Domba <br/>
Bebek Ayam Cicak <br/>
Ayam Cicak <br/>
Ayam Sapi Cicak <br/>
Ayam Cicak <br/>


    
## Unguided 

### 1. [ Soal mengenai Single Linked List non Citcular]
Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. <br/>

1. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data kedua yang dimasukkan adalah nama dan NIM anda.<br/>
![unguided1 modul 4_soal](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/b95ab9c7-e3ee-4cf0-b145-a39c1fab033a)
2. Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004 <br/>
3. Hapus data Denis <br/>
4. Tambahkan data berikut di awal: Owi 2330000<br/>
5. Tambahkan data berikut di akhir: David 23300100<br/>
6. Ubah data Udin menjadi data berikut: Idin 23300045<br/>
7. Ubah data terkahir menjadi berikut: Lucy 23300101<br/>
8. Hapus data awal<br/>
9. Ubah data awal menjadi berikut: Bagas 2330002<br/>
10. Hapus data akhir <br/>
11. Tampilkan seluruh data <br/>


```C++
#include <iostream>
#include <iomanip> //Impor library  iomanip untuk mengatur format
#include <string> //Import library string untuk penggunaan tipe data string
using namespace std;

//Deklarasi class Node untuk mepresentasikan  node dari linked list
class Node {
public:
    string nama_149; //variabel untuk menyimpan data nama dengan tipe data string
    string nim_149; //variabel untuk menyimpan data nim mhs dengan tipe data string
    Node* next;

    Node(string nama_149, string nim_149) {
        this->nama_149 = nama_149;
        this->nim_149 = nim_149;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    //Konstruktor class linked list untuk inisialisasi head  menjadi NULL
    LinkedList() {
        head = nullptr;
    }

    //Fungsi untuk tambah depan
    void tambahDepan(string nama_149, string nim_149) {
        Node* newNode = new Node(nama_149, nim_149);
        newNode->next = head;
        head = newNode;
    }

    //Fungsi untuk tambah belakang
    void tambahBelakang(string nama_149, string nim_149) {
        Node* newNode = new Node(nama_149, nim_149);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    //Fungsi untuk tambah tengah
    void tambahTengah(string nama_149, string nim_149, int posisi) {
        if (posisi < 1) {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        Node* newNode = new Node(nama_149, nim_149);
        if (posisi == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < posisi - 1; ++i) {
            if (temp == nullptr) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    //FUngsi untuk ubah depan
    void ubahDepan(string nama_149, string nim_149) {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }
        head->nama_149 = nama_149;
        head->nim_149 = nim_149;
    }

    //Fungsi untuk ubah belakang
    void ubahBelakang(string nama_149, string nim_149) {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->nama_149 = nama_149;
        temp->nim_149 = nim_149;
    }

    //Fungsi untuk ubah tengah
    void ubahTengah(string nama_149, string nim_149, int posisi) {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < posisi; ++i) {
            if (temp == nullptr) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        temp->nama_149 = nama_149;
        temp->nim_149 = nim_149;
    }

    //Fungsi untuk hapus depan
    void hapusDepan() {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    //Fungsi untuk hapus belakang
    void hapusBelakang() {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    //Fungsi untuk hapus tengah
    void hapusTengah(int posisi) {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }
        if (posisi < 1) {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        if (posisi == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        for (int i = 1; i < posisi && curr != nullptr; ++i) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        prev->next = curr->next;
        delete curr;
    }

    //Fungsi untuk hapus semua data
    void hapusList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    //Fungsi untuk menampilkan semua data
    void tampilkan() {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }
        cout << setw(10) << left << "Nama" << setw(10) << left << "NIM" << endl;
        Node* temp = head;
        while (temp != nullptr) {
            cout << setw(10) << left << temp->nama_149 << setw(10) << left << temp->nim_149 << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList linkedList;

    int pilihan_149, posisi; //variabel untuk menyimpan pilihan
    string nama_149, nim_149;

    while (true) {
        cout<<"-------------------------------------------"<<endl;
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout<<"-------------------------------------------"<<endl;
        cout<<endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. Tampilkan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Operasi: ";
        cin >> pilihan_149;

        switch (pilihan_149) {
            case 0:
                return 0;
            case 1:
                cout << "Masukkan Nama: ";
                cin >> nama_149;
                cout << "Masukkan NIM: ";
                cin >> nim_149;
                linkedList.tambahDepan(nama_149, nim_149); //Summon fungsi tambah depan
                cout<<"Data berhasil ditambahkan!"<<endl;
                break;
            case 2:
                cout << "Masukkan Nama: ";
                cin >> nama_149;
                cout << "Masukkan NIM: ";
                cin >> nim_149;
                linkedList.tambahBelakang(nama_149, nim_149); //summon fungsi tambah belakang
                cout<<"Data berhasil ditambahkan!"<<endl;
                break;
            case 3:
                cout << "Masukkan Nama: ";
                cin >> nama_149;
                cout << "Masukkan NIM: ";
                cin >> nim_149;
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                linkedList.tambahTengah(nama_149, nim_149, posisi); //summon fungsi tambah tengah
                cout<<"Data berhasil ditambahkan!"<<endl;
                break;
            case 4:
                cout << "Masukkan Nama : ";
                cin >> nama_149;
                cout << "Masukkan NIM : ";
                cin >> nim_149;
                linkedList.ubahDepan(nama_149, nim_149); //summon fungsi ubah depan
                cout<<"Data berhasil diperbarui!"<<endl;
                break;
            case 5:
                cout << "Masukkan Nama : ";
                cin >> nama_149;
                cout << "Masukkan NIM : ";
                cin >> nim_149;
                linkedList.ubahBelakang(nama_149, nim_149); //summon fungsi ubah belakang
                cout<<"Data berhasil diperbarui!"<<endl;
                break;
            case 6:
                cout << "Masukkan Nama : ";
                cin >> nama_149;
                cout << "Masukkan NIM : ";
                cin >> nim_149;
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                linkedList.ubahTengah(nama_149, nim_149, posisi); //summon fungsi ubah tengah
                cout<<"Data berhasil diperbarui!"<<endl;
                break;
            case 7:
                linkedList.hapusDepan(); //summon fungsi hapus depan
                cout<<"Data berhasil dihapus\n";
                break;
            case 8:
                linkedList.hapusBelakang(); //summon fungsi hapus belakang
                cout<<"Data berhasil dihapus\n";
                break;
            case 9:
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                linkedList.hapusTengah(posisi); //summon fungsi hapus tengah
                cout<<"Data berhasil dihapus\n";
                break;
            case 10:
                linkedList.hapusList(); //summon fungsi  hapus list
                cout<<"Semua data telah dihapus."<<endl;
                break;
            case 11:
                linkedList.tampilkan(); //summon fungsi tampil data
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }

    return 0;
}


```
#### Output :
### 1. Tampilan Menu Pilihan 

![unguided 1 1 modul 4 satrio wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/4dd272ef-6652-4d6a-a176-47990cf13319) <br/>

![unguided 1 ubah tengah](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/29c9aa5c-7644-4521-ab25-5ea525fe8d0f) <br/>
![unguided 1 ubah depan](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/b87cba4e-185b-4a7d-a398-2bbed13489dd) <br/>
![unguided 1 ubah belakang](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/8133eda8-2214-459c-9039-766ed15ef141)<br/>
![unguided 1 tambah tengah modul 4 satrio wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/cdcc1803-be18-4698-96c2-350626a174e7) <br/>
![unguided 1 tambah depan modul 4 satrio wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/2369a961-b023-4291-8545-e22ac24d1831) <br/>
![unguided 1 tambah belakang modul 4 satrio wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/c2ac812b-1762-4981-b90e-03aaecf75063) <br/>
![unguided 1 hapus tengah modul 4 satrio wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/d2b83407-882f-400d-b184-3fab4f1a6bf9) <br>
![unguided 1 hapus depan](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/69917e72-fdf6-459d-b2b2-fb2a5805855e) <br/>
![unguided 1 hapus belakang](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/7aa09278-57a9-4f39-a6e5-e85e5dc8ec17) <br/>

### 2. Inputan data
![unguided 2 modul 4 satrio wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/3bd33c60-7ec8-4d2d-a990-168e35499752)

### 3. Hasil akhir setelah data dioperasikan
![unguided 3 modul 4 satrio wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/9bd78a85-a072-41df-bbf7-41df1f473b61)

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




