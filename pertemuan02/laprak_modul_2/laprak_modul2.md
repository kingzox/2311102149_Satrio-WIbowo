# <h1 align="center">Laporan Praktikum Modul 2 - Array</h1>
<p align="center">Satrio Wibowo - 2311102149</p>

## Dasar Teori

Array adalah variabel yang terdiri dari sekumpulan data dengan tipe data yang sama. Setiap data disimpan dalam alamat memori yang berbeda-beda dan disebut elemen array. Setiap elemen memiliki nilai indek yang sesuai dengan urutannya, dan nilai indek inilah yang memungkinkan kita untuk mengakses data. Dalam Java dan C++, tanda [ ] (bracket) digunakan untuk menandai array. Tipe data array biasanya berbentuk seperti ini: tipe_data nama_array[jumlah_elemen]. Array terbagi menjadi 3, yaitu:

1. Array 1 Dimensi</br>

Sebuah array satu dimensi, juga disebut vektor, adalah sebuah variabel yang dapat menyimpan lebih dari satu nilai yang sama dan terdiri dari elemen-elemen yang disusun dalam satu baris dan memiliki tipe data yang sama. Satu indeks dapat diakses untuk setiap elemen.

2. Array 2 Dimensi</br>

Array dua dimensi adalah kumpulan dari satu atau lebih array satu dimensi yang disusun secara terstruktur. Mereka menyimpan data dalam bentuk tabel yang terdiri dari baris dan kolom dan memiliki dua indeks untuk setiap elemen.

3. Array Multidimensi</br>

Array multidimensi adalah tipe data dalam pemrograman yang memungkinkan Anda menyimpan elemen dalam bentuk grid atau tabel dengan dua atau lebih dimensi, yang berarti Anda dapat menggunakan dua atau lebih indeks untuk mengakses elemen tersebut.
Dalam hal matriks multidimensi, misalnya, setiap elemen adalah array yang mewakili satu baris matriks, dan matriks itu sendiri adalah array yang berisi semua baris matriks.
Data yang memiliki struktur lebih kompleks sering diwakili oleh array multidimensi, seperti data spasial dalam grafika komputer, data tabel dalam basis data, atau matriks dalam perhitungan matematika dan ilmu pengetahuan.


## Guided

### 1. [Program Input Array Tiga Dimensi]

```C++
#include <iostream>
 using namespace std;
 
 // PROGRAM INPUT ARRAY 3 DIMENSI
 int main(){
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
     for (int x = 0; x < 2; x++){
        for (int y = 0; y < 3; y++){
            for (int z = 0; z < 3; z++){
                 cout << "Input Array[" << x << "][" << y << "][" <<
 z << "] = ";
        cin >> arr[x][y][z];
         }
     }
cout << endl;
 }
 // Output Array
 for (int x = 0; x < 2; x++){
    for (int y = 0; y < 3; y++){
        for (int z = 0; z < 3; z++){
            cout << "Data Array[" << x << "][" << y << "][" << z<< "] = " << arr[x][y][z] << endl;
        }
    }
 }
 cout << endl;
 // Tampilan array
 for (int x = 0; x < 2; x++){
    for (int y = 0; y < 3; y++){
        for (int z = 0; z < 3; z++){
             cout << arr[x][y][z] << ends;
         }
    cout << endl;
     }
 cout << endl;
 }
 }
       
```
Program ini berfungsi sebagai input array tiga dimensi, dan pengguna dapat menginputkan nilai elemen untuk masing-masing bari dan kolom. Di sini dideklarasikan array arr[2][3][3]; oleh karena itu, kita akan mengimpor sesuai dengan kondisi program saat ini. Setelah itu, data array akan ditampilkan untuk melihat apakah semua nilai inputnya benar. Terakhir, menampilkan susunan array pada data array yang kita inputkan sebelumnya. Program menggunakan nested tiga kali di sini.

### 2. [Program Mencari Nilai Maksimal pada Array]

```C++
 #include <iostream>
 using namespace std;
 
 int main(){
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array: ";
     cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++){
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
 }
    maks = array[0];
    for (i = 0; i < a; i++){
        if (array[i] > maks)
     {
         maks = array[i];
             lokasi = i;
     }
 }
    cout<<"Nilai maksimum adalah "<<maks<<" berada di Array ke "<<lokasi<<endl;
 }

```
Program di atas berguna untuk mencari nilai maksimal dari elemen array yang telah dimasukkan oleh user. Karena program ini hanya menggunakan array 1 dimensi, maka tidak akan menggunakan nested for. Pertama, user akan diminta untuk menentukan penjang elemen arraynya, misalnya, input 3. Kemudian, nilai array 1 dimensi akan diisi dari indeks 0 hingga indeks 2, dan kemudian elemen akan dicari nilai maksimalnya dengan menggunakan percabangan if di dalam array.


    
## Unguided 

