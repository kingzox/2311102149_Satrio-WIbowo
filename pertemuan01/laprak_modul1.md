# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Satrio Wibowo - 2311102149</p>

## Dasar Teori

Tipe data merupakan sebuah jenis nilai atau berupa nilai yang membuat sebuah variabel memiliki nilai yang spesifik dan jelas ketika digunakan nantinya. Dalam C++ tipe data terbagi menjadi 3 yaitu:

- Tipe data primitif<br/>
  Tipe data primitif merupakan tipe data yang telah ditentukan oleh sistem, dan tersedia di berbagai bahasa pemrogramman. Contohnya seperti int, float, long, double, bool, dan string.

- Tipe data abstrak<br/>
  Tipe data abstrak, juga dikenal sebagai Abstract Data Type, dapat terdiri dari banyak tipe data, sehingga nilainya dapat beragam dan lebih dari satu.

- Tipe data Koleksi<br/>
  Tipe data koleksi digunakan untuk menyimpan kumpulan nilai atau objek. Dengan menggunakan tipe data koleksi ini, Anda dapat menyimpan, mengawasi, dan mengakses jumlah data yang sangat besar dengan cara yang terstruktur. Berikut tipe data koleksi yang umum digunakan dalam bahasa C++:
1. Array<br/>
  Array merupakan struktur data statis yang menyimpan elemen tipe data identik.
2. Vector<br/>
  vector mirip dengan array yang memiliki kemampuan untuk menyimpan data dalam bentuk elemen-elemen, dan alokasi memorinya dilakukan secara bersamaan dan 
  otomatis.
3. Map<br/>
  Map adalah kumpulan elemen yang dapat diakses melalui pasangan key dan value. Map mirip dengan array hanya saja pada map indexnya dapat berupa tipe data  
  selain integer.




### 1. [Tipe Data Primirif]

```C++
#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    char op;
    float num1, num2;

    //it allows user to enter operator i.e.+,-,*,/
    cout<<"enter operator (+,-,*,/): ";
    cin>> op;

    //it allows user to enter the operatpr
    cout<<"enter two operands: ";
    cin>>num1>>num2;

    //switch statenent begins
    switch(op){
        //if user enter +
        case '+' :
        cout<<"Result: "<<num1+num2;
        break;

        //if user enter -
        case '-': 
        cout<<"Result: "<<num1-num2;
        break;

        //if user enter *
        case '*':
        cout<<"Result: "<<num1*num2;
        break;

        //if user enter /
        case '/':
        if(num2 !=0){
            cout<<"Result: "<<fixed<<setprecision(2)<<num1/num2;
        } else{
            cout<<"error! division by zero isn't allowed.";
        }
        break;
        
        //if operator is other than + - * /,
        //error massage will display
        default:
        cout<<"error! operator isn't corrcet";
        

    } //switch statement ends

    return 0;

}
```
Kode di atas digunakan untuk memilih operasi penambahan (+), pengurangan (-), perkalian (*), dan pembagian (/). Keempat operasi ini akan berjalan ketika user telah menginputkan dua angka pada saat penginputan cin. Terdapat juga dua tipe data primitif pada program ini, yaitu char dan float. Tipe data char digunakan pada saat pemilihan switch case dan float digunakan sebagai tipe data 2 angka yang diinput user.

### 2. [Tipe Data Abstrak]

```C++
#include <stdio.h>
#include <string.h>

//struct
struct Mahasiswa
{
    char name[50];
    char address[100];
    int age;
};

int main(){
     //using struct
     struct Mahasiswa mhs1, mhs2;
     //mengisi nilai ke struct
     strcpy(mhs1.name, "Dian>");
     strcpy(mhs1.address, "Mataram");
     mhs1.age = 22;
     strcpy(mhs2.name, "Bambang");
     strcpy(mhs2.address, "Surabaya");
     mhs2.age = 23;

     //mencetak isi struct
     printf("## Mahasiswa 1 ##\n");
     printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf ("\n");
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
return 0;
}
```
Kode yang disebutkan di atas digunakan untuk mencetak isi struct. Salah satu contoh tipe data abstrak adalah struct. Struct mahasiswa ada dalam kode di atas. Struktur siswa ini memiliki tiga nilai: char nama berukuran 50, char address berukuran 50, dan int usia. Kemudian, nilai diisi pada int main, dan struktur siswa dideklarasikan dengan dua objek: mhs1 bernama Dian dan mhs2 bernama Bambang.

