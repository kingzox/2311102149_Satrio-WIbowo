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