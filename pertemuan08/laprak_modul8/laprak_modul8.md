  # <h1 align="center">Laporan Praktikum Modul 8 - ALGORITMA SEARCHING</h1>
<p align="center">Satrio Wibowo - 2311102149</p>


## Dasar Teori



## Guided

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.

```C++
#include <iostream>

using namespace std;

int main() {
  int n = 10;
  int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
  int cari = 10;
  bool ketemu = false;
  int i;
  // Algoritma Sequential Search
  for (i = 0; i < n; i++) {
    if (data[i] == cari) {
      ketemu = true;
      break;
    }
  }
  cout << "\tProgram Sequential Search Sederhana\n" << endl;
  cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
  if (ketemu) {
    cout << "\nAngka " << cari << " ditemukan pada indeks ke-" << i << endl;
  } else {
    cout << cari << " tidak dapat ditemukan pada data." << endl;
  }
  return 0;
}

```

Program di atas adalah program pencarian data menggunakan metode Sequential Search. Program ini mencari data yang diminta dalam sebuah array. Jika data tersebut ditemukan, program akan menampilkan indeks dari data tersebut. Jika data tidak ditemukan, program akan memberikan pesan bahwa data tersebut tidak ditemukan. Dalam program ini, data yang dicari adalah angka 10. Sequential Search akan mencari angka 10 dalam array dengan menggunakan perulangan for. Setelah data ditemukan, program akan menampilkan pesan bahwa angka 10 ditemukan pada indeks ke-9. Kesimpulannya, program tersebut berhasil menemukan data yang dicari dalam array. 

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search.

```C++

#include <conio.h>
#include <iomanip>
#include <iostream>

using namespace std;

int dataArray[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;
void selection_sort() {
  int temp, min, i, j;
  for (i = 0; i < 7; i++) {
    min = i;
    for (j = i + 1; j < 7; j++) {
      if (dataArray[j] < dataArray[min]) {
        min = j;
      }
    }
    temp = dataArray[i];
    dataArray[i] = dataArray[min];
    dataArray[min] = temp;
  }
}

void binarysearch() {
  int awal, akhir, tengah;
  bool b_flag = false;
  awal = 0;
  akhir = 6;  // Corrected to 6 to match array bounds
  while (!b_flag && awal <= akhir) {
    tengah = (awal + akhir) / 2;
    if (dataArray[tengah] == cari) {
      b_flag = true;
    } else if (dataArray[tengah] < cari) {
      awal = tengah + 1;
    } else {
      akhir = tengah - 1;
    }
  }
  if (b_flag) {
    cout << "\nData ditemukan pada index ke- " << tengah << endl;
  } else {
    cout << "\nData tidak ditemukan\n";
  }
}

int main() {
  cout << "\tBINARY SEARCH" << endl;
  cout << "\nData: ";
  // Tampilkan data awal
  for (int x = 0; x < 7; x++) {
    cout << setw(3) << dataArray[x];
  }
  cout << endl;
  cout << "\nMasukkan data yang ingin Anda cari: ";
  cin >> cari;
  cout << "\nData diurutkan: ";
  // Urutkan data dengan selection sort
  selection_sort();
  // Tampilkan data setelah diurutkan
  for (int x = 0; x < 7; x++) {
    cout << setw(3) << dataArray[x];
  }
  cout << endl;
  binarysearch();
  _getche();
  return 0;
}

```

Program ini mencari data dalam array menggunakan algoritma binary search setelah mengurutkan data dengan selection sort. Dimulai dengan array dataArray berisi tujuh elemen integer, program meminta pengguna memasukkan angka yang ingin dicari.

Fungsi selection_sort() mengurutkan array dengan menemukan elemen terkecil dalam bagian yang belum diurutkan dan menukarnya ke depan, diulang untuk setiap elemen sampai seluruh array terurut. Fungsi binarysearch() mencari data dalam array terurut dengan menentukan posisi tengah, membandingkannya dengan data yang dicari, dan mempersempit pencarian ke separuh array yang relevan, berulang hingga data ditemukan atau tidak.

