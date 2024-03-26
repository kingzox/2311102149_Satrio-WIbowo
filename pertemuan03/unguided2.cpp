#include <iostream>

using namespace std;

class node {
public:
    string produk_149;
    int harga_149;
    node* prev;
    node* next;
};

class doublelinkedlist {
public:
    node *head;
    node* tail;
    doublelinkedlist() {
        head = nullptr;
        tail = nullptr;
    }

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