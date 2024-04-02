# <h1 align="center">Laporan Praktikum Modul 4 - LINKED LIST CIRCULAR DAN NON CIRCULAR</h1>
<p align="center">Satrio Wibowo - 2311102149</p>

## Dasar Teori
1. Linked List Non Circular<br/>

Linked list non-circular adalah suatu struktur data yang terdiri dari simpul-simpul yang tidak saling terhubung antara simpul pertama (head) dan simpul terakhir (tail). Dalam linked list ini, pointer yang menunjuk ke simpul terakhir memiliki nilai 'NULL', yang menandakan akhir dari data dalam list tersebut. Ini berbeda dengan linked list circular di mana simpul terakhirnya mengarah kembali ke simpul pertama. Dalam penggunaannya, linked list non-circular memungkinkan penambahan dan penghapusan elemen dengan mengatur pointer secara tepat, sehingga menjaga konsistensi dan integritas data. Linked 
list non circular dapat digambarkan sebagai berikut:<br/>

![image](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/0fab43c2-3b95-44ae-ba7c-cb609b38cc1d)

2. Linked List Circular<br/>
Linked list circular adalah struktur data di mana simpul terakhir (tail) tidak memiliki nilai 'NULL' dan terhubung kembali dengan simpul pertama (head), menciptakan siklus tertutup dalam urutan simpulnya. Dalam penggunaannya, linked list circular membutuhkan node tambahan yang disebut node current untuk mengontrol iterasi data, memastikan program berhenti pada simpul awal setelah melakukan serangkaian operasi. Linked list circular berguna untuk menyimpan data yang perlu diakses secara berulang, seperti daftar putar lagu, antrian pesan, atau penggunaan memori berulang dalam aplikasi tertentu. Keberadaan siklus tertutup memungkinkan akses efisien ke data yang berulang tanpa memerlukan akhir yang jelas pada struktur data. Linked list circular dapat
digambarkan sebagai berikut: <br/>

![image](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/f37e2d82-9122-464e-9df2-00c068227cbb)





## Guided

### 1. [Linked list non circular]

