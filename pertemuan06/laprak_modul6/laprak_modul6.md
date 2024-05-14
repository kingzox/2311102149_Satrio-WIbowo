  # <h1 align="center">Laporan Praktikum Modul 6 - STACK</h1>
<p align="center">Satrio Wibowo - 2311102149</p>


## Dasar Teori
Stack adalah sebuah kumpulan data di mana data diletakkan di atas data lain. Oleh karena itu, stack menggunakan konsep LIFO (Last In First Out) sebagai struktur data, sehingga elemen terakhir yang disimpan dalam stack menjadi elemen pertama yang diambil. Dalam proses komputasi, operasi push digunakan untuk meletakkan elemen di bagian atas stack, dan operasi pop digunakan untuk memindahkan elemen dari tempat tersebut.  

![ilustrasi  stack](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/1d1d3c67-835a-4104-a459-f85a9fc81872) <br/>


Operasi stack melakukan banyak fungsi dasar yang dapat dilakukan pada struktur data ini. Berikut adalah beberapa operasi stack yang biasa dilakukan:

- Push (Masukkan): Menempatkan elemen ke dalam tumpukan pada posisi paling atas atau ujung. 
- Pop (Keluarkan): Menghapus elemen dari posisi paling atas atau ujung tumpukan.
- Top (Atas): Memperoleh nilai atau melihat elemen tertinggi dalam tumpukan tanpa menghapusnya.
- IsEmpty (Kosong) menunjukkan apakah tumpukan kosong atau tidak. 
- IsFull (Penuh) menunjukkan apakah tumpukan penuh, terutama ketika tumpukan memiliki kapasitas terbatas.
- Size—atau ukuran—adalah cara untuk menghitung jumlah elemen yang ada dalam tumpukan.
- Peek (Lihat): Melihat elemen atau nilai di tempat tertentu dalam tumpukan tanpa menghapusnya.
- Clear (Hapus Semua): Menghapus semua elemen yang ada dalam tumpukan.
- Cari (Cari): Menemukan keberadaan elemen tertentu dalam tumpukan.

Stack dapat diimplementasikan menggunakan array dan linked list. Implementasi menggunakan array adalah salah satu pendekatan yang sederhana dan memberikan akses acak kepada pengguna berdasarkan indeks. Kelebihan dari implementasi ini adalah kemudahannya dalam proses implementasi. Namun, array memiliki keterbatasan karena ukurannya tidak dapat diubah secara dinamis selama proses berlangsung.

Sementara itu, implementasi menggunakan linked list juga memungkinkan untuk digunakan dalam stack. Seperti implementasi menggunakan array, linked list juga dapat menggunakan operasi seperti addEnd Front untuk menggantikan operasi push dan fungsi untuk menghapus node depan dari linked list sebagai pengganti operasi pop. Kelebihan utama dari implementasi stack menggunakan linked list adalah kemampuannya untuk dinamis bertambah dan berkurang sesuai dengan kebutuhan saat runtime. Namun, kekurangan dari penggunaan linked list adalah bahwa prosesnya membutuhkan lebih banyak memori karena penggunaan pointer dalam linked list.

Agar dapat menghindari kesalahan saat menggunakan stack, penting untuk selalu memeriksa batasan stack, seperti kondisi stack penuh atau stack kosong, terutama dalam implementasi yang menggunakan array.



## Guided

### 1. [Latihan Stack]

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


    
## Unguided 

### 1. [STACK]
Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan
dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari
depan dan belakang sama. Jelaskan bagaimana cara kerja programnya!

