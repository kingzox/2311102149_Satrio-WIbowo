  # <h1 align="center">Laporan Praktikum Modul 7 - QUEUE</h1>
<p align="center">Satrio Wibowo - 2311102149</p>


## Dasar Teori
Queue adalah struktur data yang mengatur elemen-elemen dalam urutan linier dan berfungsi berdasarkan prinsip "First In, First Out" (FIFO). Artinya, elemen yang pertama kali dimasukkan ke dalam antrian akan menjadi yang pertama dikeluarkan. Prinsip ini mirip dengan konsep antrean dalam kehidupan sehari-hari, di mana orang yang datang lebih dulu akan dilayani lebih dulu. Dalam antrian, elemen yang berada di posisi pertama disebut Front atau Head, sedangkan elemen yang baru ditambahkan berada di posisi terakhir dan disebut Back, Rear, atau Tail.

Queue memiliki dua ujung utama:
- Front (Head): Ujung depan antrian, tempat elemen data dikeluarkan.
- Rear (Tail): Ujung belakang antrian, tempat elemen data dimasukkan.


Ada dua operasi utama pada queue:
- Enqueue: Operasi untuk menambahkan elemen data baru ke bagian belakang antrian (rear).
- Dequeue: Operasi untuk menghapus elemen data terdepan dari antrian (front).

Konsep penting lainnya:
- Kosong vs penuh: Queue dapat dalam keadaan kosong (tidak ada elemen) atau penuh (sudah mencapai kapasitas maksimum).
- FIFO (First In, First Out): Elemen yang pertama masuk antrian akan menjadi elemen pertama yang keluar.

Implementasi: </br>
Queue dapat diimplementasikan menggunakan berbagai struktur data seperti array atau linked list. Pemilihan implementasi tergantung pada kebutuhan program dan performa yang diinginkan.</br>

![images](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/fccc4b98-a4a3-4bde-a290-f41679142d55) </br>

Operasi umum pada Queue
- Enqueue: Operasi ini menambahkan elemen baru ke akhir antrian selama antrian tidak penuh. Setiap kali elemen ditambahkan (enqueue), variabel atau penunjuk posisi belakang (rear) akan bertambah satu.

- Dequeue: Operasi ini menghapus elemen pertama dari antrian selama antrian tidak kosong. Jika antrian kosong, akan terjadi underflow. Karena penghapusan dilakukan pada elemen pertama, setelah penghapusan perlu dilakukan pergeseran elemen-elemen yang tersisa untuk menyesuaikan posisinya.

- Display atau View: Operasi ini menampilkan semua data yang ada dalam antrian.

- IsEmpty: Operasi ini memeriksa apakah antrian kosong atau tidak. Untuk mencegah underflow saat dequeue, perlu dipastikan antrian tidak kosong. Antrian dianggap kosong jika penunjuk posisi belakang bernilai 0. Operasi ini biasanya diimplementasikan sebagai fungsi yang mengembalikan nilai true jika antrian kosong, dan false jika tidak.

- IsFull: Operasi ini memeriksa apakah antrian sudah penuh atau belum. Saat melakukan enqueue, penting untuk memastikan antrian tidak penuh untuk menghindari overflow. Antrian dianggap penuh jika penunjuk posisi belakang sama dengan nilai maksimal antrian. Operasi ini juga biasanya diimplementasikan sebagai fungsi yang mengembalikan nilai true jika antrian penuh, dan false jika tidak.

- Destroy atau Clear: Operasi ini menghapus semua data dalam antrian. Biasanya, fungsi IsEmpty dipanggil terlebih dahulu untuk memastikan antrian tidak kosong sebelum melakukan penghapusan. Jika antrian kosong, akan ditampilkan pesan bahwa antrian sudah kosong.

- Peek: Operasi ini mendapatkan nilai elemen pertama dalam antrian tanpa menghapusnya.




## Guided

### 1. [Latihan Stack]

```C++

//guided

#include <iostream>
using namespace std;

const int maksimalAntrian = 5;
int front = 0;
int back = 0;
string queueTeller[5];

//mengecek antrian apakah sudah penuh
bool isFull(){
    if(back == maksimalAntrian){
        return true;
    } else {
        return false;
    }
}

//mengecek antrian apakah masih kosong
bool isEmpty(){
    if (back == 0){
        return true;
    } else {
        return false;
    }
}

//menambah antrian
void tambahDAta(string nama){
    if (isFull()){
        cout<<"Antrian sudah penuh\n";
     } else {
        if (isEmpty()){
            queueTeller[0] = nama;
            front++;
            back++;
        } else {
            queueTeller[back] = nama;
            back++;
        }
     }
}

//mengurangi antrian
void kurangAntrian(){
    if (isEmpty()){
        cout<<"Antrian kosong\n";
    } else {
        for ( int i = 0; i < back; i++){
            queueTeller[i] = queueTeller[i+1];
        }
        back --;
    }
}

//memnghitung banyak data antrian
int count(){
    return back;
}

//menghapus seluruh antrian
void clearQueue(){
    if (isEmpty()){
        cout<<"Antrian kosong\n";
    } else {
        for (int i = 0; i < back; i++){
            queueTeller[i] = " ";
        }
        back = 0;
        front = 0;
    }
}

//melihat antrian
void viewQueue(){
    cout<<"Data antrian : \n";
    
    for (int i = 0; i < maksimalAntrian; i++){

        if (queueTeller[i]!= ""){
            cout << i+1 << ". "<<queueTeller[i]<<endl;
        } else {
            cout << i+1 <<". "<<"(kosong)"<<endl;
        }
        
    }
    }

    int main(){
        tambahDAta("Alya");
        tambahDAta("Kiki");
        tambahDAta("Artika");

        viewQueue();

        //memngurangi antrian
        kurangAntrian();
        viewQueue();

        //menghapus seluruh antrian
        clearQueue();
        viewQueue();

        return 0;
    }


```

