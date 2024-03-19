# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Satrio Wibowo - 2311102149</p>

## Dasar Teori

Masih Tahap Edit

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
    while(cin>>arr_149[size_149]){
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


Program di atas merupakan sebuah program dalam bahasa pemrograman C++ yang meminta user untuk memasukkan ukuran array tiga dimensi (x, y, dan z), mengisi array tersebut dengan nilai yang dimasukkan pengguna, dan kemudian menampilkan nilai dari setiap elemen array beserta indeksnya. Selain itu, program juga menampilkan elemen array dalam format tiga dimensi dengan mengatur baris dan kolom sesuai dengan indeksnya.


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



Kode di atas merupakan kode yang digunakan untuk mencetakn/menampilkan sebuah struct dan class. Pada kode di atas terdapat struct Data_Mhs_2149 yang menampung nilai string nama_2149, string nim_2149, dan char kelas_2149. Lalu ada class Nilai_2149 yang menampung nilai int kalkulus_2149, int dasar_mm_2149, int matdis_2149, int alrpo_2149, string status_2149, dan int rata2_2149 dengan akses publik.n Pada struct Data_Mhs_2149 diisi dengan nama Satrio Wibowo, nim 2311102149, dan kelas D. Untuk class Nilai_2149 diisin dengan nilai kalkulus 83, nilai matdis 85, nilai alpro 82, dan nilai dasar mm 90, lalu memasukkan rumus rata-rata dengan rumus (nilai kalkulus+nilai matdis+nilai alpro+nilai dasar mm)/4, dan terakhir status dengan nilai TUNTAS. Kemudian untuk menampilkan/menjalankan struct dan kelas ini dideklarasikan sesuai dengan syntax yang telah ditentukan.

A. Fungsi dari struct<br/>
  Dalam pemrograman C++, fungsi struct adalah konstruksi yang mendefinisikan struktur data yang terdiri dari koleksi variabel yang dinyatakan dengan nama, yang masing-masing memiliki tipe data yang berbeda.

B. Fungsi dari class<br/>
  Dalam pemrograman berorientasi objek (OOP), class adalah struktur utama. Class dapat membuat objek yang sama atau berbeda tetapi memiliki atribut yang sama. Setiap objek yang dibuat dari class tersebut akan memiliki 
  atribut yang sama, tetapi nilainya dapat berbeda.

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