```C++
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cstdlib> // Untuk menggunakan system("cls") dan system("pause")

using namespace std;

bool isPalindrome_149(const string& sentence) {
    stack<char> charStack;
    string processedSentence;

    // Menghapus spasi dan mengubah huruf menjadi lowercase
    for (char c_149 : sentence) {
        if (!isspace(c_149)) {
            charStack.push(tolower(c_149));
            processedSentence.push_back(tolower(c_149));
        }
    }

    string reversedSentence;
    while (!charStack.empty()) {
        reversedSentence.push_back(charStack.top());
        charStack.pop();
    }

    return processedSentence == reversedSentence;
}

int main() {
    char choice_149 = ' ';
    string kalimat_149;
    
    do {
        cout << "Masukkan kalimat: ";
        getline(cin, kalimat_149);

        if (isPalindrome_149(kalimat_149)) {
            cout << "Kalimat ini adalah palindrom." << endl;
        } else {
            cout << "Kalimat ini bukan palindrom." << endl;
        }

        cout << "\nTekan Enter untuk melanjutkan atau ketik 'n' untuk keluar...";
        choice_149 = cin.get();
        cin.ignore(); // Membersihkan buffer

        // Membersihkan layar dan mengulang program jika Enter ditekan
        system("cls");
    } while (choice_149 != 'n' && choice_149 != 'N');

    cout << "Terima kasih telah menggunakan program!" << endl;

    // Menunggu untuk menekan tombol sebelum menutup program
    system("pause");
    
    return 0;
}


```
#### Output :
![output unguided1 1 modul 6](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/2c66e190-90d5-4a84-9c65-f989332d0068) <br/>
![output unguided 1 2 modul 6](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/8ad03948-11ba-4256-afc0-3d08bdc2ae7f) <br/>

Program tersebut merupakan aplikasi C++ yang bertujuan untuk menentukan apakah suatu kalimat merupakan palindrom atau tidak. Sebuah palindrom adalah istilah untuk sesuatu yang dapat dibaca sama baik dari depan maupun dari belakang. Program ini menggunakan konsep struktur data stack untuk melakukan pengecekan palindrom dengan langkah-langkah berikut: menghapus spasi, mengubah semua huruf menjadi huruf kecil, dan membandingkan kalimat asli dengan kalimat yang sudah dibalik.

Adapun fungsi fungsi yang ada pada program, yaitu :

- Library yang Diimpor: Program mengimpor beberapa library C++ yang diperlukan, seperti <iostream> untuk input-output, <stack> untuk menggunakan struktur data stack, <string> untuk manipulasi string, <cctype> untuk operasi pada karakter, dan <cstdlib> untuk menghapus layar dan menghentikan program.
- Fungsi isPalindrome_149(const string& sentence): Fungsi ini menerima satu parameter, yaitu string sentence, dan mengembalikan nilai boolean yang menunjukkan apakah kalimat tersebut merupakan palindrom atau bukan. Di dalam fungsi ini, setiap karakter dari kalimat dimasukkan ke dalam stack setelah diubah menjadi huruf kecil dan setelah mengabaikan spasi. Kemudian, kalimat asli juga diolah untuk mendapatkan versi yang sudah dibalik. Setelah itu, dilakukan perbandingan antara kedua versi kalimat tersebut. Jika sama, maka kalimat tersebut adalah palindrom.
- Fungsi main(): Di dalam fungsi main(), program meminta pengguna untuk memasukkan kalimat. Kalimat tersebut kemudian diperiksa apakah merupakan palindrom atau bukan menggunakan fungsi isPalindrome_149(). Hasilnya kemudian ditampilkan kepada pengguna. Pengguna diminta untuk menekan tombol Enter untuk melanjutkan atau mengetik 'n' untuk keluar. Setelah itu, layar dibersihkan dan program mengulang proses ini sampai pengguna memilih untuk keluar.

### 2. [STACK]
Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan
stack dengan minimal 3 kata. Jelaskan output program dan source codenya
beserta operasi/fungsi yang dibuat!

```C++
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk membalikkan kalimat menggunakan stack
string reverseSentence_149(string sentence_149) {
    stack<char> charStack_149;
    string reversedSentence_149 = "";

    // Push setiap karakter ke dalam stack
    for (char c_149 : sentence_149) {
        if (c_149 != ' ') {
            charStack_149.push(c_149);
        } else {
            // Ketika menemukan spasi, pop karakter dari stack dan tambahkan ke kalimat terbalik
            while (!charStack_149.empty()) {
                reversedSentence_149 += charStack_149.top();
                charStack_149.pop();
            }
            // Tambahkan spasi
            reversedSentence_149 += ' ';
        }
    }

    // Push sisa karakter ke dalam stack (untuk kata terakhir)
    while (!charStack_149.empty()) {
        reversedSentence_149 += charStack_149.top();
        charStack_149.pop();
    }

    return reversedSentence_149;
}

int main() {
    string kalimat_149, hasil_149;

    do {
        cout << "Masukkan kalimat (minimal 3 kata): ";
        getline(cin, kalimat_149);

        // Periksa jika kalimat kurang dari 3 kata
        if (kalimat_149.find(' ') == string::npos || kalimat_149.find(' ') == kalimat_149.rfind(' ')) {
            cout << "Kalimat harus memiliki minimal 3 kata. Silakan coba lagi." << endl;
        }
    } while (kalimat_149.find(' ') == string::npos || kalimat_149.find(' ') == kalimat_149.rfind(' ')); // Ulangi input jika kalimat kurang dari 3 kata

    hasil_149 = reverseSentence_149(kalimat_149);

    cout << "Hasil pembalikan: " << hasil_149 << endl;

    return 0;
}

```