Fungsi main() menampilkan data awal, meminta input pengguna, mengurutkan data, menampilkan data terurut, dan memanggil binarysearch() untuk mencari data. Hasil pencarian ditampilkan di layar, menunjukkan apakah data ditemukan beserta indeksnya jika ditemukan. Program menunggu input karakter sebelum keluar. Secara keseluruhan, program ini menggabungkan selection sort dan binary search untuk mencari data secara efisien dalam array.
    
## Unguided 

### 1. [SEARCHING]
Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi untuk melakukan binary search pada string yang sudah diurutkan
bool binarySearch_149(const string &sorted_str_149, char target_149) {
    int left_149 = 0;
    int right_149 = sorted_str_149.length() - 1;

    while (left_149 <= right_149) {
        int mid_149 = left_149 + (right_149 - left_149) / 2;

        if (sorted_str_149[mid_149] == target_149) {
            return true;  // Huruf ditemukan
        }
        if (sorted_str_149[mid_149] < target_149) {
            left_149 = mid_149 + 1;
        } else {
            right_149 = mid_149 - 1;
        }
    }

    return false;  // Huruf tidak ditemukan
}

// Fungsi untuk mencari semua indeks dari huruf yang ditemukan dalam kalimat asli
vector<int> findIndices_149(const string &original_str_149, char target_149) {
    vector<int> indices_149;
    for (size_t i = 0; i < original_str_149.length(); ++i) {
        if (original_str_149[i] == target_149) {
            indices_149.push_back(i);
        }
    }
    return indices_149;
}

int main() {
    string input_149;
    char target_149;
    char choice_149;

    cout << "======================================================\n";
    cout << "                     BINARY SEARCH                    \n";
    cout << "      Mencari Huruf dari Inputan Sebuah Kalimat       \n";
    cout << "======================================================\n";

    do {
        // Meminta pengguna memasukkan kalimat
        cout << "Masukkan sebuah kalimat: ";
        getline(cin, input_149);

        // Meminta pengguna memasukkan huruf yang ingin dicari
        cout << "Masukkan huruf yang ingin dicari: ";
        cin >> target_149;
        cin.ignore(); // Membersihkan buffer setelah input karakter

        // Membuat salinan kalimat asli untuk pencarian indeks
        string original_input_149 = input_149;

        // Mengurutkan string
        sort(input_149.begin(), input_149.end());

        // Mencetak kalimat yang sudah diurutkan (untuk tujuan debugging atau verifikasi)
        cout << "Kalimat yang sudah diurutkan: " << input_149 << endl;

        // Melakukan binary search
        bool found_149 = binarySearch_149(input_149, target_149);

        // Menampilkan hasil pencarian
        if (found_149) {
            cout << "Huruf '" << target_149 << "' ditemukan dalam kalimat." << endl;

            // Mencari dan menampilkan semua indeks dari huruf yang ditemukan
            vector<int> indices_149 = findIndices_149(original_input_149, target_149);
            cout << "Huruf '" << target_149 << "' terdapat pada index : ";
            for (size_t i = 0; i < indices_149.size(); ++i) {
                cout << indices_149[i];
                if (i < indices_149.size() - 1) {
                    cout << ", ";  // Menambahkan koma jika bukan indeks terakhir
                }
            }
            cout << endl;
        } else {
            cout << "Huruf '" << target_149 << "' tidak ditemukan dalam kalimat." << endl;
        }

        // Menanyakan pengguna apakah ingin mencoba kalimat lain
        cout << "Apakah Anda ingin mencoba kalimat lain? (y/n): ";
        cin >> choice_149;
        cin.ignore(); // Membersihkan buffer setelah input karakter

    } while (choice_149 == 'y' || choice_149 == 'Y');

    return 0;
}


```
#### Output :
![output unguided1 modul 8 - satrio wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/4caf8ba6-3866-4ff8-8d93-0a5c67274c50) <br/>





### 2. [QUEUE]
Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM
Mahasiswa

```C++
#include <iostream>
using namespace std;