### 1. [Buatlah program untuk menampilkan Output seperti berikut ini dengan data yang diinputkan oleh user!]
![Soal_Unguided-01_Satrio Wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/6b4cf71c-2f08-45ef-8691-108d5161d748)

```C++
//Satrio Wibowo
//2311102149

#include<iostream>
using namespace std;

int main(){

    int arr_149[50]; //Deklarasi isi array
    int size_149=0; //Menghitiung ukuran array

    cout<<"Tekan titik (.) untuk berhenti menginputkan data"<<endl;
    cout<<"Masukkan data array: "<<endl;
    while(cin>>arr_149[size_149]){ //Perulangan untuk memproses inputan user
    size_149++ ;}

    cout << "Data Array: ";
    //Perulangan for untuk mencetak data array
    for (int i = 0; i < size_149; ++i){
        cout << arr_149[i] << " ";
    }
    cout << endl;
    //Mencetak angka genap
    cout<<"Nomor Genap: ";
    //Perulangan for untuk mencetak  nomor genap dari array
    for(int j=0;j<size_149;j++){
        //Percabangan if untuk menentukan kondisi jika angka yang ada pada data array merupakan angka genap
        if(arr_149[j]%2==0){
            cout<<arr_149[j]<<", ";
        }
    }
    cout<<endl;
    //Mencetak angka ganjil
    cout<<"Nomor Ganjil: ";
    //Perulangan for untuk mencetak  nomor genap dari array
    for(int i=0;i<size_149;i++){
         //Percabangan if untuk menentukan kondisi jika angka yang ada pada data array merupakan angka ganjil
        if(arr_149[i]%2 !=0){
            cout<<arr_149[i]<<", ";
        }
    }
    return 0;
}
```
#### Output:
![Output Ungided1_Satrio Wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/12d12933-1860-4fb4-853f-040288dcc9ce)

Program di atas merupakan program yang mememinta user untuk memasukkan data ke dalam sebuah array. Inputan data akan berhenti ketika user menekan tombol titik. Setelah data selesai dimasukkan, program akan mencetak seluruh data, serta angka genap dan ganjil yang ada dalam array. Program juga menggunakan perulangan while untuk memproses inputan user dan perulangan for untuk mencetak data dari array.

### 2. [ Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!]

```C++
//Satrio Wibowo
//2311102149

#include <iostream>
using namespace std;

int main() {
    //Variable untuk menyimpan ukuran elemen array tiga dimensi
    int xsize_149, ysize_149, zsize_149;

    // user menginputkan ukuran elemen array tiga dimensi
    cout << "Masukkan ukuran elemen array tiga dimensi x: "; cin>>xsize_149;
    cout << "Masukkan ukuran elemen array tiga dimensi y: "; cin>>ysize_149;
    cout << "Masukkan ukuran elemen array tiga dimensi z: "; cin>>zsize_149;
   
    //Deklarasi array untuk ukuran yang akan dimasukkan user
    int arr[xsize_149][ysize_149][zsize_149];

    // loop untuk mengisi elemen array dengan data yang diinputkan user
    for (int x = 0; x < xsize_149; x++) {
        for (int y = 0; y < ysize_149; y++) {
            for (int z = 0; z < zsize_149; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Perulangan For untuk menampilkan elemen array berserta indeksnya
    for (int x = 0; x < xsize_149; x++) {
        for (int y = 0; y < ysize_149; y++) {
            for (int z = 0; z < zsize_149; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    //Perulangan For untuk menampilkan elemen array dalam format tiga dimensi
    for (int x = 0; x < xsize_149; x++) {
        for (int y = 0; y < ysize_149; y++) {
            for (int z = 0; z < zsize_149; z++) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

```
#### Output: 
![Output Unguided2_Satrio Wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/34237a9d-bfa9-444b-8f06-0591ecb37e8e)

Program di atas merupakan sebuah program dalam bahasa pemrograman C++ yang meminta user untuk memasukkan ukuran array tiga dimensi (x, y, dan z), mengisi array tersebut dengan nilai yang dimasukkan pengguna, dan kemudian menampilkan nilai dari setiap elemen array beserta indeksnya. Selain itu, program juga menampilkan elemen array dalam format tiga dimensi dengan mengatur baris dan kolom sesuai dengan indeksnya.


  ### 3. [Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!]

