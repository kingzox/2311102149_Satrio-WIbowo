  # <h1 align="center">Laporan Praktikum Modul 8 - ALGORITMA SEARCHING</h1>
<p align="center">Satrio Wibowo - 2311102149</p>


## Dasar Teori
Algoritma Searching (pencarian) adalah urutan langkah-langkah logis yang dirancang untuk menemukan data tertentu dalam kumpulan data. Kumpulan data ini bisa berupa apa saja, seperti daftar kata, array bilangan, atau database besar. Algoritma ini bekerja dengan cara membandingkan data yang dicari dengan elemen-elemen dalam kumpulan data, hingga data yang dicari ditemukan atau dipastikan tidak ada.

Algoritma pencarian memiliki berbagai macam jenis dan kegunaannya, masing-masing dengan kelebihan dan kekurangannya. Beberapa jenis algoritma pencarian yang umum digunakan adalah:
## 1. Sequential Search

![sequential searching - satrio wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/de7105a6-5881-485d-8b7b-45e77e4822bd) <br/>

Konsep Sequential Search, juga dikenal sebagai Linear Search, adalah salah satu metode pencarian sederhana yang digunakan untuk menemukan keberadaan suatu nilai tertentu dalam sebuah kumpulan data yang tidak terurut.Cara kerja pencarian sekuensial:

- Mulai dari elemen pertama dalam kumpulan data.
- Bandingkan elemen tersebut dengan data yang sedang dicari.
- Jika elemen tersebut cocok dengan data yang dicari, pencarian selesai dan elemen tersebut dikembalikan.
- Jika elemen tersebut tidak cocok, lanjutkan ke elemen berikutnya dalam kumpulan data.
- Ulangi langkah 2 dan 3 hingga seluruh elemen dalam kumpulan data telah diperiksa.
- Jika tidak ada elemen yang cocok ditemukan, pencarian dinyatakan gagal.

Kelebihan pencarian sekuensial:

- Sederhana dan mudah diimplementasikan.
- Tidak memerlukan data yang diurutkan sebelumnya.

Kekurangan pencarian sekuensial:

- Inefisien untuk kumpulan data yang besar.
- Semakin besar kumpulan data, semakin banyak perbandingan yang perlu dilakukan, sehingga waktu pencarian menjadi semakin lama.
- Tidak cocok untuk aplikasi real-time yang membutuhkan pencarian cepat.

Penggunaan pencarian sekuensial:

- Biasanya digunakan untuk kumpulan data yang kecil.
- Digunakan sebagai dasar untuk memahami algoritma pencarian yang lebih kompleks.

## 2.  Binary Search
![binary search - satrio wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/47f14912-cff9-4e2b-92c3-14cc66df9a0e) <br/>


Binary search adalah algoritma pencarian yang digunakan untuk menemukan lokasi (indeks) suatu elemen tertentu dalam kumpulan data yang telah diurutkan secara terurut. 
Cara kerja pencarian biner:

- Hitung indeks tengah dari kumpulan data.
- Bandingkan data yang dicari dengan elemen pada indeks tengah tersebut.
- Jika data yang dicari cocok dengan elemen pada indeks tengah, pencarian selesai dan elemen tersebut dikembalikan.
- Jika data yang dicari lebih kecil dari elemen pada indeks tengah, maka data yang dicari pasti berada di bagian kiri dari kumpulan data yang tersisa. Ulangi langkah 1-3 untuk bagian kiri tersebut.
- Jika data yang dicari lebih besar dari elemen pada indeks tengah, maka data yang dicari pasti berada di bagian kanan dari kumpulan data yang tersisa. Ulangi langkah 1-3 untuk bagian kanan tersebut

Kelebihan pencarian biner:

- Sangat efisien untuk kumpulan data yang besar.
- Waktu pencarian rata-rata berbanding lurus dengan logaritma dari ukuran kumpulan data (記号 (kì hào) bìng hào, notation). Dengan kata lain, waktu pencarian meningkat jauh lebih lambat dibandingkan pencarian sekuensial - seiring dengan bertambahnya ukuran data.

Kekurangan pencarian biner:

- Memerlukan data yang sudah diurutkan sebelumnya.
- Kurang efisien untuk kumpulan data yang kecil (karena proses pengulangan untuk mencari indeks tengah bisa jadi lebih memakan waktu dibandingkan pencarian sekuensial).

Penggunaan pencarian biner:

- Digunakan untuk mencari data dalam array atau daftar yang sudah diurutkan.
- Digunakan dalam berbagai aplikasi, seperti mesin pencari, sistem basis data, dan algoritma sorting lainnya.

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

### 1. [SEARCHING : Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!]


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