Program tersebut adalah implementasi sederhana dari struktur data antrian (queue) menggunakan array dalam bahasa C++. Queue memiliki ukuran maksimum yang ditentukan oleh konstanta maksimalAntrian dengan nilai 5. Variabel front dan back digunakan untuk melacak posisi depan dan belakang antrian. Program ini memiliki beberapa fungsi untuk mengelola antrian, termasuk isFull() untuk memeriksa apakah antrian penuh, isEmpty() untuk memeriksa apakah antrian kosong, tambahDAta() untuk menambahkan elemen ke akhir antrian, kurangAntrian() untuk menghapus elemen dari depan antrian, count() untuk menghitung jumlah elemen dalam antrian, clearQueue() untuk menghapus semua elemen dalam antrian, dan viewQueue() untuk menampilkan semua elemen dalam antrian. Fungsi tambahDAta() menambahkan elemen baru ke antrian jika belum penuh, sedangkan kurangAntrian() menghapus elemen pertama dan menggeser elemen lainnya ke depan untuk menjaga urutan. Fungsi viewQueue() menampilkan semua elemen dalam antrian, menunjukkan posisi yang kosong jika tidak ada elemen di posisi tersebut. Program ini kemudian mengilustrasikan penggunaan fungsi-fungsi ini dengan menambahkan, menghapus, dan menampilkan elemen-elemen antrian, serta menghapus semua elemen dari antrian.


    
## Unguided 

### 1. [QUEUE]
Ubahlah penerapan konsep queue pada bagian guided dari array menjadi
linked list!

```C++
#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node_149 {
    string data_149;
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

    // Add a new element to the queue
    void tambahData_149(string nama_149) {
        Node_149* newNode_149 = new Node_149();
        newNode_149->data_149 = nama_149;
        newNode_149->next_149 = nullptr;
        
        if (isEmpty_149()) {
            front_149 = back_149 = newNode_149;
        } else {
            back_149->next_149 = newNode_149;
            back_149 = newNode_149;
        }
    }

    // Remove an element from the queue
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

    // Count the number of elements in the queue
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

    // View the elements in the queue
    void viewQueue_149() {
        cout << "Data antrian: \n";
        Node_149* temp_149 = front_149;
        int index_149 = 1;
        while (temp_149 != nullptr) {
            cout << index_149 << ". " << temp_149->data_149 << endl;
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

    queue_149.tambahData_149("Alya");
    queue_149.tambahData_149("Kiki");
    queue_149.tambahData_149("Artika");

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
#### Output :
![output modul 7  unguided 1 -satrio](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/1f0b91a6-f4df-48ae-a636-3cd0f904ba71) </br>


Kode di atas adalah implementasi antrian berbasis linked list dalam bahasa C++. Antrian ini menggunakan struktur Node_149 untuk merepresentasikan setiap elemen dalam antrian dan kelas Queue_149 untuk mengelola operasi antrian. Berikut adalah penjelasan setiap bagian dari kode:

- Struktur Node_149:
Struktur Node_149 mendefinisikan elemen dalam antrian. Setiap Node_149 memiliki dua atribut: data_149 yang merupakan data yang disimpan (dalam bentuk string) dan next_149 yang merupakan pointer ke node berikutnya dalam antrian.

- Kelas Queue_149:
Kelas Queue_149 mengelola antrian menggunakan dua pointer, front_149 dan back_149, yang mengarah ke elemen pertama dan terakhir dalam antrian, masing-masing. Kelas ini menyediakan berbagai metode untuk operasi antrian:

- isEmpty_149: Memeriksa apakah antrian kosong dengan memeriksa apakah front_149 adalah nullptr.
- tambahData_149: Menambahkan elemen baru ke antrian. Metode ini membuat node baru dan menambahkannya ke belakang antrian. Jika antrian kosong, node baru tersebut menjadi node pertama (front) dan terakhir (back) dalam antrian.
- kurangAntrian_149: Menghapus elemen dari antrian (dari depan). Jika antrian kosong, metode ini mencetak pesan bahwa antrian kosong. Jika tidak, metode ini menghapus node depan dan memperbarui pointer front_149.
- count_149: Menghitung jumlah elemen dalam antrian dengan mengiterasi melalui semua node dari depan ke belakang.
- clearQueue_149: Menghapus seluruh elemen dalam antrian dengan memanggil metode kurangAntrian_149 berulang kali sampai antrian kosong.
- viewQueue_149: Menampilkan semua elemen dalam antrian. Metode ini mengiterasi melalui semua node dan mencetak data yang disimpan dalam setiap node.
- Destruktor Queue_149:
Destruktor untuk kelas Queue_149 memastikan bahwa semua memori yang dialokasikan untuk node dalam antrian dibebaskan ketika objek antrian dihancurkan.

- Main Function:
Main Function mendemonstrasikan penggunaan kelas Queue_149. Ini dimulai dengan membuat objek Queue_149 bernama queue_149. Kemudian, tiga elemen ("Alya", "Kiki", "Artika") ditambahkan ke antrian menggunakan metode tambahData_149. Antrian kemudian ditampilkan dengan metode viewQueue_149. Satu elemen dihapus dari antrian menggunakan metode kurangAntrian_149 dan antrian ditampilkan kembali. Terakhir, seluruh elemen dalam antrian dihapus menggunakan metode clearQueue_149 dan antrian ditampilkan sekali lagi.

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




