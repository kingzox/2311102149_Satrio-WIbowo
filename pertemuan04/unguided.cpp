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
