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