### 3. [Tipe Data Koleksi]

```C++
#include <iostream>
#include <array>

using namespace std;

int main() {
    // Deklarasi dan inisialisasi array

int nilai[5];
nilai[0] = 23;
nilai[1] = 50;
nilai[2] = 34;
nilai[3] = 78;
nilai[4] = 90;

    // Mencetak array dengan tab

cout << "Isi array pertama : " << nilai[0] << endl;
cout << "Isi array kedua : " << nilai[1] << endl;
cout << "Isi array ketiga : " << nilai[2] << endl;
cout << "Isi array keempat : " << nilai[3] << endl;
cout << "Isi array kelima : " << nilai[4] << endl;

return 0;
}
```
Dalam kode di atas adalah contoh program dengan array. Array adalah salah satu contoh tipe data koleksi, dan library array membantu proses pemrogramannya. Pada program di atas terdapat array yang dapat menyimpan 5 nilai, yaitu 23, 50, 34, 78, dan 90. Kemudian dideklarasikan di bawahnya.



    
## Unguided 

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!
]

```C++

//-- Satrio Wibowo --
//-- 2311102149 --

#include<iostream>
using namespace std;



int jari2_2149, alas_2149, tinggi_2149, sisi_2149; //Data primitf integer untuk mengisi jari-jari, alas, tinggi, dan sisi agar dapat menyimpan bilangan bulat
float phi=3.14;//Data primitif float yang sudah ditetapkan nilainya yaitu 3.14, digunakan untuk menyimpan nilai phi
char pilihan_2149; //Data primitif char untuk pilihan menu ke 4

void Luas_Lingkaran(){ //Fungsi luas lingkaran
    cout<<"Rumus Luas Lingkaran = phi*r*r\n";
    cout<<"Masukkan Jari-jari: "; cin>>jari2_2149;
    cout<<"Hasil Luas Lingkaran: "<<phi*jari2_2149*jari2_2149<<endl; //Rumus luas lingkaran
}

void Luas_Segitiga(){ //Fungsi luas segitiga
    cout<<"Rumus Luas Segitiga = 1/2*a*t\n";
    cout<<"Masukkan alas: "; cin>>alas_2149;
    cout<<"Masukkan tinggi: "; cin>>tinggi_2149;
    cout<<"Hasil Luas Segitiga: "<<0.5*alas_2149*tinggi_2149<<endl; //Rumus luas segitiga
}

void Luas_Persegi(){ //Fungsi luas persegi
    cout<<"Rumus Luas Persegi = s*s\n";
    cout<<"Masukkan Sisi: "; cin>>sisi_2149; 
    cout<<" Hasil Luas Persegi: "<<sisi_2149*sisi_2149<<endl; //Rumus luas persegi
}

int main(){

   
    int choice_2149;//Data primitif integer untuk memilih menu pilihan perhitungan luas bangun datar

    do{ //Looping untuk menjalankan menu pilih perhitungan luas bangun datar

    cout<<"--------------------------------\n";
    cout<<"PERHITUNGAN LUAS BANGUN DATAR\n";
    cout<<"--------------------------------\n";
    cout<<endl;
    cout<<"1. Luas Lingkaran\n";
    cout<<"2. Luas Segitiga\n";
    cout<<"3. Luas Persegi\n";
    cout<<"4. Exit\n";
    cout<<endl;
    cout<<"Silahkan masukkan pilihan anda: "; cin>>choice_2149;
    switch (choice_2149)
    { case 1:
        Luas_Lingkaran(); //Pemanggilan fungsi luas lingkaran jika user memilih 1
        cout<<endl;
      break;

      case 2:
        Luas_Segitiga(); //Pemanggilan fungsi luas segitiga jika user memilih 2
        cout<<endl;
      break;

      case 3:
        Luas_Persegi(); //Pemanggilan fungsi luas persegi jika user memilih 3
        cout<<endl;
      break;
      
      case 4:
        cout<<"Apakah anda yakin ingin keluar? [y/n]"; cin>>pilihan_2149;
        
        //If else condition pada menu pilihan 4, ketika user memilih y maka akan keluar, sebaliknya ketika memilih n maka akan kembali ke menu awal
        
        if(pilihan_2149 == 'y'){ 
          cout<<"Anda berhasil keluar\n";
      } else {
          cout<<"Anda memilih untuk tidak keluar\n";
      }
      break;

       default:
          cout<<"Anda salah memasukkan inputan, silahkan input kembali!\n"; //Jika user menginputkan angka selain 1-4 maka akan muncul "Anda salah memasukkan pilihan "
      break;
    }
    } while(pilihan_2149 != 'y'); //Looping akan berhenti ketika user memilih y pada pilihan no 4  
    return 0;
}
```
#### Output:
![Screenshot 2024-03-12 160253](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/28e831fa-3b01-45db-b380-c8a41d3b58c0)


