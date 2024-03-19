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