// Structure to represent a student
struct Mahasiswa_149 {
    string nama_149;
    string NIM_149;
};

// Node structure for the linked list
struct Node_149 {
    Mahasiswa_149 data_149;
    Node_149* next_149;
};

// Class for the linked list-based queue
class Queue_149 {
private:
    Node_149* front_149;
    Node_149* back_149;

public:
    Queue_149() {
        front_149 = nullptr;
        back_149 = nullptr;
    }

    // Check if the queue is empty
    bool isEmpty_149() {
        return front_149 == nullptr;
    }

    // Add a new student to the queue
    void tambahData_149(string nama_149, string NIM_149) {
        Node_149* newNode_149 = new Node_149();
        newNode_149->data_149.nama_149 = nama_149;
        newNode_149->data_149.NIM_149 = NIM_149;
        newNode_149->next_149 = nullptr;
        
        if (isEmpty_149()) {
            front_149 = back_149 = newNode_149;
        } else {
            back_149->next_149 = newNode_149;
            back_149 = newNode_149;
        }
    }

    // Remove a student from the queue
    void kurangAntrian_149() {
        if (isEmpty_149()) {
            cout << "Antrian kosong\n";
        } else {
            Node_149* temp_149 = front_149;
            front_149 = front_149->next_149;
            delete temp_149;
            if (front_149 == nullptr) {
                back_149 = nullptr;
            }
        }
    }

    // Count the number of students in the queue
    int count_149() {
        int count_149 = 0;
        Node_149* temp_149 = front_149;
        while (temp_149 != nullptr) {
            count_149++;
            temp_149 = temp_149->next_149;
        }
        return count_149;
    }

    // Clear the entire queue
    void clearQueue_149() {
        while (!isEmpty_149()) {
            kurangAntrian_149();
        }
    }

    // View the students in the queue
    void viewQueue_149() {
        cout << "Data antrian: \n";
        Node_149* temp_149 = front_149;
        int index_149 = 1;
        while (temp_149 != nullptr) {
            cout << index_149 << ". Nama: " << temp_149->data_149.nama_149 << ", NIM: " << temp_149->data_149.NIM_149 << endl;
            temp_149 = temp_149->next_149;
            index_149++;
        }
        if (isEmpty_149()) {
            cout << "(kosong)\n";
        }
    }

    ~Queue_149() {
        clearQueue_149();
    }
};

int main() {
    Queue_149 queue_149;

    queue_149.tambahData_149("Alya", "123456789");
    queue_149.tambahData_149("Kiki", "987654321");
    queue_149.tambahData_149("Artika", "112233445");

    queue_149.viewQueue_149();

    // Mengurangi antrian
    queue_149.kurangAntrian_149();
    queue_149.viewQueue_149();

    // Menghapus seluruh antrian
    queue_149.clearQueue_149();
    queue_149.viewQueue_149();

    return 0;
}


