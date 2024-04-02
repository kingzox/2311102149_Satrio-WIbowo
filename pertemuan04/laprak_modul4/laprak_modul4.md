# <h1 align="center">Laporan Praktikum Modul 2 - Array</h1>
<p align="center">Satrio Wibowo - 2311102149</p>

## Dasar Teori
1. Single Linked List/Singly Linked List<br/>
Single Linked List (SLL) adalah suatu struktur data yang terdiri dari node yang saling terhubung melalui pointer. Di SLL, setiap node hanya memiliki pointer ke node berikutnya, dan pointer terakhir node menunjuk ke NULL.

Single Linked List dapat dianalogikan sebagai berikut: <br/>
![image](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/77269721-11d0-405a-972c-45ea40749e0f)<br/>
Beberapa operasi umum yang dilakukan oleh SLL termasuk: Push: Operasi untuk menambahkan data ke dalam daftar yang terhubung. Data yang paling baru akan berada di depan atau di belakang data lainnya, tergantung pada operasi pushDepan atau pushBelakang yang digunakan.


Pop adalah operasi untuk menghapus data dari daftar yang terhubung. Data yang dihapus adalah data paling depan atau paling belakang 1. Referensi adalah operasi untuk menampilkan data yang ada dalam daftar yang terhubung.


2. Double Linked List/Doubly Linked List<br/>
Double Linked List/Doubly Linked List(DLL) adalah sekumpulan node data yang terurut linear atau sekuensial dengan dua pointer: prev dan next.
Doule Linked List dapat dianalogikan seperti berikut: <br/>
![image](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/79952450-4be7-4eb8-b2f8-b2fe955a0ad0) <br/>

- Keunggulan: Saat menyusuri list, Anda dapat mengaksesnya dari kiri ke kanan atau dari kanan ke kiri.
Sangat mudah untuk menghapus node dari daftar karena mereka dapat mengubah pointer sebelumnya dan berikutnya.
Bisa digunakan untuk mengurutkan data ke atas atau ke bawah.

- Kekurangan: Karena setiap node memiliki dua pointer, membutuhkan lebih banyak memori.=
Karena harus melakukan pengecekan pointer prev dan next, diperlukan lebih banyak operasi untuk mengakses data.












## Guided

### 1. [Latihan Single Linked List]

```C++
// Latihan Single Linked List

#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node {
    int data;
    Node* next;
};

Node* head;
Node* tail;

//Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty() {
    if (head == NULL)
        return true;
    else
        return false;
}

//Tambah Depan
void insertDepan(int nilai) {
    //Buat Node baru
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty() == true) {
        head = tail = baru;
        tail->next = NULL;
    }
    else {
        baru->next = head;
        head = baru;
    }
}

//Tambah Belakang
void insertBelakang(int nilai) {
    //Buat Node baru
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty() == true) {
        head = tail = baru;
        tail->next = NULL;
    }
    else {
        tail->next = baru;
        tail = baru;
    }
}

//Hitung Jumlah List
int hitungList() {
    Node* hitung;
    hitung = head;
    int jumlah = 0;

    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}

//Tambah Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else {
        Node* baru, * bantu;
        baru = new Node();
        baru->data = data;

        // tranversing
        bantu = head;
        int nomor = 1;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//Hapus Depan
void hapusDepan() {
    Node* hapus;

    if (isEmpty() == false) {
        if (head->next != NULL) {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else {
            head = tail = NULL;
        }
    }
    else {
        cout << "List kosong!" << endl;
    }
}

//Hapus Belakang
void hapusBelakang() {
    Node* hapus;
    Node* bantu;

    if (isEmpty() == false) {
        if (head != tail) {
            hapus = tail;
            bantu = head;

            while (bantu->next != tail) {
                bantu = bantu->next;
            }

            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else {
            head = tail = NULL;
        }
    }
    else {
        cout << "List kosong!" << endl;
    }
}

//Hapus Tengah
void hapusTengah(int posisi) {
    Node* hapus, * bantu, * bantu2;

    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else {
        int nomor = 1;
        bantu = head;

        while (nomor <= posisi) {
            if (nomor == posisi - 1) {
                bantu2 = bantu;
            }

            if (nomor == posisi) {
                hapus = bantu;
            }

            bantu = bantu->next;
            nomor++;
        }

        bantu2->next = bantu;
        delete hapus;
    }
}

//Ubah Depan
void ubahDepan(int data) {
    if (isEmpty() == false) {
        head->data = data;
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Tengah
void ubahTengah(int data, int posisi) {
    Node* bantu;

    if (isEmpty() == false) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else {
            bantu = head;
            int nomor = 1;

            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }

            bantu->data = data;
        }
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Belakang
void ubahBelakang(int data) {
    if (isEmpty() == false) {
        tail->data = data;
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus List
void clearList() {
    Node* bantu, * hapus;
    bantu = head;

    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

//Tampilkan List
void tampil() {
    Node* bantu;
    bantu = head;

    if (isEmpty() == false) {
        while (bantu != NULL) {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }

        cout << endl;
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();

    return 0;
}
```
Program single-linked list non-circular di atas dibuat menggunakan bahasa C++. Pertama, kita mendeklarasikan struct Node dengan data dan pointer next. Kemudian, kita membuat fungsi untuk menambahkan data di depan, belakang, dan tengah. Kemudian, kita membuat fungsi untuk menghitung jumlah list, menghapus data di depan, belakang, dan tengah, mengubah data di depan, belakang, dan tengah, menghapus semua data, dan menampilkan data. Kemudian, kita memasukkan fungsi-fungsi tersebut ke dalam fungsi Node. Hasilnya adalah 3 5 2 3 5 7 3 8 11.