### Output
![output unguided 2 modul 6](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/9f89f534-eb27-4f1b-a2d6-7617eb233204)

Program di atas adalah sebuah program C++ yang bertujuan untuk membalikkan setiap kata dalam sebuah kalimat, tetapi mempertahankan urutan kata tersebut. Program ini menggunakan struktur data stack untuk melakukan pembalikan.

Adapun fungsi dan libraru pada program di atas, yaitu :

- Library yang Diimpor: Program mengimpor beberapa library C++, yaitu <iostream>, <stack>, dan <string>, yang diperlukan untuk operasi input-output, penggunaan struktur data stack, dan manipulasi string.
- Fungsi reverseSentence_149(string sentence_149): Fungsi ini menerima sebuah string sentence_149 (kalimat) dan mengembalikan string yang merupakan hasil pembalikan setiap kata dalam kalimat tersebut. Dalam fungsi ini, setiap karakter dari kalimat dimasukkan ke dalam stack hingga ditemukan spasi. Ketika spasi ditemukan, karakter-karakter dari stack dikeluarkan satu per satu sehingga kata tersebut dibalik. Proses ini diulangi untuk setiap kata dalam kalimat. Hasilnya adalah kalimat yang sudah dibalik namun urutan kata tetap sama.
- Fungsi main(): Di dalam fungsi main(), program meminta pengguna untuk memasukkan sebuah kalimat yang memiliki minimal tiga kata. Pengguna diminta untuk memasukkan kalimat tersebut hingga syarat minimal terpenuhi. Setelah itu, program memanggil fungsi reverseSentence_149() untuk membalikkan kalimat yang telah dimasukkan oleh pengguna. Hasil pembalikan kemudian ditampilkan kepada pengguna.

## Kesimpulan

Dalam konteks bahasa pemrograman C++, penggunaan struktur data stack merupakan pendekatan yang penting dan sering digunakan dalam pengembangan aplikasi. Stack menawarkan cara efisien untuk menyimpan dan mengelola data dengan prinsip Last In First Out (LIFO), di mana elemen terakhir yang dimasukkan akan menjadi yang pertama kali dikeluarkan. Implementasi stack dapat dilakukan menggunakan array atau linked list, masing-masing dengan kelebihan dan kekurangannya. 

Implementasi dengan array menawarkan kemudahan implementasi dan akses acak terhadap elemen, namun memiliki keterbatasan dalam ukuran yang tetap. Sementara itu, implementasi dengan linked list memberikan fleksibilitas dalam ukuran dan operasi dinamis, namun memerlukan lebih banyak memori karena penggunaan pointer. Kesimpulannya, pengembang harus memilih implementasi stack yang paling sesuai dengan kebutuhan spesifik aplikasi mereka, dengan mempertimbangkan faktor seperti kecepatan, efisiensi memori, dan fleksibilitas dalam pengelolaan data. 

Dengan pemahaman yang baik tentang karakteristik dan keunggulan kedua pendekatan ini, penggunaan stack dapat meningkatkan efisiensi dan efektivitas dalam pengembangan aplikasi C++.


## Referensi
[1] Muhammad Nugraha. Dasar Pemrograman Dengan C++, Materi Paling Dasar untuk Menjadi Programmer Berbagai Platform. Yogyakarta: Deepublish. 2021. <br/>
[2] Asisten Praktikum. Modul 6 Stack. Purwokerto: Institut Teknologi Purwokerto. 2024. <br/>