```C++

//Satrio Wibowo
//2311102149

#include <iostream> 
using namespace std; 
 
int bilangan_149[10]; 
int main(){ 

int pilihan_149; 
int i; 
cout<<" =============="<<endl;
cout<<"      MENU     "<<endl;
cout<<" =============="<<endl;

cout<<" 1. Input Array"<<endl;
cout<<" 2. Tampil Array"<<endl; 
cout<<" 3. Cari Nilai Minimum"<<endl;
cout<<" 4. Cari Nilai Maksimum"<<endl; 
cout<<" 5. Hitung Rata-rat"<<endl; 

cout<<endl; 
cout<<" Masukkan Pilihan: "; 
cin >>pilihan_149 ; 
cout << endl; 
switch (pilihan_149){ 
//Input Array 
case 1: 
for ( i=0; i < 10; i++ ) { 
    cout << " Masukan Array ke " << i+1 << " : "; 
    cin >> bilangan_149[i]; 
        if ( i == 9 ) { 
            cout << " Berhasil menginput Array ... " <<endl; 
    } 
} 
break; 

//Tampil Array 
case 2: 
for ( i=0; i < 10; i++ ) { 
    cout << "Array ke " << i+1 << " : " << bilangan_149[i] << endl; 
} 
break; 

//Nilai Minimum Array 
case 3: 
int minimal, terkecil; 
minimal = bilangan_149[0]; 
    for( i=0; i < 10; i++) { 
         terkecil = min(minimal,bilangan_149[i]); 
    } 
        cout << " Nilai Minimum Adalah : " << terkecil << endl; 
break; 

//Nilai Maksimum Array 
case 4: 
int maksimal, terbesar; 
maksimal = bilangan_149[0]; 
for( i=0; i < 10; i++) { 
    terbesar = max(maksimal,bilangan_149[i]); 
    } 
        cout << " Nilai Maksimum Adalah : " << terbesar << endl; 
            if ( terbesar == 0) { 
                cout << " ket : Jika nilai 0 silahkan inputkan array! " <<endl; 
    } 
break; 

//Mencari Nilai Rata - rata
case 5: 
float sum; 
sum = 0; 
for ( i=0; i < 10; i++ ) {
    sum = sum + bilangan_149[i]; 
} 
cout << " Total Nilai: " << sum << endl; 
cout << " Rata-Rata adalah: " << sum/10 << endl;
if ( sum == 0) { 
        cout << " ket : Jika nilai 0 silahkan input array ! " << endl; 
} 
        cout << endl; 
break;

//Output jika salah memasukkan pilihan
default:
cout<<"Pilihan yang anda masukkan salah, silahkan inputkan ulang pilihan anda!"<<endl;
break;
        
} 
    system ("pause");
    system ("cls"); 
    main(); 
    return 0; 
}
```
#### Output: 
![Output Unguided3 1_Satrio Wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/6af9123a-f072-4bbf-afde-7d2f574cf04e)
![Output Unguided 3 2_Satrio Wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/5d31b3c3-3b91-4506-b45b-5bfb498bd745)
![Output Unguided 3 3_Satrio Wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/61362529-9d47-47f0-96c7-49499fef383a)
![Output Unguided 3 4_Satrio Wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/c9ba6fa9-181d-48ad-9967-b9ee28c7af12)
![Output Unguided 3 5_Satrio Wibowo](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/1a6fb8d0-03a8-4b6c-8c41-1c50d4c5cd43)

Program tersebut memiliki 5 case yang berbeda, pada case pertama kita diharuskan menginputkan array terlebih dahulu. Untuk menginput dan tercetak 10 array yang kita inputkan maka menggunakan statement for(i=0;i<10;i++). Pada case ke 2 akan ditampilkan array yang telah kita inputkan. Pada case ke 3 kita mencari nilai minimum
dari indeks yang telah diinputkan dari pilihan 1. Pada case 4 program menampilkan nilai maksimum dari yang kita inputkan ada pilihan 1. Pada case 5 program mencari rata rata dari semua bilangan yang telah kita inputkan dengan menggunakan rumus sum/10, yang berarti rata rata = total nilai%banyaknya bilangan.


## Kesimpulan
Array merupakan struktur data yang fundamental dalam pemrograman, memungkinkan pengguna untuk menyimpan dan mengelola kumpulan data dalam satu variabel. Penting untuk dicatat bahwa pendeklarasian mengalokasikan memori secara statis, sehingga ukuran array harus ditentukan sebelum penggunaannya. Namun demikian, array memiliki keunggulan antara lain  memudahkan pengolahan data dengan menyediakan cara efisien untuk mengakses dan memanipulasi elemen-elemen dalam array menggunakan perulangan dan operasi array.  Array juga memungkinkan penggunaan memori yang efisien dan operasi yang cepat, menjadikannya pilihan yang sangat berguna untuk pemrosesan data massal seperti pengolahan gambar, pengolahan sinyal, dan analisis data besar lainnya. Oleh karena itu, array menjadi kunci penting dalam pengembangan program komputer yang efektif dan efisien.

## Referensi
[1] Muhammad Taufik Dwi Putra, Deden Pradeka, dan Ana Rahma Yuniati. Belajar Dasar Pemrograman dengan C++. Bandung: Widina Media Utama, 2022.<br/>
[2] Shofyann Hanief, Wayan Jepriana., Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Yogyakarta: Andi Publisher, 2020.