Kode di atas adalah program C++ yang mencari sebuah huruf dalam sebuah kalimat yang diinput oleh user menggunakan algoritma binary search setelah mengurutkan kalimat tersebut. Program ini dimulai dengan mendeklarasikan beberapa fungsi dan variabel yang diperlukan untuk pencarian.

Fungsi binarySearch_149 digunakan untuk mencari sebuah karakter dalam string yang sudah diurutkan. Fungsi ini melakukan pencarian biner dengan inisialisasi variabel left_149 dan right_149 untuk menentukan batas pencarian. Dalam loop while, posisi tengah (mid_149) dihitung dan dibandingkan dengan target. Jika karakter ditemukan, fungsi mengembalikan nilai true; jika tidak, batas pencarian diperbarui hingga karakter ditemukan atau batas habis.

Fungsi findIndices_149 mencari semua indeks dari karakter target dalam kalimat asli. Fungsi ini menggunakan loop for untuk memeriksa setiap karakter dalam string asli dan menyimpan indeks yang sesuai dalam vector indices_149.

Fungsi main mengelola interaksi dengan user dan menggabungkan kedua fungsi sebelumnya. Program dimulai dengan mencetak header dan kemudian meminta user untuk memasukkan sebuah kalimat dan karakter yang ingin dicari. Setelah itu, kalimat diurutkan menggunakan sort dari STL. Kalimat yang sudah diurutkan dicetak untuk verifikasi.

Selanjutnya, fungsi binarySearch_149 dipanggil untuk mencari karakter dalam kalimat yang sudah diurutkan. Jika karakter ditemukan, program mencetak pesan bahwa karakter tersebut ditemukan dan memanggil findIndices_149 untuk mendapatkan semua indeks dari karakter tersebut dalam kalimat asli. Indeks-indeks ini kemudian dicetak. Jika karakter tidak ditemukan, program mencetak pesan yang sesuai.

Terakhir, user ditanya apakah ingin mencoba kalimat lain. Jika user memilih 'y' atau 'Y', program akan mengulangi proses. Jika tidak, program akan berhenti. Program ini menggabungkan input/output user dengan algoritma sorting dan searching untuk menyediakan fungsionalitas pencarian karakter yang efisien dalam kalimat.


### 2. [SEARCHING : Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!]

```C++

 
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat
int hitungHurufVokal_149(const string& kalimat_149, string& hurufVokalDitemukan_149) {
    int jumlah_149 = 0;
    string vokal_149 = "aiueoAIUEO"; // Huruf vokal

    // Menggunakan fungsi count_if dari <algorithm> untuk menghitung jumlah huruf vokal dalam kalimat
    jumlah_149 = count_if(kalimat_149.begin(), kalimat_149.end(), [&](char c_149) {
        if (vokal_149.find(c_149) != string::npos) {
            if (!hurufVokalDitemukan_149.empty()) {
                hurufVokalDitemukan_149 += ", "; // Menambahkan tanda koma jika sudah ada huruf vokal sebelumnya
            }
            hurufVokalDitemukan_149 += c_149; // Menambahkan huruf vokal yang ditemukan ke dalam string hurufVokalDitemukan
            return true;
        }
        return false;
    });

    return jumlah_149;
}

int main() {
    string kalimat_149;
    string hurufVokalDitemukan_149;
    char lanjut_149;

    cout << "=========================================\n";
    cout << "  FIND THE VOCAL LETTERS IN A SENTENCE\n";
    cout << "=========================================\n";

    do {
        // Meminta user memasukkan kalimat
        cout << "Masukkan sebuah kalimat: ";
        getline(cin, kalimat_149);

        // Reset string hurufVokalDitemukan_149 sebelum menghitung huruf vokal baru
        hurufVokalDitemukan_149.clear();

        // Menghitung jumlah huruf vokal dalam kalimat dan menambahkan huruf vokal yang ditemukan ke dalam hurufVokalDitemukan
        int jumlahHurufVokal_149 = hitungHurufVokal_149(kalimat_149, hurufVokalDitemukan_149);

        // Menampilkan hasil
        cout << "Jumlah huruf vokal dalam kalimat adalah: " << jumlahHurufVokal_149 << endl;
        if (jumlahHurufVokal_149 > 0) {
            cout << "Huruf vokal yang ditemukan dalam kalimat: " << hurufVokalDitemukan_149 << endl;
        }

        // Meminta user apakah ingin melanjutkan atau tidak
        cout << "Apakah Anda ingin mencoba pada kalimat lainnya? (y/n): ";
        cin >> lanjut_149;
        cin.ignore(); // Mengabaikan newline character yang tersisa di input stream
    } while (lanjut_149 == 'y' || lanjut_149 == 'Y');

    return 0;
}


```

### Output
![output unguided2 modul 8 - satrio wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/6d61f3da-a67f-41eb-87e8-db4a9917100d) <br/>