### 2. [Latihan Double Linked List]

```C++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Program di atas merupakan sebuah implementasi dari program Guided1.cpp dengan menggunakan konsep class dan objek. Pertama-tama, kita mendefinisikan sebuah kelas Node yang menyimpan data, serta pointer ke node sebelumnya dan setelahnya. Selanjutnya, kita mendefinisikan sebuah kelas DoublyLinkedList yang memiliki pointer ke kepala dan ekor dari linked list. Konstruktor digunakan untuk menginisialisasi pointer kepala dan ekor menjadi NULL. Fungsi push digunakan untuk menambahkan data di depan linked list, fungsi pop untuk menghapus data di depan, fungsi update untuk mengubah data, fungsi deleteAll untuk menghapus semua data, dan fungsi display untuk menampilkan data. Selanjutnya, kita memanggil fungsi-fungsi ini di dalam fungsi main. Hasilnya adalah 3 5 2 3 5 7 3 8 11.


    
## Unguided 

### 1. [Soal mengenai Single Linked List]
Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan Usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:<br/>
ㅤ1. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.<br/>
<img width="136" alt="Soal_Unguided-01_Modul 3_Satrio Wibowo" src="https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/8393cc86-17f5-42be-8595-cede542b6bc7"><br/>
  2. Hapus data Akechi<br/>
ㅤ3. Tambahkan data berikut diantara John dan Jane: "Futaba 18"<br/>
ㅤ4. Tambahkan data berikut di awal: "Igor 20"<br/>
ㅤ5. Ubah data Michael menjadi: "Reyn 18"<br/>
ㅤ6. Tampilkan seluruh data<br/>

```C++
#include <iostream>
using namespace std;

// Node struct untuk merepresentasikan node dalam linked list
struct Node {
    string nama_149;
    int usia_149;
    Node* next;
};