Kode di atas merupakan program yang menggunakan fungsi. Terdapat 3 fungsi yaitu luas lingkaran, luas segitiga dan luas persegi, dimana masing masing fungsi memiliki tipe data primitif di dalamnya. Ada 3 tipe data int, 1 float yang sudah ditentukan value nya yaitu 3.14 sebagai phi, dan char. Pada int main disediakan 4 pilihan yang selanjutnya akan diproses pada switch condition. pada setiap masing masing case dipanggil dari 3 fungsi yang telah dituliskan. Jika user menginputkan pilihan yang diinginkannya maka akan ter-output case yang dipilihnya. Pada menu tersebut juga menggunakan looping dimana ketika user memilih 'y' pada pilihan ke 4 maka program akan berhenti, sebaliknya jika user memilih 'n' maka program akan ter-looping kembali.

Kesimpulan:<br/>
Dapat disimpulkan bahwa tipe data primitif merupakan tipe data yang telah ditentukan oleh sistem, dan banyak tersedia di bahasa pemrogramman. Tipe data primitif merupakan fundamental dari sekian banyak komponen untuk membuat sebuah program.


## Unguided 

### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!]

```C++

//-- Satrio Wibowo --
//-- 2311102149 --

//Contoh program menggunakan struct dan class

#include<iostream>
using namespace std;


//struct Data_Mhs_2149 berisi data yang tediri dari nama,umur menggunakan string dan kelas char
struct Data_Mhs_2149{
    string nama_2149;
    string nim_2149;
    char kelas_2149;

};

//class Nilai_2149 berisi data yang tediri dari kalulus, matdis,, alpro, dasar mm, rata-rata menggunakan int dan status string
class Nilai_2149{
public:
     int kalkulus_2149;
     int matdis_2149;
     int alpro_2149;
     int dasar_mm_2149;
     string status_2149;
     int rata2_2149;


};

int main(){
    cout<<"---------------------------\n";
    cout<<"    DATA NILAI MAHASISWA   \n";
    cout<<"---------------------------\n";
    cout<<endl;
    
    //Deklarasi dari struct Data_Mhs_2149
    Data_Mhs_2149 data{"Satrio WIbowo", "2311102149", 'D'};
    cout<<"Nama: "<<data.nama_2149<<endl;
    cout<<"Umur: "<<data.nim_2149<<endl;
    cout<<"Kelas: "<<data.kelas_2149<<endl;

    cout<<endl;

    //Deklarasi dari class Nilai_2149
    Nilai_2149 nilai;
    nilai.kalkulus_2149 = 83;
    nilai.matdis_2149 = 85;
    nilai.alpro_2149 = 82;
    nilai.dasar_mm_2149 = 90;
    nilai.rata2_2149 = (nilai.kalkulus_2149+nilai.alpro_2149+nilai.dasar_mm_2149+nilai.matdis_2149)/4;
    nilai.status_2149 = "TUNTAS";

    cout<<"------------------------\n";
    cout<<endl;

    cout<<"Nilai Kalkulus: "<<nilai.kalkulus_2149<<endl;
    cout<<"Nilai Matdis: "<<nilai.matdis_2149<<endl;
    cout<<"Nilai Alpro: "<<nilai.alpro_2149<<endl;
    cout<<"Nilai Dasar Multimedia: "<<nilai.dasar_mm_2149<<endl;
    
    cout<<endl;
    cout<<"------------------------\n";
   
    cout<<"Rata-rata nilai: "<<nilai.rata2_2149<<endl;
    cout<<"Status: "<<nilai.status_2149<<endl;

    
    return 0;
    
}
```
#### Output: 
![Screenshot 2024-03-12 160402](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/ca991e6e-3585-4c64-8a29-df05ffdf2c1d)