```

### Output
![output unguided 2 modul 7 -Satrio](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/396291f1-e7f3-4a98-b064-b15dda47c25d)


Melanjutkan dari unguided 1, yaitu menambahkan elemen nama mahasiswa dan nimnya. Secara keseluruhan, program ini menunjukkan bagaimana mengelola antrian mahasiswa menggunakan linked list dan melakukan operasi dasar seperti menambah, menghapus, menghitung, mengosongkan, dan menampilkan elemen-elemen antrian. Setiap mahasiswa memiliki atribut nama dan NIM (Nomor Induk Mahasiswa). Berikut adalah penjelasan mendetail dari program tersebut:

-Struktur Mahasiswa_149:
Struktur Mahasiswa_149 mendefinisikan data mahasiswa dengan dua atribut: nama_149 untuk nama mahasiswa dan NIM_149 untuk Nomor Induk Mahasiswa.

- Struktur Node_149:
Struktur Node_149 mendefinisikan elemen dalam antrian. Setiap Node_149 berisi objek Mahasiswa_149 sebagai datanya dan pointer next_149 yang menunjuk ke node berikutnya dalam antrian.
Kelas Queue_149:

- Kelas Queue_149 mengelola antrian dengan menggunakan dua pointer, front_149 dan back_149, yang menunjuk ke elemen pertama dan terakhir dalam antrian.
Metode dan Fungsi dalam Queue_149:

- Konstruktor:
Menginisialisasi antrian kosong dengan mengatur front_149 dan back_149 ke nullptr.

- isEmpty_149:
Memeriksa apakah antrian kosong dengan mengecek apakah front_149 adalah nullptr.

- tambahData_149:
Menambahkan mahasiswa baru ke antrian. Metode ini membuat node baru, mengisi data mahasiswa ke node tersebut, dan menambahkannya ke belakang antrian. Jika antrian kosong, node baru tersebut menjadi node pertama (front) dan terakhir (back) dalam antrian.

- kurangAntrian_149:
Menghapus mahasiswa dari antrian (dari depan). Jika antrian kosong, metode ini mencetak pesan bahwa antrian kosong. Jika tidak, metode ini menghapus node depan dan memperbarui pointer front_149.

- count_149:
Menghitung jumlah mahasiswa dalam antrian dengan mengiterasi melalui semua node dari depan ke belakang.

- clearQueue_149:
Menghapus seluruh elemen dalam antrian dengan memanggil metode kurangAntrian_149 berulang kali sampai antrian kosong.

- viewQueue_149:
Menampilkan semua mahasiswa dalam antrian. Metode ini mengiterasi melalui semua node dan mencetak nama dan NIM dari setiap mahasiswa dalam antrian.

- Destruktor:
Destruktor untuk kelas Queue_149 memastikan bahwa semua memori yang dialokasikan untuk node dalam antrian dibebaskan ketika objek antrian dihancurkan.

- Fungsi Main:
Fungsi main mendemonstrasikan penggunaan kelas Queue_149 dengan melakukan operasi dasar antrian:
1. Membuat objek Queue_149 bernama queue_149.
2. Menambahkan tiga mahasiswa ke antrian menggunakan metode tambahData_149.
3. Menampilkan antrian dengan metode viewQueue_149.
4. Mengurangi satu elemen dari antrian dengan metode kurangAntrian_149 dan menampilkan antrian kembali.
5. Menghapus seluruh elemen dalam antrian dengan metode clearQueue_149 dan menampilkan antrian yang sekarang kosong.

   
## Kesimpulan

Queue merupakan struktur data penting dalam pemrograman komputer yang mengikuti aturan FIFO (First In First Out), yang berarti elemen yang pertama dimasukkan ke dalam queue akan menjadi yang pertama dikeluarkan. Konsepnya mirip dengan antrian di kehidupan sehari-hari, di mana orang yang datang pertama kali akan dilayani terlebih dahulu. Queue umumnya diimplementasikan dengan dua operasi dasar: enqueue untuk menambahkan elemen baru ke dalam queue, biasanya dilakukan di bagian belakang (rear), dan dequeue untuk menghapus elemen dari queue, yang dilakukan di bagian depan (front). Selain itu, terdapat juga operasi peek yang memungkinkan untuk melihat elemen yang berada di depan queue tanpa menghapusnya. Queue digunakan dalam berbagai aplikasi seperti sistem antrian, penjadwalan tugas dalam sistem operasi, dan pemrosesan data pada algoritma pencarian dan pemrosesan grafik. Dengan prinsip FIFO-nya, queue menjadi alat yang efektif dalam mengelola data secara terurut dan efisien.

## Referensi
[1] Anita Sindar RMS, ST., M.TI., STRUKTUR DATA DAN ALGORITMA DENGAN C++. Serang: CV. AA. RIZKY, 2020. <br/>
[2] Asisten Praktikum. Modul 7 Queue. Purwokerto: Institut Teknologi Purwokerto. 2024. <br/>
[3] Malik, D.S., C++ Programming. Boston: Course Technology, 2023.