// Kelas untuk mengelola linked list
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Destructor
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Fungsi untuk menambahkan node di depan
    void insertFront(string nama_149, int usia_149) {
        Node* newNode = new Node;
        newNode->nama_149 = nama_149;
        newNode->usia_149 = usia_149;
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menambahkan node di belakang
    void insertBack(string nama_149, int usia_149) {
        Node* newNode = new Node;
        newNode->nama_149 = nama_149;
        newNode->usia_149 = usia_149;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Fungsi untuk menambahkan node di tengah
    void insertMiddle(string nama_149, int usia_149, int posisi) {
        if (posisi <= 0) {
            cout << "Posisi harus lebih besar dari 0" << endl;
            return;
        }
        if (posisi == 1) {
            insertFront(nama_149, usia_149);
            return;
        }
        Node* newNode = new Node;
        newNode->nama_149 = nama_149;
        newNode->usia_149 = usia_149;
        Node* current = head;
        for (int i = 1; i < posisi - 1 && current != nullptr; ++i) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Posisi terlalu besar" << endl;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    // Fungsi untuk mencari node berdasarkan nama
    Node* search(string nama_149) {
        Node* current = head;
        while (current != nullptr) {
            if (current->nama_149 == nama_149) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Fungsi untuk menghapus node berdasarkan nama
    void remove(string nama_149) {
        if (head == nullptr) {
            return;
        }
        if (head->nama_149 == nama_149) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->nama_149 == nama_149) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    // Fungsi untuk menampilkan seluruh data
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->nama_149 << " " << current->usia_149 << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;

    // Input data pengguna
    string namaSaya;
    int usiaSaya;

    // Input data pengguna sendiri
    cout << "Masukkan nama Anda: ";
    getline(cin, namaSaya);
    cout << "Masukkan usia Anda: ";
    cin >> usiaSaya;
    cin.ignore(); // Membersihkan newline dari buffer stdin

    // Masukkan data pengguna ke dalam linked list
    list.insertFront(namaSaya, usiaSaya);

    // Input data nama dan usia mahasiswa lain dari pengguna
    int jumlahMahasiswa;
    cout << "Masukkan jumlah mahasiswa lain: ";
    cin >> jumlahMahasiswa;
    cin.ignore(); // Membersihkan newline dari buffer stdin

    for (int i = 0; i < jumlahMahasiswa; ++i) {
        string namaMahasiswa;
        int usiaMahasiswa;

        cout << "Masukkan nama mahasiswa ke-" << i+1 << ": ";
        getline(cin, namaMahasiswa);
        cout << "Masukkan usia mahasiswa ke-" << i+1 << ": ";
        cin >> usiaMahasiswa;
        cin.ignore(); // Membersihkan newline dari buffer stdin

        list.insertBack(namaMahasiswa, usiaMahasiswa);
    }

    // Tampilkan seluruh data
    cout << "Data mahasiswa:" << endl;
    list.display();
    cout << endl;

    // Menu operasi
    while(true){
    char opsi;
    cout << "Menu Operasi:" << endl;
    cout << "a. Hapus data mahasiswa" << endl;
    cout << "b. Tambahkan data mahasiswa di depan" << endl;
    cout << "c. Tambahkan data mahasiswa di tengah" << endl;
    cout << "d. Tambahkan data mahasiswa di belakang" << endl;
    cout << "e. Tampilkan data" << endl;
    cout << "f. Keluar" << endl;
    cout << "Pilih opsi (a/b/c/d/e): ";
    cin >> opsi;
    cin.ignore(); // Membersihkan newline dari buffer stdin

    // Proses operasi sesuai dengan opsi yang dipilih
    switch (opsi) {
        case 'a': {
            string namaHapus;
            cout << "Masukkan nama mahasiswa yang ingin dihapus: ";
            getline(cin, namaHapus);
            list.remove(namaHapus);
            break;
        }
        case 'b': {
            string namaTambahDepan;
            int usiaTambahDepan;
            cout << "Masukkan nama mahasiswa yang ingin ditambahkan di depan: ";
            getline(cin, namaTambahDepan);
            cout << "Masukkan usia mahasiswa yang ingin ditambahkan di depan: ";
            cin>> usiaTambahDepan;
            cin.ignore(); // Membersihkan newline dari buffer stdin
            list.insertFront(namaTambahDepan, usiaTambahDepan);
            break;
        }
        case 'c': {
            string namaTambahTengah;
            int usiaTambahTengah;
            int posisiTambahTengah;
            cout << "Masukkan nama mahasiswa yang ingin ditambahkan di tengah: ";
            getline(cin, namaTambahTengah);
            cout << "Masukkan usia mahasiswa yang ingin ditambahkan di tengah: ";
            cin >> usiaTambahTengah;
            cout << "Masukkan posisi untuk menambahkan mahasiswa di tengah: ";
            cin >> posisiTambahTengah;
            cin.ignore(); // Membersihkan newline dari buffer stdin
            list.insertMiddle(namaTambahTengah, usiaTambahTengah, posisiTambahTengah);
            break;
        }
        case 'd': {
            string namaTambahBelakang;
            int usiaTambahBelakang;
            cout << "Masukkan nama mahasiswa yang ingin ditambahkan di belakang: ";
            getline(cin, namaTambahBelakang);
            cout << "Masukkan usia mahasiswa yang ingin ditambahkan di belakang: ";
            cin >> usiaTambahBelakang;
            cin.ignore(); // Membersihkan newline dari buffer stdin
            list.insertBack(namaTambahBelakang, usiaTambahBelakang);
            break;
        }
        case 'e': {
            cout << "Data mahasiswa setelah operasi:" << endl;
            list.display();
            break;
        }
        case 'f' : {
            cout<<"Anda telah keluar dari menu!"<<endl;
            exit(0);
        }
        default:
            cout << "Opsi tidak valid" << endl;
    
    }
    }

    return 0;

}

```
#### Output:
![Output Unguided 1 1 Modul 3](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/028b6b0d-c50a-4ad0-8cc3-fe028e82eef1)<br/>
![Output Unguided 1 2 Modul 3](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/1d0985eb-ab5f-4de5-b172-735322a8ce4c)<br/>
![Output Unguided 1 3 Modul 3](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/6f2988bb-0534-4ab6-a008-f8e4a9761b05)<br/>

Program di atas menggunakan struct Node yang berisi string nama_149, int usia_149, dan Node *next. Program ini memiliki beberapa fungsi, antara lain:
- InsertFront digunakan untuk menambah node di depan
- InsertBack digunakan untuk menambah node di belakang
- InsertMiddle digunakan untuk menambah node di tengah
- search digunakan untuk mencari node berdasarkan nama
- remove digunakan untuk menghapus node berdasarkan nama
- display digunakan untuk menampilkan seluruh data(baik sebelum diubah/sesudah diubah)
 Lalu pada main function, semua fungsi terkait linked list dipanggil untuk menjalankan progra sehingga menghasilkan output seperti yang telah dijelaskan pada soal Unguided 1 di atas. 


### 2. [Soal mengenai Double Linked List]
Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama Produk dan Harga.<br/>
Case:<br/>
1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific
2. Hapus produk Wardah
3. Update produk Hanasui menjadi Cleora dengan harga 55000
4. Tampilkan menu, di mana tampilan akhirnya akan menjadi seperti dibawah ini:
![Soal_Unguided-02_Modul 3_Satrio Wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/fedecd77-5b3b-42ff-902e-b062d887e404)

```C++
#include <iostream>

using namespace std;

//Deklarasi class yang digunakan untuk elemen dalam linked list
class node {
public:
    string produk_149;
    int harga_149;
    node* prev;
    node* next;
};

//Deklaras class 'doublelinkedlist' yang akan mewakili double linked list
class doublelinkedlist {
public:
    node *head;
    node* tail;
    doublelinkedlist() {
        head = nullptr;
        tail = nullptr;
    }

//Fungsi untuk menambahkan node baru ke depan linked list
    void push(string produk_149, int harga_149) {
        node* newNode = new node;
        newNode->harga_149 = harga_149;
        newNode->produk_149 = produk_149;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }

//Fungsi untuk memnghapus node pertama dari linked list
    void pop() {
        if (head == nullptr) {
            return;
        }

        node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }

//Fungsi untuk memoerbarui harga dan nama produk dari suatu node dalam linked list
    bool update(int hargaBaru, string produkLama, string produkBaru) {
        node* current = head;
        while (current != nullptr) {
            if (current->produk_149 == produkLama) {
                current->produk_149 = produkBaru;
                current->harga_149 = hargaBaru;
                return true;
            }
            current = current->next;
        }
        return false;
    }

//Fungsi untuk menambahkan node baru pada posisi tertentu
    void tambahData(int posisi, int harga_149, string produk_149) {
        if (posisi < 1) {
            cout << "Posisi harus lebih dari 0" << endl;
            return;
        }

        if (head == nullptr || posisi == 1) {
            push(produk_149, harga_149);
            return;
        }

        node* current = head;
        for (int y = 1; y < posisi - 1 && current->next != nullptr; y++) {
            current = current->next;
        }

        node* newNode = new node;
        newNode->harga_149 = harga_149;
        newNode->produk_149 = produk_149;
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }

//Fungsi untuk menghapus node pada posisi tertentu
    void hapusData(int posisi) {
        if (posisi < 1) {
            cout << "Posisi harus lebih dari 0" << endl;
            return;
        }

        if (head == nullptr) {
            return;
        }

        if (posisi == 1) {
            node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete temp;
            return;
        }

        node* current = head;
        for (int i = 1; current != nullptr && i < posisi; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Posisi melebihi panjang list" << endl;
            return;
        }

        current->prev->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }
        delete current;
    }

//Fungsi untuk menghapus semua node 
    void deleteAll() {
        node* current = head;
        while (current != nullptr) {
            node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

//Fungsi untuk menampilkan isi linked list
    void display() {
        node* current = head;
        while (current != nullptr) {
            cout << current->produk_149 << " " << current->harga_149 << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    doublelinkedlist list;
    cout << "menu\n";
    list.push("Hanasui", 30000);
    list.push("Wardah", 50000);
    list.push("Skintific", 100000);
    list.push("Somethinc", 150000);
    list.push("Originote", 60000);
    list.display();
    int pilih_149;
    while (true) {
        cout<<"-----------------------------\n";
        cout << "TOKO SKINCARE PURWOKERTO\n";
        cout<<"-----------------------------\n";
        cout<<endl;
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Update Data\n";
        cout << "4. Tambah Data Urutan Tertentu\n";
        cout << "5. Hapus Data Urutan Tertentu\n";
        cout << "6. Hapus Seluruh Data\n";
        cout << "7. Tampilkan Data\n";
        cout << "8. Exit\n";
        cout<<endl;
        cout<<"Masukkan Pilihan Anda: "; cin >> pilih_149;
        switch (pilih_149) {
            case 1: {
                int harga_149;
                string produk_149;
                cout << "INPUT NAMA PRODUK : ";
                cin>>produk_149;
                cout << "INPUT HARGA : ";
                cin >> harga_149;
                list.push(produk_149, harga_149);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                string produkLama, produkBaru;
                int hargaBaru;
                cout << "MASUKKAN PRODUK LAMA : ";
                cin>>produkLama;
                cout << "MASUKKAN PRODUK BARU : ";
                cin>> produkBaru;
                cout << "MASUKKAN HARGA PRODUK : ";
                cin >> hargaBaru;
                list.update(hargaBaru, produkLama, produkBaru);
                break;
            }
            case 4: {
                int posisi;
                int harga_149;
                string produk_149;
                cout << "INPUT NAMA PRODUK : ";
                cin>>produk_149;
                cout << "INPUT HARGA : ";
                cin >> harga_149;
                cout << "INPUT POSISI : ";
                cin >> posisi;
                list.tambahData(posisi, harga_149, produk_149);
                cout << "DATA BARU DITAMBAHKAN PADA POSISI : " << posisi;
                break;
            }
            case 5: {
                int posisi;
                cout << "POSISI DATA YANG DIHAPUS : ";
                cin >> posisi;
                list.hapusData(posisi);
                cout << "DATA " << posisi << " DIHAPUS\n";
                break;
            }
            case 6: {
                list.deleteAll();
                break;
            }
            case 7: {
                list.display();
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                cout << "Input anda masukkan tidak sesuai\n";
                break;
            }
        }
    }
    return 0;
}

```
#### Output: 
![Output Unguided 2 1 Modul 3 Satrio](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/b143d396-a271-41ff-ba60-255bb1e3c51c) <br/>
![Output Unguided 2 2 Modul 3 Satrio](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/45881d6d-b9c6-4104-b04d-756c096c3e9e) <br/>
![Output Unguided 2 3 Modul 3 Satrio](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/29e9aa0a-4b17-4812-8619-9ab2d892ebba)<br/>






## Kesimpulan
Dari praktikum yang telah dilakukan dapat disimpulkan bahwa Single Linked List terhubung dan Double Linked List adalah struktur data yang digunakan untuk menyimpan dan mengelola data dalam urutan tertentu. SSL memiliki pointer ke node berikutnya dan menyimpan data, sedangkan DLL memungkinkan navigasi maju dan mundur. Linked list memiliki batas data yang dinamis tidak seperti array yang statis.

## Referensi
[1]  Abu Sara, M. R., Klaib, M. F. J., & Hasan, M. (2021). Hybrid Array List: An Efficient Dynamic Array with Linked List Structure. Indonesia Journal on Computing (Indo-JC), 5(3), 47-62. <br/>
[2] Clinton L. Jeffery. Build Your Own Programming Language: A programmer's guide to designing compilers, interpreters, and DSLs for solving modern computing problems. United Kingdom: Packt Publishing Ltd. 2021.