Kode di atas merupakan kode yang digunakan untuk mencetakn/menampilkan sebuah struct dan class. Pada kode di atas terdapat struct Data_Mhs_2149 yang menampung nilai string nama_2149, string nim_2149, dan char kelas_2149. Lalu ada class Nilai_2149 yang menampung nilai int kalkulus_2149, int dasar_mm_2149, int matdis_2149, int alrpo_2149, string status_2149, dan int rata2_2149 dengan akses publik.n Pada struct Data_Mhs_2149 diisi dengan nama Satrio Wibowo, nim 2311102149, dan kelas D. Untuk class Nilai_2149 diisin dengan nilai kalkulus 83, nilai matdis 85, nilai alpro 82, dan nilai dasar mm 90, lalu memasukkan rumus rata-rata dengan rumus (nilai kalkulus+nilai matdis+nilai alpro+nilai dasar mm)/4, dan terakhir status dengan nilai TUNTAS. Kemudian untuk menampilkan/menjalankan struct dan kelas ini dideklarasikan sesuai dengan syntax yang telah ditentukan.

A. Fungsi dari struct<br/>
  Dalam pemrograman C++, fungsi struct adalah konstruksi yang mendefinisikan struktur data yang terdiri dari koleksi variabel yang dinyatakan dengan nama, yang masing-masing memiliki tipe data yang berbeda.

B. Fungsi dari class<br/>
  Dalam pemrograman berorientasi objek (OOP), class adalah struktur utama. Class dapat membuat objek yang sama atau berbeda tetapi memiliki atribut yang sama. Setiap objek yang dibuat dari class tersebut akan memiliki 
  atribut yang sama, tetapi nilainya dapat berbeda.

  ### 3. [Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!]

