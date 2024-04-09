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



    
## Unguided 

### 1. [Hash Table]
Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
1. Setiap mahasiswa memiliki NIM dan nilai.
2. Program memiliki tampilan pilihan menu berisi poin C.
3. Implementasikan fungsi untuk menambahkan data baru, menghapus data,
mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai
(80 – 90).

```C++


  
   
   
    
  

    
 
       
               


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




