
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