Program di atas adalah implementasi dalam C++ untuk menghitung jumlah huruf vokal dalam sebuah kalimat yang diinput oleh user. Program ini dimulai dengan mendeklarasikan fungsi hitungHurufVokal_149, yang menghitung jumlah huruf vokal dalam kalimat dan menyimpan huruf-huruf vokal yang ditemukan dalam sebuah string. Fungsi ini menggunakan lambda function dalam count_if dari header <algorithm> untuk memeriksa setiap karakter dalam kalimat, memeriksa apakah karakter tersebut adalah huruf vokal (dari string "aiueoAIUEO"). Jika ditemukan, karakter tersebut ditambahkan ke string hurufVokalDitemukan_149, dan jumlah vokal dihitung.

Fungsi main mengelola interaksi dengan user. Program mencetak header dan meminta user untuk memasukkan sebuah kalimat. Setelah itu, program memanggil fungsi hitungHurufVokal_149 untuk menghitung jumlah huruf vokal dalam kalimat tersebut. Hasilnya kemudian ditampilkan, termasuk jumlah huruf vokal dan huruf-huruf vokal yang ditemukan. Setelah itu, user ditanya apakah ingin mencoba kalimat lain. Jika user memilih 'y' atau 'Y', proses akan diulangi. Jika tidak, program akan berhenti.

Secara keseluruhan, program ini menggabungkan input/output user dengan pemrosesan string menggunakan algoritma untuk menyediakan fungsionalitas menghitung dan menampilkan huruf vokal dalam kalimat secara efisien.

### 3. [SEARCHING : Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!]

```C++
#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk menghitung berapa banyak angka 4 dalam data menggunakan Sequential Search
int hitungAngkaEmpat_149(const vector<int>& data_149) {
    int count_149 = 0;
    int angka_149 = 4; // Angka yang ingin dicari

    for (int i_149 = 0; i_149 < data_149.size(); ++i_149) {
        if (data_149[i_149] == angka_149) {
            count_149++;
        }
    }

    return count_149;
}

int main() {
    // Data yang diberikan
    vector<int> data_149 = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};

    // Menghitung berapa banyak angka 4 dalam data menggunakan Sequential Search
    int jumlahAngkaEmpat_149 = hitungAngkaEmpat_149(data_149);

    // Menampilkan hasil
    cout << "Jumlah angka 4 dalam data adalah: " << jumlahAngkaEmpat_149 << endl;

    return 0;
}

```

### Output
![output unguided3 modul8 - satrio wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/f95ad5fc-5b14-4f10-9228-f8ad24662801) <br/>

Program di atas adalah implementasi dalam C++ untuk menghitung berapa kali angka 4 muncul dalam sebuah vector menggunakan metode Sequential Search. Program ini dimulai dengan mendeklarasikan fungsi hitungAngkaEmpat_149, yang menerima sebuah vector integer sebagai parameter. Fungsi ini menggunakan loop for untuk memeriksa setiap elemen dalam vector. Jika elemen tersebut sama dengan angka 4, maka sebuah variabel penghitung count_149 akan bertambah satu. Setelah loop selesai, fungsi mengembalikan nilai count_149, yang merupakan jumlah angka 4 dalam vector.

Fungsi main menginisialisasi sebuah vector data_149 dengan sepuluh elemen integer yang berisi beberapa angka 4. Selanjutnya, fungsi hitungAngkaEmpat_149 dipanggil dengan vector ini sebagai argumen, dan hasilnya disimpan dalam variabel jumlahAngkaEmpat_149. Program kemudian menampilkan hasil jumlah kemunculan angka 4 dalam vector tersebut ke layar dengan menggunakan cout.

Secara keseluruhan, program ini menggabungkan penggunaan vector dan loop untuk menyediakan fungsionalitas menghitung kemunculan angka tertentu dalam data dengan cara yang sederhana dan langsung.

   
## Kesimpulan

Dari praktikum yang telah dilakukan, dapat ditarik kesimpulan bahwa algoritma searching merupakan alat penting dalam ilmu komputer untuk menemukan data dalam kumpulan data. Sequential Search dan Binary Search adalah dua contoh populer dengan kelebihan dan kekurangannya masing-masing. Memahami karakteristik dan kegunaannya memungkinkan pengembang untuk memilih algoritma yang tepat untuk menyelesaikan masalah mereka secara efisien.

## Referensi
[1] Bart J. Van Zeghbroeck, et al., Josephson Sampler Response Using a Binary Search Algorithm, Colorado: IEEE, 2024. <br/>
[2] Asisten Praktikum. Modul 8 Algoritma Searching. Purwokerto: Institut Teknologi Purwokerto. 2024. <br/>
[3] Malik, D.S., C++ Programming. Boston: Course Technology, 2023.