```C++

//-- Satrio Wibowo--
//-- 2311102149

//Contoh program menggunakan map

#include<iostream>
#include<map> //std library yang digunakan agar bisa menggunakan fungsi map
using namespace std;

void cars_list(){ //Fungsi carlist berisi deklarasi map dengan key int dan value string
    map<int,string> garage_2149;
    garage_2149[1] = "Nissan Skyline R34 GT-R       => $100.000";
    garage_2149[2] = "Mazda RX-7 Veilside           => $85.000";
    garage_2149[3] = "Dodge Charger 22'             => $18.500";
    garage_2149[4] = "Honda Civic Type R 00'        => $11.100";
    garage_2149[5] = "Toyota Supra Mk4              => $100.000";


    //Looping untuk menampilkan data dari garage_2149
    for(int i=1; i<=garage_2149.size(); i++){
        cout<<i<<". "<<garage_2149[i]<<endl;
    }

};


int main(){

int choice_2149; //Data primitif int untuk mengisi pilihan menu
do{ //Looping untuk menjalankan program daftar SATRIO GARAGE
cout<<endl;
cout<<"-----------------------------------\n";
cout<<"          SATRIO GARAGE            \n";
cout<<"-----------------------------------\n";
cout<<endl;

cars_list(); //Pemanggilan fungsi cars_list
cout<<"6. Exit";
cout<<endl;
cout<<"Please choose one car to buy: "; cin>>choice_2149;
cout<<endl;
switch(choice_2149){

case 1:
    cout<<"You choose Nissan Skyline R34 GT-R with price $100.000"; //Menampilkan case 1 jika user memilih 1
    break;
case 2:
    cout<<"You choose Mazda RX-7 Veilside with price $85.000"; //Menampilkan case 2 jika user memilih 2
    break;
case 3:
    cout<<"You choose Dodge Charger 22' with price $18.500"; //Menampilkan case 3 jika user memilih 3
    break;
case 4:
    cout<<"You choose Honda Civic Type R 00' with price $11.100"; //Menampilkan case 4 jika user memilih 4
    break;
case 5:
     cout<<"You choose Toyota Supra Mk4 with price $100.000"; //Menampilkan case 5 jika user memilih 5
    break;
case 6:
    cout<<"Thank You for coming to SATRIO GARAGE!";
    break;
default:
 cout<<"You Choose wrong choice, input again!"<<endl; //Menampilkan default jika user memilih bukan di antara case 1 - case 5
 break;
}}while(choice_2149<5); //Program akan berhenti ketika user menginputkan nila <5

return 0;
}
```
#### Output: 
![Screenshot 2024-03-12 160919](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/b106a244-65f6-4935-becf-dab7ef57c94d)


Kode di atas merupakan code yang menggunakan fungsi map. Dimana pada map tersebut terdapat key yang bersifat int dan value bersifat string. Map tersebut memiliki 5 elemen yang telah di isi dengan nama-nama mobil beserta dengan harganya masing-masing. Kemudian, elemen elemen tersebut dideklarasikan dengan perulangan for untuk mencetak/menampilkan semua elemennya.

Perbedaan Array dan Map<br/>
- Array adalah sekumpulan variabel dengan tipe yang sama yang diberi nama dan ukuran tertentu. Array dapat berupa array satu dimensi (1D) atau multidimensi (2D, 3D, dan seterusnya), dan setiap elemen dalam array memiliki indeks yang dimulai dari 0.<br/>
- Sedangkan Map adalah kumpulan elemen yang dapat diakses melalui pasangan key dan value. Setiap elemen map memiliki key dan value. Key dapat berupa string, integer, atau bahkan array, dan value dapat berupa semua jenis data yang sah. Untuk mendeklarasikan map, dapat menggunakan kurung kurawal {} atau kelas Map dalam bahasa pemrograman. Dengan menggunakan key, dapat mengakses elemen map, seperti map["key"] atau map.get("key").


## Kesimpulan
Dari apa yang sudah dipelajari dan dipraktikan, dapat disimpulkan bahwa tipe data adalah komponen yang sangat mendasar untuk kita dalam membuat program. sifat dari tipe data sendiri yaitu sebagai media untuk menyimpan, diatur, dan digunakan ke dalam program yang menjadikan kita dalam memogram menjadi lebih akurat dan efisien.

## Referensi
[1] Muhammad Taufik Dwi Putra, Deden Pradeka, dan Ana Rahma Yuniati. Belajar Dasar Pemrograman dengan C++. Bandung: Widina Media Utama, 2022.<br/>
[2] Meidyan Permata Putri, et al., Algoritma dan Struktur Data. Bandung: Widina Bhakti Persada Bandung, 2022.<br/>
[3] Muhammad Taufik Dwi Putra, Munawir, dan Ana Rahma Yuniarti. Belajar Pemrograman Lanjut dengan C++. Bandung: Widina Media Utama, 2023.<br/>