```C++
#include <iostream>

using namespace std;

// PROGRAM SINGLE LINKED LIST NON-CIRCULAR

// Deklarasi struct node
struct Node
{
    int data;
    Node *next;
};

Node *head; // Deklarasi head
Node *tail; // Deklarasi tail

// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

// Pengecekkan apakah linked list kosong
bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
    // Tambah depan
    void insertDepan(int nilai)
    {

        // buat node baru
        Node *baru = new Node();
        baru->data = nilai;
        baru->next = NULL;
        if (isEmpty() == true)
        {
            head = tail = baru;
            head->next = NULL;
        }
        else
        {
            baru->next = head;
            head = baru;
        }
    }

    // Tambah belakang
    void insertBelakang(int nilai)
    {
        // buat node baru
        Node *baru = new Node();
        baru->data = nilai;
        baru->next = NULL;
        if (isEmpty() == true)
        {
            head = tail = baru;
            head->next = NULL;
        }
        else
        {
            tail->next = baru;
            tail = baru;
        }
    }

    // Hitung jumlah list
    int hitungList()
    {
        Node *hitung;
        hitung = head;
        int jumlah = 0;
        while (hitung != NULL)
        {
            jumlah++;
            hitung = hitung->next;
        }
        return jumlah;
    }

    // Tambah tengah
    void insertTengah(int data, int posisi)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            Node *baru, *bantu;
            baru = new Node();
            baru->data = data;

            // tranversing
            bantu = head;
            int nomor = 1;
            while (nomor < posisi - 1)
            {
                bantu = bantu->next;
                nomor++;
            }

            baru->next = bantu->next;
            bantu->next = baru;
        }
    }

    // Hapus depan
    void hapusDepan()
    {
        Node *hapus;
        if (isEmpty() == false)
        {
            if (head->next != NULL)
            {
                hapus = head;
                head = head->next;
                delete hapus;
            }
            else
            {
                head = tail = NULL;
            }
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }

    // Hapus belakang
    void hapusBelakang()
    {
        Node *hapus;
        Node *bantu;
        if (isEmpty() == false)
        {
            if (head != tail)
            {
                hapus = tail;
                bantu = head;
                while (bantu->next != tail)
                {
                    bantu = bantu->next;
                }
                tail = bantu;
                tail->next = NULL;
                delete hapus;
            }
            else
            {
                head = tail = NULL;
            }
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }
    // Hapus tengah
    void hapusTengah(int posisi)
    {
        Node *hapus, *bantu, *sebelum;
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            int nomor = 1;
            bantu = head;
            while (nomor <= posisi)
            {
                if (nomor == posisi - 1)
                {
                    sebelum = bantu;
                }
                if (nomor == posisi)
                {
                    hapus = bantu;
                }
                bantu = bantu->next;
                nomor++;
            }
            sebelum->next = bantu;
            delete hapus;
        }
    }

    // ubah depan
    void ubahDepan(int data)
    {
        if (isEmpty() == 0)
        {
            head->data = data;
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }

    // ubah tengah
    void ubahTengah(int data, int posisi)
    {
        Node *bantu;
        if (isEmpty() == 0)
        {
            if (posisi < 1 || posisi > hitungList())
            {
                cout << "Posisi di luar jangkauan" << endl;
            }
            else if (posisi == 1)
            {
                cout << "Posisi bukan posisi tengah" << endl;
            }
            else
            {
                int nomor = 1;
                bantu = head;
                while (nomor < posisi)
                {
                    bantu = bantu->next;
                    nomor++;
                }
                bantu->data = data;
            }
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }

    // ubah belakang
    void ubahBelakang(int data)
    {
        if (isEmpty() == 0)
        {
            tail->data = data;
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }

    // Hapus list
    void clearList()
    {
        Node *bantu, *hapus;
        bantu = head;
        while (bantu != NULL)
        {
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }
        head = tail = NULL;
        cout << "List berhasil terhapus!" << endl;
    }

    // Tampilkan list
    void tampilList()
    {
        Node *bantu;
        bantu = head;
        if (isEmpty() == false)
        {
            while (bantu != NULL)
            {
                cout << bantu->data << " ";
                bantu = bantu->next;
            }
            cout << endl;
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }

    int main()
    {
        init();
        insertDepan(3);
        tampilList();
        insertBelakang(5);
        tampilList();
        insertDepan(2);
        tampilList();
        insertDepan(1);
        tampilList();
        hapusDepan();
        tampilList();
        hapusBelakang();
        tampilList();
        insertTengah(7, 2);
        tampilList();
        hapusTengah(2);
        tampilList();
        ubahDepan(1);
        tampilList();
        ubahBelakang(8);
        tampilList();
        ubahTengah(11, 2);
        tampilList();

        return 0;
    }
```
Program di atas adalah sebuah implementasi dari single linked list non-circular menggunakan bahasa C++. Pertama, sebuah struktur Node dideklarasikan yang menyimpan data dan pointer ke node selanjutnya. Variabel head dan tail diinisialisasi dengan nilai NULL untuk menandakan list kosong. Selanjutnya, fungsi-fungsi dibuat untuk menambahkan data ke depan, belakang, dan tengah, serta untuk menghitung jumlah elemen, menghapus elemen di berbagai posisi, mengubah data, menghapus semua elemen, dan menampilkan isi list. Semua fungsi ini dipanggil dari dalam main function. Berikut output dari program di atas:
3 <br/>
3 5 <br/>
2 3 5 <br/>
1 2 3 5 <br/>
2 3 5 <br/>
2 3 <br/>
2 7 3 <br/>
2 3 <br/>
1 3 <br/>
1 8 <br/>
1 11 <br/>

### 2. [Latihan Double Linked List]

```C++
#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string data;
    Node* next;
};

Node* head, * tail, * baru, * bantu, * hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
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
[1]  Abu Sara, M. R., Klaib, M. F. J., & Hasan, M. (2021). Hybrid Array List: An Efficient Dynamic Array with Linked List Structure. Indonesia Journal on Computing (Indo-JC), 5(3), 47-62. <br/>
[2] Clinton L. Jeffery. Build Your Own Programming Language: A programmer's guide to designing compilers, interpreters, and DSLs for solving modern computing problems. United Kingdom: Packt Publishing Ltd. 2021.
